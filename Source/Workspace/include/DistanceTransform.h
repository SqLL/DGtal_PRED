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
#include "SymetricMask.h"


using namespace std;

/*! \DistanceTransform
	*
	* \brief Abstract class to make a DistanceTransform
	*
*/
template <typename T>
class DistanceTransform 
{

	private:
	SymetricMask<T> myMask;
	
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

	DistanceTransform(const DistanceTransform &refDistanceTransform);
	/*!
		* \fn ~DistanceTransform();
		* \brief To desalloc memory use by the DistanceTransform
	*/
	~DistanceTransform();

};




#endif // _DistanceTransform_H_
