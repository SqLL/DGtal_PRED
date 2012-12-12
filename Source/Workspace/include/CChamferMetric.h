/*!
 * \file CChamferMetric.h
 * \brief a CChamferMetric 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a CChamferMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CCHAMFERMETRIC_H_
#define _CCHAMFERMETRIC_H_


#include <iostream>
#include <cmath>
#include "ChamferMask.h"

//TODO il faudra surement surcharger la methode distance

using namespace std;

/*! \CChamferMetric
	*
	* \brief Abstract class to make a metric
	*
*/

template <typename W,typename T>
class CChamferMetric : public CMetricInducedByNorm<W,T>
{
	private:
	ChamferMask<T> myMask;
	
	public:
	/*!
		*	\fn CChamferMetric();
		*	\brief Constructor of a CChamferMetric without parameters
	*/
	CChamferMetric();
	/*!
		* \fn CChamferMetric(const CChamferMetric &refCChamferMetric);
		* \brief Constructor to make a copy of the CChamferMetric used as parameters
	*/

	CChamferMetric(const CChamferMetric &refCChamferMetric);
	/*!
		* \fn ~CChamferMetric();
		* \brief To desalloc memory use by the CChamferMetric
	*/
	~CChamferMetric();

};




#endif // _CChamferMetric_H_
