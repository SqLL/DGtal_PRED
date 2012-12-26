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
class Mask 
{

	protected:

	vector< T > myPointsMask; 
	
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
	this->myPointsMask.clear();//on vide le premier masque
	typename vector< Weighting<T> >::iterator it;
	for(it=refMask.begin(); it!=refMask.end();++it)
	{
		this->myPointsMask.push_back(*it);
	}
}

template <typename T>
Mask<T>::~Mask()
{
	myPointsMask.clear();
}
	
template <typename T>
void Mask<T>::add(const T &newPoint)
{
	myPointsMask.push_back(newPoint);
}






#endif // _Mask_H_
