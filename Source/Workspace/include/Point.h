/*!
 * \file Point.h
 * \brief a point is a list of positions
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a point in ND dimensions
 *
 */


#ifndef _POINT_H_
#define _POINT_H_


#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/io/boards/Board2D.h"
#include "DGtal/helpers/StdDefs.h"
#include <boost/ptr_container/ptr_list.hpp>
#include <cmath>


/*! \DGtal
	* 
	* We use datatype of DGtal 
	* 
*/
using namespace std;


/*! \Point
	*	
	* \brief Simple class which represent a list of point with dimension
	*
*/

class Point 
{
	private:

		boost::ptr_list<int> myPositions; /*!< myPositions is a list of Positions which compose the point */																																					

	public:
	/*!
		*	\fn Point();
		*	\brief Constructor of a picture without parameters
	*/
	Point();
	/*!
		* \fn Picture(const Picture &refpicture);
		* \brief Constructor to make a copy of the picture used as parameters
	*/
	Point(const Point &refpoint);
	/*!
		* \fn ~Picture();
		* \brief To desalloc memory use by the picture
	*/
	~Point();
};




#endif // _POINT_H_
