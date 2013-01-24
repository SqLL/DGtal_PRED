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
/*! \class MaskGenerator 
	*
	* \brief abstract class within to generate a mask
	*
*/
class MaskGenerator 
{
	public:
	/*!
		*	\fn 	MaskGenerator();
		*	\brief Constructor of a 	MaskGenerator without parameters
	*/
	MaskGenerator();

	/*!
		* \fn virtual ~MaskGenerator()=0;
		* \brief pure virtual for a virtual class
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
