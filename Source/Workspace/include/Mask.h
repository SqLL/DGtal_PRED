/*!
 * \file Mask.h
 * \brief a Mask 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file is abstract represent a simple mask
 *
 */


#ifndef _MASK_H_
#define _MASK_H_


#include <iostream>
#include <cmath>



using namespace std;

/*! \Mask
	*
	* \brief Abstract class to make a mask
	*
*/

template <typename T>
class Mask 
{

	private:
	list< PointND<T> > myPointsMask; 
	
	public:
	/*!
		*	\fn Mask();
		*	\brief Constructor of a Mask without parameters
	*/
	Mask();
	/*!
		* \fn Mask(const Mask &refMask);
		* \brief Constructor to make a copy of the Mask used as parameters
	*/

	Mask(const Mask &refMask);
	/*!
		* \fn ~Mask();
		* \brief To desalloc memory use by the Mask
	*/
	~Mask();

};




#endif // _Mask_H_
