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
#include "CMetric.h"


using namespace std;

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
	void applyAlgorithm();
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

#endif // _DistanceTransform_H_
