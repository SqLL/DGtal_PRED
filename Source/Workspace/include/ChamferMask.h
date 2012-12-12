/*!
 * \file ChamferMask.h
 * \brief a ChamferMask 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a ChamferMask which will be use as mask by a ChamferMetric for a picture
 *
 */


#ifndef _CCHAMFERMASK_H_
#define _CCHAMFERMASK_H_


#include <iostream>
#include <cmath>
#include "SymetricMask.h"


using namespace std;

/*! \ChamferMask
	*
	* \brief this class is using by a metric
	*
*/

template <typename T>
class ChamferMask : public SymetricMask<T>
{


	public:
	/*!
		*	\fn ChamferMask();
		*	\brief Constructor of a ChamferMask without parameters
	*/
	ChamferMask();
	/*!
		* \fn ChamferMask(const ChamferMask &refChamferMask);
		* \brief Constructor to make a copy of the ChamferMask used as parameters
	*/

	ChamferMask(const ChamferMask &refChamferMask);
	/*!
		* \fn ~ChamferMask();
		* \brief To desalloc memory use by the ChamferMask
	*/
	~ChamferMask();

};




#endif // _ChamferMask_H_
