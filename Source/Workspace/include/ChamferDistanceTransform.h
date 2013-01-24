/*!
 * \file ChamferDistanceTransform.h
 * \brief a ChamferDistanceTransform 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a ChamferDistanceTransform it's a class which contains a CChamferMetric and can apply an algorithm based on Chamfer metric to a space or picture
 *
 */


#ifndef _CHAMFERDISTANCETRANSFORM_H_
#define _CHAMFERDISTANCETRANSFORM_H_


#include <iostream>
#include <cmath>
#include "CChamferMetric.h"
#include "DistanceTransform.h"



/*! \class ChamferDistanceTransform
	*
	* \brief Abstract class to make a ChamferDistanceTransform
	*
*/


template <typename W,typename T>
class ChamferDistanceTransform : DistanceTransform<W,T>
{

	protected:
	CChamferMetric<W,T> myChamferMetric;
	
	public:

	/*!
		*	\fn ChamferDistanceTransform();
		*	\brief Constructor of a ChamferDistanceTransform without parameters
	*/
	ChamferDistanceTransform();

	/*!
		* \fn ChamferDistanceTransform(const ChamferDistanceTransform &refChamferDistanceTransform);
		* \brief Constructor to make a copy of the ChamferDistanceTransform used as parameters
	*/
	ChamferDistanceTransform(const ChamferDistanceTransform &refChamferDistanceTransform);

	/*!
		* \fn DistanceTransform(const CMetric<W,T>& myNewMetric);
		* \brief Constructor to make a copy of the metric
	*/
	ChamferDistanceTransform(const CChamferMetric<W,T>& myNewMetric);

	/*!
		* \fn ~ChamferDistanceTransform();
		* \brief To desalloc memory use by the ChamferDistanceTransform
	*/
	~ChamferDistanceTransform();

	/*!
		* \fn void applyAlgorithm();
		* \cite demming2010introduction
		*	\brief Method who apply an algorithm using the metric member.
	*/
	ImageInt applyAlgorithm(ImageChar input, unsigned char threshold, bool outrangeAtZero);
};


template <typename W,typename T>
ChamferDistanceTransform<W,T>::ChamferDistanceTransform()
{
}

template <typename W,typename T>
ChamferDistanceTransform<W,T>::ChamferDistanceTransform(const CChamferMetric<W,T>& myNewMetric)
{
	myChamferMetric=myNewMetric;
}

template <typename W,typename T>
ChamferDistanceTransform<W,T>::~ChamferDistanceTransform()
{
}

template <typename W,typename T>
ostream& operator<< (ostream &os, const ChamferDistanceTransform<W,T> &refDistance)
{
	os << refDistance.myChamferMetric << endl;
	return os;
}

template <typename W,typename T>
ImageInt ChamferDistanceTransform<W,T>::applyAlgorithm(ImageChar input, unsigned char threshold, bool outrangeAtZero)
{

	//ImageInt output();

	Z2i::Domain aDomain=input.domain();
	ImageInt output(aDomain);
	

	
	/** CREATION DU MASK TEMPORAIRE **/

	vector < Weighting<T> > maskTemp;
	for (unsigned int i = 0; i < myChamferMetric.getMask().Size(); i++)
	{
			if (myChamferMetric.getMask().isUpperPart(myChamferMetric.getMask().getWeightingPoint(i)))
					maskTemp.push_back(myChamferMetric.getMask().getWeightingPoint(i));
	}
	
	//forward step
	for (
		//Initialisation
		typename ImageInt::Domain::ConstIterator iteratorOutput = output.domain().begin(),	iteratorInput = input.domain().begin();
		iteratorOutput != output.domain().end();
		++iteratorOutput, ++iteratorInput) {

		if (input(*iteratorInput) > (int) threshold)
			output.setValue((*iteratorOutput), 0);
		else
		{
			unsigned int val = INT_MAX;

			typename vector < Weighting<T> >::iterator it;
			for (it = maskTemp.begin(); it != maskTemp.end(); it++)
			{
				if (output.domain().isInside(*iteratorOutput + (*it).Point()))
				val = min(val, (output(*iteratorOutput + (*it).Point())) + (unsigned int) (*it).Weight());
			}

			output.setValue(*iteratorOutput, val);
		}
	}

	//backward step
	for (
		//Initialisation
		typename ImageInt::Domain::ConstReverseIterator iteratorOutput = output.domain().rbegin();
		iteratorOutput != output.domain().rend();
		++iteratorOutput) {

		unsigned int val = output(*iteratorOutput);
		if (val != 0)
		{
			typename vector < Weighting<T> >::iterator it;
			for (it = maskTemp.begin(); it != maskTemp.end(); it++)
			{
				if (output.domain().isInside(*iteratorOutput - (*it).Point()))
				val = min(val, (output(*iteratorOutput - (*it).Point())) + (unsigned int) (*it).Weight());
			}

			output.setValue(*iteratorOutput, val);
		}
	}

	return output;
}

#endif // _ChamferDistanceTransform_H_
