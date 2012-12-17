/*!
 * \file MedialAxis.h
 * \brief a MedialAxis 
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file is abstract represent a MedialAxis it's a class which contains a symetric mask and can apply it to a picture
 *
 */


#ifndef _MEDIALAXIS_H_
#define _MEDIALAXIS_H_


#include <iostream>
#include <cmath>
#include "SymmetricMask.h"


using namespace std;

/*! \MedialAxis
	*
	* \brief class to make a MedialAxis
	*
*/
template <typename T>
class MedialAxis 
{

	private:
	SymmetricMask<T> myMask;
	
	public:
	/*!
		*	\fn MedialAxis();
		*	\brief Constructor of a MedialAxis without parameters
	*/
	MedialAxis();
	/*!
		* \fn MedialAxis(const MedialAxis &refMedialAxis);
		* \brief Constructor to make a copy of the MedialAxis used as parameters
	*/

	MedialAxis(const MedialAxis &refMedialAxis);
	/*!
		* \fn ~MedialAxis();
		* \brief To desalloc memory use by the MedialAxis
	*/
	~MedialAxis();
	
	/*!
		* \fn void applyAlgorithm();
		*	\brief Method who apply an algorithm using the metric member.
	*/
	void applyAlgorithm();

};




#endif // _MedialAxis_H_
