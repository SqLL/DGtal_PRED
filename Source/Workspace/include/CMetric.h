/*!
 * \file CMetric.h
 * \brief a CMetric 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent an abstract CMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CMetric_H_
#define _CMetric_H_


#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/io/boards/Board2D.h"
#include "DGtal/helpers/StdDefs.h"
#include <cmath>


/*! \DGtal
	* 
	* We use datatype of DGtal 
	* 
*/
using namespace std;
using namespace DGtal;
using namespace DGtal::Z2i;

/*! \CMetric
	*
	* \brief Abstract class to make a metric
	*
*/

class CMetric : CLocalPremetric
{

	public:
	/*!
		*	\fn CMetric();
		*	\brief Constructor of a CMetric without parameters
	*/
	CMetric();
	/*!
		* \fn CMetric(const CMetric &refCMetric);
		* \brief Constructor to make a copy of the CMetric used as parameters
	*/

	CMetric(const CMetric &refCMetric);
	/*!
		* \fn ~CMetric();
		* \brief To desalloc memory use by the CMetric
	*/
	virtual ~CMetric();

};




#endif // _CMetric_H_
