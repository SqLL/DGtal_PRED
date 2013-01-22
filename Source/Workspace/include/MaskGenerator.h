/*!
 * \file MaskGenerator.h
 * \brief an abstract class to generate a mask
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 19/12/2012
 *
 * This file represent an abstract class with the method you have to override in herited classes.
 *
 */


#ifndef _MASKGENERATOR_H_
#define _MASKGENERATOR_H_


#include <iostream>
#include <cmath>
#include "DGtal/kernel/PointVector.h"
#include "Mask.h"




template <typename T>
class MaskGenerator 
{
	public:
	/*!
		*	\fn Weighting();
		*	\brief Constructor of a WeightPoint without parameters
	*/
	MaskGenerator();

	/*!
		* \fn ~Weighting();
		* \brief To desalloc memory use by the Weighting
	*/
	virtual ~MaskGenerator()=0;

};

template <typename T>
MaskGenerator<T>::MaskGenerator()
{
}

template <typename T>
MaskGenerator<T>::~MaskGenerator()
{
}


#endif
