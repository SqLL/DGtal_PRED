/*!
 * \file CChampferMask.h
 * \brief a CChampferMask 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a CChampferMask which will be use as mask for a picture
 *
 */


#ifndef _CCHAMPFERMASK_H_
#define _CCHAMPFERMASK_H_


#include <iostream>
#include <cmath>
#include "SymetricMask.h"
#include "CChampferMetric.h"


using namespace std;

/*! \CChampferMask
	*
	* \brief Abstract class to make a metric
	*
*/

template <typename T,typename W,typename Y>
class CChampferMask : public SymetricMask<T>
{

	private:
	CChampferMetric<W,Y> myMetric;

	public:
	/*!
		*	\fn CChampferMask();
		*	\brief Constructor of a CChampferMask without parameters
	*/
	CChampferMask();
	/*!
		* \fn CChampferMask(const CChampferMask &refCChampferMask);
		* \brief Constructor to make a copy of the CChampferMask used as parameters
	*/

	CChampferMask(const CChampferMask &refCChampferMask);
	/*!
		* \fn ~CChampferMask();
		* \brief To desalloc memory use by the CChampferMask
	*/
	~CChampferMask();

};




#endif // _CChampferMask_H_
