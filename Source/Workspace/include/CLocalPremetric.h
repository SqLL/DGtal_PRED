/*!
 * \file CLocalPremetric.h
 * \brief a CLocalPremetric 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 9/12/2012
 *
 * This file represent an abstract CLocalPremetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CLOCALPREMETRIC_H_
#define _CLOCALPREMETRIC_H_


#include <iostream>
#include <cmath>




/*! \CLocalPremetric
	*
	* \brief Abstract class to make a metric
	*
*/


template <typename W,typename T>
class CLocalPremetric 
{
	private:
		T myPoint; /*!< myPoint is a Point which will be use to know the distance */																																					
		W value; /*!< x,y are the dimension of the CLocalPremetric */
	public:
	
	/*!
		*	\fn CLocalPremetric();
		*	\brief Constructor of a CLocalPremetric without parameters
	*/
	CLocalPremetric();
	
	/*!
		* \fn CLocalPremetric(const CLocalPremetric &refCLocalPremetric);
		* \brief Constructor to make a copy of the CLocalPremetric used as parameters
	*/
	CLocalPremetric(const CLocalPremetric &refCLocalPremetric);
	
	/*!
		* \fn ~CLocalPremetric();
		* \brief To desalloc memory use by the CLocalPremetric
	*/
	virtual ~CLocalPremetric() = 0;
	
	/*!
		* \fn W	Distance(const T& p1, const T& p2); 
		* \brief get the vector distance between two points
		* \param Two points this maybe point in 2 or n dimensions
		* \return Vector of distance
	*/
	W	Distance(const T& p1, const T& p2); 
};

template <typename W,typename T>
CLocalPremetric<W,T>::CLocalPremetric()
{
}

template <typename W,typename T>
CLocalPremetric<W,T>::~CLocalPremetric()
{
}




#endif // _CLocalPremetric_H_
