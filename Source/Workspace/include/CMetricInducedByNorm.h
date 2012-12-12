/*!
 * \file CMetricInducedByNorm.h
 * \brief a CMetricInducedByNorm is metric which can be configurate with a Norm
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent an abstract CMetricInducedByNorm which will be use to know a distance between points with a distance
 *
*/


#ifndef _CMETRICINDUCEDBYNORM_H_
#define _CMETRICINDUCEDBYNORM_H_


#include <iostream>
#include <cmath>


/*! \std
	* 
	* We use datatype of Standard template library
	* 
*/
using namespace std;


/*! \CMetricInducedByNorm
	*
	* \brief Abstract class to make a metric
	*
*/
template <typename W,typename T>
class CMetricInducedByNorm : public CMetric<W,T>
{

	public:
	/*!
		*	\fn CMetricInducedByNorm();
		*	\brief Constructor of a CMetricInducedByNorm without parameters
	*/
	CMetricInducedByNorm();
	/*!
		* \fn CMetricInducedByNorm(const CMetricInducedByNorm &refCMetricInducedByNorm);
		* \brief Constructor to make a copy of the CMetricInducedByNorm used as parameters
	*/

	CMetricInducedByNorm(const CMetricInducedByNorm &refCMetricInducedByNorm);
	/*!
		* \fn ~CMetricInducedByNorm();
		* \brief To desalloc memory use by the CMetricInducedByNorm
	*/
	virtual ~CMetricInducedByNorm();

};




#endif // _CMetricInducedByNorm_H_
