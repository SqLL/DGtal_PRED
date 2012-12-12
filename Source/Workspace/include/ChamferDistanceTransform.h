/*!
 * \file ChamferDistanceTransform.h
 * \brief a ChamferDistanceTransform 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a ChamferDistanceTransform it's a class which contains a CChamferMetric and can apply an algorithm based on Chamfer metric to a space or picture
 *
 */


#ifndef _CHAMFERDISTANCETRANSFORM_H_
#define _CHAMFERDISTANCETRANSFORM_H_


#include <iostream>
#include <cmath>
#include "CChamferMetric.h"


using namespace std;

/*! \ChamferDistanceTransform
	*
	* \brief Abstract class to make a ChamferDistanceTransform
	*
*/


template <typename W,typename T>
class ChamferDistanceTransform 
{

	private:
	CChamferMetric<W,T> myMetric;
	
	public:
	/*!
		*	\fn ChamferDistanceTransform();
		*	\brief Constructor of a ChamferDistanceTransform without parameters
	*/
	ChamferDistanceTransform();
	/*!
		* \fn ChamferDistanceTransform(const ChamferDistanceTransform &refChamferDistanceTransform);
		* \brief Constructor to make a copy of the ChamferDistanceTransform used as parameters
	*/

	ChamferDistanceTransform(const ChamferDistanceTransform &refChamferDistanceTransform);
	/*!
		* \fn ~ChamferDistanceTransform();
		* \brief To desalloc memory use by the ChamferDistanceTransform
	*/
	~ChamferDistanceTransform();


	/*!
		* \fn void applyAlgorithm();
		*	\brief Method who apply an algorithm using the metric member.
	*/
	void applyAlgorithm();
};




#endif // _ChamferDistanceTransform_H_
