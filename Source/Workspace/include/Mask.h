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
#include "Weighting.h"
#include <vector>



using namespace std;

/*! \Mask
	*
	* \brief Abstract class to make a mask
	*
*/

template <typename T>
class Mask;

template <typename T>
ostream& operator<<(ostream &, const Mask <T> &);

template <typename T>
class Mask 
{

	protected:

	vector< T* > myPointsMask; 
	
	public:
	

	
	typedef typename vector< T >::const_iterator constIterator;
	typedef typename vector< T >::iterator Iterator;
	typedef typename vector< T* >::const_iterator constIterator_ptr;
	typedef typename vector< T* >::iterator Iterator_ptr;
	
	/*!
		*	\fn Mask()
		*	\brief Constructor of a Mask without parameters
	*/
	Mask();

	/*!
		* \fn Mask(const Mask &refMask)
		* \brief Constructor to make a copy of the Mask used as parameters
	*/
	Mask(const Mask &refMask);

	/*!
		* \fn ~Mask()
		* \brief To desalloc memory use by the Mask
	*/
	~Mask();
	
	/*!
		* \fn Mask<T>& operator=(const Mask<T>& refmask)
		* \brief Allocation operator for the Mask class
	*/
	Mask<T>& operator=(const Mask<T>& refmask);
	
	/*!
		* \fn friend ostream& operator<< <>(ostream& os, const Mask<T>& r)
		* \brief Allows an easy way to display an instance of the class
	*/
	friend ostream& operator<< <>(ostream& os, const Mask<T>& r);

	/*!
		* \fn void add(const Weighting<T> &newPoint);
		*	\brief To add a Weighting point in the mask
	*/
	void add(const T &newPoint);
};

template <typename T>
Mask<T>::Mask()
{
}



template <typename T>
Mask<T>::Mask(const Mask<T> &refMask)
{
	for(unsigned int iterator = 0; iterator < myPointsMask.size(); iterator++)
  { 
     delete(myPointsMask[iterator]);
	}
	this->myPointsMask.clear();//we clear the first mask
	
	typename vector<T*>::const_iterator const_It=refMask.myPointsMask.begin();
	for(;const_It !=refMask.myPointsMask.end();++const_It)
	{
		this->myPointsMask.push_back(new T(**const_It));
	}
	/**
	for(refMask.constIterator=refMask.myPointsMask.begin(); refMask.constIterator!=refMask.myPointsMask.end();++refMask.constIterator)
	{
		this->myPointsMask.push_back(new T(*refMask.constIterator));
	}
	**/
}

template <typename T>
Mask<T>::~Mask()
{

	for(unsigned int iterator = 0; iterator < myPointsMask.size(); iterator++)
  { 
     delete(myPointsMask[iterator]);
	}
	myPointsMask.clear();
}
	
template <typename T>
void Mask<T>::add(const T &newPoint)
{
	myPointsMask.push_back(new T(newPoint));
}


template<typename T>
ostream& operator<<(ostream& os, const Mask<T>& r)
{
	typename vector<T*>::const_iterator const_It=r.myPointsMask.begin();
	for(;const_It !=r.myPointsMask.end();++const_It)
		os << (**const_It);
	return os;
}

template <typename T>
Mask<T>& Mask<T>::operator=(const Mask<T>& refMask)
{
	this->myPointsMask.clear();//we clear the first mask
	typename vector< Weighting<T> >::iterator it;
	for(it=refMask.myPointsMask.begin(); it!=refMask.myPointsMask.end();++it)
	{
		this->myPointsMask.push_back(*it);
	}
	return *this;
}


#endif // _Mask_H_
