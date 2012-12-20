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


	void add(const Weighting<T> &newPoint);

};

template <typename T>
SymmetricMask<T>::SymmetricMask()
{
}

template <typename T>
SymmetricMask<T>::SymmetricMask(const SymmetricMask<T> &refMask)
{
	Mask<T>::myPointsMask.clear();//on vide le premier masque
	typename vector< Weighting<T> >::const_iterator it;
	for(it=refMask.myPointsMask.begin(); it!=refMask.myPointsMask.end();++it)
	{
		Mask<T>::myPointsMask.push_back(*it);
	}
}

template <typename T>
SymmetricMask<T>::~SymmetricMask()
{
	Mask<T>::myPointsMask.clear();
}

template <typename T>
void SymmetricMask<T>::add(const Weighting<T> &newPoint)
{
	Mask<T>::myPointsMask.push_back(newPoint);
}

#endif // _SymetricMask_H_
