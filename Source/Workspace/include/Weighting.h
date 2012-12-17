/*!
 * \file Weighting.h
 * \brief a Weighting
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a Weighting. Weighting is a point and a specific Weight
 *
 */


#ifndef _WEIGHTING_H_
#define _WEIGHTING_H_


#include <iostream>
#include <cmath>
#include "DGtal/kernel/PointVector.h"


using namespace std;

/*! \Weighting
	*
	* \brief class using by a metric
	*
*/

template <typename T>
class Weighting 
{

	private:
	T myPoint;
	int myWeight;
	
	public:
	/*!
		*	\fn Weighting();
		*	\brief Constructor of a SymetricMask without parameters
	*/
	Weighting();
	/*!
		* \fn Weighting(const SymetricMask &refWeighting);
		* \brief Constructor to make a copy of the Weighting used as parameters
	*/

	Weighting(const Weighting &refWeighting);
	/*!
		* \fn ~Weighting();
		* \brief To desalloc memory use by the Weighting
	*/
	~Weighting();

};




#endif // _SymetricMask_H_
