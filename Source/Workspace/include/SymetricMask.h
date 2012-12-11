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


#ifndef _SYMETRICMASK_H_
#define _SYMETRICMASK_H_


#include <iostream>
#include <cmath>
#include "Mask.h"


using namespace std;

/*! \SymetricMask
	*
	* \brief Abstract class to make a metric
	*
*/

template <typename T>
class SymetricMask : public Mask<T>
{
	public:
	/*!
		*	\fn SymetricMask();
		*	\brief Constructor of a SymetricMask without parameters
	*/
	SymetricMask();
	/*!
		* \fn SymetricMask(const SymetricMask &refSymetricMask);
		* \brief Constructor to make a copy of the SymetricMask used as parameters
	*/

	SymetricMask(const SymetricMask &refSymetricMask);
	/*!
		* \fn ~SymetricMask();
		* \brief To desalloc memory use by the SymetricMask
	*/
	~SymetricMask();

};




#endif // _SymetricMask_H_