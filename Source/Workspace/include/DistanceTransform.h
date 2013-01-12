/*!
 * \file DistanceTransform.h
 * \brief a DistanceTransform 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file is abstract represent a DistanceTransform it's a class which contains a symetric mask and can apply it to a picture
 *
 */


#ifndef _DistanceTransform_H_
#define _DistanceTransform_H_


#include <iostream>
#include <cmath>
#include <climits>
#include "CMetric.h"
#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/images/ImageContainerBySTLVector.h"


using namespace std;

typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned char> ImageChar; //more efficient for color/gray values

typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned int> ImageInt; // used for distance transform maps

/*! \DistanceTransform
	*
	* \brief Abstract class to make a DistanceTransform
	*
*/


template <typename W,typename T>
class DistanceTransform;

template <typename W,typename T>
ostream& operator<<(ostream &, const DistanceTransform<W,T> &);

template <typename W,typename T>
class DistanceTransform 
{

	private:
	CMetric<W,T> myMetric;
	

	
	public:

	/*!
		*	\fn DistanceTransform();
		*	\brief Constructor of a DistanceTransform without parameters
	*/
	DistanceTransform();
	/*!
		* \fn DistanceTransform(const DistanceTransform &refDistanceTransform);
		* \brief Constructor to make a copy of the DistanceTransform used as parameters
	*/

	DistanceTransform(const CMetric<W,T>& myNewMetric);

	DistanceTransform(const DistanceTransform &refDistanceTransform);
	
	
	/*!
		* \fn operator<< <>(ostream& os, const CMetric<W,T> & refMetric);
		* \brief Allows an easy way to display an instance of the class
	*/
	friend ostream& operator<< <>(ostream &, const DistanceTransform<W,T> &);
	
	/*!
		* \fn ~DistanceTransform();
		* \brief To desalloc memory use by the DistanceTransform
	*/
	~DistanceTransform();

	/*!
		* \fn void applyAlgorithm();
		*	\brief Method who apply an algorithm using the metric member.
	*/
	void applyAlgorithm(ImageChar input, unsigned char threshold, bool outrangeAtZero);
};

template <typename W,typename T>
DistanceTransform<W,T>::DistanceTransform()
{
}

template <typename W,typename T>
DistanceTransform<W,T>::DistanceTransform(const CMetric<W,T>& myNewMetric)
{
	myMetric=myNewMetric;
}

template <typename W,typename T>
DistanceTransform<W,T>::~DistanceTransform()
{
}

template <typename W,typename T>
ostream& operator<< (ostream &os, const DistanceTransform<W,T> &refDistance)
{
	os << refDistance.myMetric << endl;
	return os;
}

template <typename W,typename T>
void DistanceTransform<W,T>::applyAlgorithm(ImageChar input, unsigned char threshold, bool outrangeAtZero)
{
	/**
		cout << myMetric.myMask->Size() << endl;
		cout << myMetric.myMask->getWeightingPoint(1) << endl;	
		cout << myMetric.myMask->getWeightingPoint(1).Point() << endl;		
	**/
	
	//ImageInt output();

	Z2i::Domain monsuperdomaine=input.domain();
	ImageInt output(monsuperdomaine);
	
	//output.Size=input.Size;
	//output.Dimension=input.Dimension;
	//output.translateDomain(input.extent());
	//output.domain=input.domain();
	
	//Initialisation
	typename ImageInt::Domain::ConstIterator iteratorOuput = output.domain().begin();	
	typename ImageInt::Domain::ConstIterator iteratorInput = input.domain().begin();	
	for(;iteratorOuput != output.domain().end() && iteratorInput != input.domain().end() ;++iteratorOuput, ++iteratorInput)
	{

		if(input(*iteratorInput) > (int) threshold)
		{
			output.setValue( (*iteratorOuput) , 0);
		}
		else
		{
			output.setValue(*iteratorOuput, INT_MAX);
		}
		
		cout << (*iteratorOuput) << " : " << (int)output(*iteratorOuput) << endl;			
	}
	

	
}

#endif // _DistanceTransform_H_
