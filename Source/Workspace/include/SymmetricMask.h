/*!
 * \file SymetricMask.h
 * \brief a SymetricMask 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent all of symetric mask herit from this class
 *
 */


#ifndef _SYMMETRICMASK_H_
#define _SYMMETRICMASK_H_


#include <iostream>
#include <cmath>
#include "Mask.h"


using namespace std;

/*! \SymmetricMask
	*
	* \brief class using by a metric
	*
*/

template <typename T>
class SymmetricMask : public Mask<T>
{
	public:
	/*!
		*	\fn SymmetricMask();
		*	\brief Constructor of a SymetricMask without parameters
	*/
	SymmetricMask();
	/*!
		* \fn SymmetricMask(const SymetricMask &refSymmetricMask);
		* \brief Constructor to make a copy of the SymmetricMask used as parameters
	*/

	SymmetricMask(const SymmetricMask &refSymmetricMask);
	/*!
		* \fn ~SymmetricMask();
		* \brief To desalloc memory use by the SymmetricMask
	*/
	~SymmetricMask();

};




#endif // _SymetricMask_H_
