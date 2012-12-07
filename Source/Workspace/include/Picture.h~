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
#include <cmath>
#include "PointND.h"

/*! \std
	* 
	* We use datatype of standart template library
	* 
*/
using namespace std;

/*! \Picture
	*
	* \brief Simple class which represent a list of point with dimension
	*
*/

template <typename T>
class Picture;

template <typename T>
ostream& operator<<(ostream &, const Picture<T> &);


template<typename T>
class Picture 
{
    private:
		int myX,myY; /*!< x,y are the dimension of the picture */
		list< PointND<T> > myPoints; /*!< myPoints is a list of Point which compose the picture or image */																																					

  public:

	/*!
		*	\fn Picture();
		*	\brief Constructor of a picture without parameters
	*/
	Picture();

	/*!
		*	\fn Picture();
		*	\brief Constructor of a picture with dimensions
	*/
	Picture(const int & x, const int & y),

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

	/*!
		* \fn operator<< <>(ostream& os, const Picture<T>& r);
		* \brief With this operator you can display the class easily
	*/
	friend ostream& operator<< <>(ostream &, const Picture<T> &);

	/*!
		* \fn void addPoint(const PointND<T> & point);
		*	\brief allow user to add point in the picture this method could be private for some reasons
	*/
	void addPoint(const PointND<T> & point);

	/*!
		* \fn int getX();
		*	\brief to get the dimensions x of the picture
	*/
	int getX();

	/*!
		* \fn int getY();
		*	\brief to get the dimensions y of the picture
	*/
	int getY();

	/*!
		* \fn void setX(const int & x);
		*	\brief to set the dimensions x of the picture
	*/
	void setX(const int & x);

	/*!
		* \fn void setY(const int & y);
		*	\brief to set the dimensions y of the picture
	*/
	void setY(const int & y);
};


//constructeur
template <typename T>
Picture<T>::Picture()
{
}

template <typename T>
Picture<T>::Picture(const int & x, const int & y)
: myX(x), myY(y)
{
}

template <typename T>
Picture<T>::Picture(const Picture &refpicture)
{
	myPoints.clear();
	typename list<PointND<T> >::const_iterator it,itEnd;
	itEnd=(refpicture.myPoints.end());
  for (it = (refpicture.myPoints.begin()); it != itEnd; ++it)
	{		
		myPoints.push_back(*it);
	}
	myX=refpicture.myX;
	myY=refpicture.myY;
}


template<typename T>
ostream& operator<<(ostream& os, const Picture<T>& r)
{
	typename list<PointND<T> >::const_iterator it,itEnd;
	itEnd=(r.myPoints.end());
	unsigned int cpt=1;
	os << "Dimensions x = " << r.myX << " y = " << r.myY << endl;
  for (it = (r.myPoints.begin()); it != itEnd; ++it, ++cpt)
	{		
		os << *it;
		if(cpt % (r.myX) == 0)
		{
			os << endl;
		} 
	}
	return os;
}

/**
	* The user must known perfectly the dimensions and change them if he want to modify and add some points
*/
template <typename T>
void Picture<T>::addPoint(const PointND<T> & point)
{
	PointND<T> nPoint(point);
	myPoints.push_back(nPoint);
}


template <typename T>
int Picture<T>::getX()
{
	return myX;
}

template <typename T>
int Picture<T>::getY()
{
	return myY;
}

template <typename T>
void Picture<T>::setX(const int & nx)
{
	myX=nx;
}

template <typename T>
void Picture<T>::setY(const int & ny)
{
	myY=ny;
}

template <typename T>
Picture<T>::~Picture()
{
	myPoints.clear();
}


#endif // _PICTURE_H_
