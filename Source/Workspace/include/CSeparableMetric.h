/*!
 * \file CSeparableMetric.h
 * \brief a CSeparableMetric 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a CSeparableMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CSEPARABLEMETRIC_H_
#define _CSEPARABLEMETRIC_H_


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

/*! \CSeparableMetric
	*
	* \brief Abstract class to make a metric
	*
*/

class CSeparableMetric : public CMetric
{

	public:
	/*!
		*	\fn CSeparableMetric();
		*	\brief Constructor of a CSeparableMetric without parameters
	*/
	CSeparableMetric();
	/*!
		* \fn CSeparableMetric(const CSeparableMetric &refCSeparableMetric);
		* \brief Constructor to make a copy of the CSeparableMetric used as parameters
	*/

	CSeparableMetric(const CSeparableMetric &refCSeparableMetric);
	/*!
		* \fn ~CSeparableMetric();
		* \brief To desalloc memory use by the CSeparableMetric
	*/
	~CSeparableMetric();

};




#endif // _CSeparableMetric_H_