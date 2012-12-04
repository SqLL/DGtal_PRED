/*!
 * \file Picture.h
 * \brief a picture is a list of point
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a picture which will be use to apply our algorithm distance transform
 *
 */


#ifndef _PICTURE_H_
#define _PICTURE_H_


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
using namespace DGtal;
using namespace DGtal::Z2i;

/*! \Picture
	*
	* \brief Simple class which represent a list of point with dimension
	*
*/

class Picture 
{
    private:
		int myX,myY; /*!< x,y are the dimension of the picture */
		boost::ptr_list<Point> myPoints; /*!< myPoints is a list of Point which compose the picture or image */																																					

  public:
	/*!
		*	\fn Picture();
		*	\brief Constructor of a picture without parameters
	*/
	Picture();
	/*!
		* \fn Picture(const Picture &refpicture);
		* \brief Constructor to make a copy of the picture used as parameters
	*/
	Picture(const Picture &refpicture);
	/*!
		* \fn ~Picture();
		* \brief To desalloc memory use by the picture
	*/
	~Picture();
};




#endif // _PICTURE_H_
