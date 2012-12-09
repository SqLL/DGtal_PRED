/*!
 * \file CChampferMetric.h
 * \brief a CChampferMetric 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a CChampferMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CCHAMPFERMETRIC_H_
#define _CCHAMPFERMETRIC_H_


#include <iostream>
#include <cmath>

//TODO il faudra surement surcharger la methode distance

using namespace std;

/*! \CChampferMetric
	*
	* \brief Abstract class to make a metric
	*
*/

template <typename W,typename T>
class CChampferMetric : public CMetricInducedByNorm<W,T>
{

	public:
	/*!
		*	\fn CChampferMetric();
		*	\brief Constructor of a CChampferMetric without parameters
	*/
	CChampferMetric();
	/*!
		* \fn CChampferMetric(const CChampferMetric &refCChampferMetric);
		* \brief Constructor to make a copy of the CChampferMetric used as parameters
	*/

	CChampferMetric(const CChampferMetric &refCChampferMetric);
	/*!
		* \fn ~CChampferMetric();
		* \brief To desalloc memory use by the CChampferMetric
	*/
	~CChampferMetric();

};




#endif // _CChampferMetric_H_
