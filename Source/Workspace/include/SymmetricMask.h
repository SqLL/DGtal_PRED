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
#include "Weighting.h"



using namespace std;

/*! \SymmetricMask
	*
	* \brief class using by a metric
	*
*/
template <typename T>
class SymmetricMask;

template <typename T>
ostream& operator<<(ostream &, const SymmetricMask <T> &);



template <typename T>
class SymmetricMask : public Mask<T>
{


	
	public:
	
	
	typedef typename vector< T >::const_iterator constIterator;
	typedef typename vector< T >::iterator Iterator;
	typedef typename vector< T* >::const_iterator constIterator_ptr;
	typedef typename vector< T* >::iterator Iterator_ptr;
	
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


	SymmetricMask<T>& operator=(const SymmetricMask<T>& refmask);	
	
	friend ostream& operator<< <>(ostream& os, const SymmetricMask<T>& r);

	void add(const T &newPoint);

};

template <typename T>
SymmetricMask<T>::SymmetricMask()
{
}

template <typename T>
SymmetricMask<T>::SymmetricMask(const SymmetricMask<T>& refMask)
{
	Mask<T>::myPointsMask.clear();//on vide le premier masque
	refMask.constIterator = refMask.myPointsMask.begin();
	for(; refMask.constIterator !=refMask.myPointsMask.end();++refMask.constIterator)
	{
		Mask<T>::myPointsMask.push_back(*refMask.constIterator );
	}
}

template <typename T>
SymmetricMask<T>& SymmetricMask<T>::operator=(const SymmetricMask<T>& refMask)
{
	Mask<T>::myPointsMask.clear();//on vide le premier masque
	for(refMask.constIterator = refMask.myPointsMask.begin(); refMask.constIterator !=refMask.myPointsMask.end();++refMask.constIterator)
	{
		Mask<T>::myPointsMask.push_back(*refMask.constIterator );
	}
	return *this;
}

template <typename T>
SymmetricMask<T>::~SymmetricMask()
{
	Mask<T>::myPointsMask.clear();
}

template <typename T>
void SymmetricMask<T>::add(const T &newPoint)
{
	this->myPointsMask.push_back(newPoint);
}


template<typename T>
ostream& operator<<(ostream& os, const SymmetricMask<T>& r)
{
	typename vector<T>::const_iterator const_It=r.myPointsMask.begin();
	for(;const_It !=r.myPointsMask.end();++const_It)
		os << (*const_It);
	return os;
}

#endif // _SymetricMask_H_
