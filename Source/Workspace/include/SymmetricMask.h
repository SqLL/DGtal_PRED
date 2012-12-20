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

template <typename T>
SymmetricMask<T>::SymmetricMask()
{
}

template <typename T>
SymmetricMask<T>::SymmetricMask(const SymmetricMask<T> &refMask)
{
	myPointsMask.clear();//on vide le premier masque
	typename vector< Weighting<T> >::iterator it;
	for(it=refMask.begin(); it!=refMask.end();++it)
	{
		myPointsMask.push_back(*it);
	}
}

template <typename T>
SymmetricMask<T>::~SymmetricMask()
{
	//Impossible a cause error: request for member ‘myPointsMask’ in ‘this’, which is of non-class type ‘SymmetricMask<Weighting<DGtal::PointVector<2u, int> > >* const’
	//this.myPointsMask.clear();
}

#endif // _SymetricMask_H_
