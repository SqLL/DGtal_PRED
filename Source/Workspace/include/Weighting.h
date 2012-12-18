/*!
 * \file Weighting.h
 * \brief a Weighting
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a Weighting. Weighting is a point and a specific Weight
 *
 */


#ifndef _WEIGHTING_H_
#define _WEIGHTING_H_


#include <iostream>
#include <cmath>
#include "DGtal/kernel/PointVector.h"


using namespace std;

/*! \Weighting
	*
	* \brief class using by a metric
	*
*/

template <typename T>
class Weighting ;

template <typename T>
ostream& operator<<(ostream &, const Weighting <T> &);

template <typename T>
bool operator==(const Weighting<T> &, const Weighting<T> &);


template <typename T>
class Weighting 
{

	private:
	T myPoint;
	int myWeight;
	
	public:
	/*!
		*	\fn Weighting();
		*	\brief Constructor of a WeightPoint without parameters
	*/
	Weighting();

	/*!
		*	\fn Weighting(const T &refpoint, const int &myWeight);
		*	\brief Constructor of weighting with all it need
	*/
	Weighting(const T &refpoint, const int &myWeight);

	/*!
		* \fn Weighting(const SymetricMask &refWeighting);
		* \brief Constructor to make a copy of the Weighting used as parameters
	*/
	Weighting(const Weighting &refWeighting);

	/*!
		* \fn ~Weighting();
		* \brief To desalloc memory use by the Weighting
	*/
	~Weighting();

	/*!
		* \fn operator<< <>(ostream& os, const Weighting<T>& r);
		* \brief With this operator you can display the class easily
	*/
	friend ostream& operator<< <>(ostream& os, const Weighting<T>& r);

	/*!
		* \fn operator==<>( const Weighting<T> & a, const Weighting<T> & b );
		* \brief You can compare two point with this method
	*/
	friend bool operator==<>( const Weighting<T> & a, const Weighting<T> & b );
};


//constructeur
template <typename T>
Weighting<T>::Weighting()
{
}

template <typename T>
Weighting<T>::	Weighting(const T &refpoint, const int &refWeight)
{
	myPoint=refpoint;
	myWeight=refWeight;
}

template <typename T>
Weighting<T>::Weighting( const Weighting &refWeighting)
{
	myPoint=refWeighting.myPoint;
	myWeight=refWeighting.myWeight;
}

template<typename T>
Weighting<T>::~Weighting()
{
}

template<typename T>
ostream& operator<<(ostream& os, const Weighting<T>& r)
{
	r.myPoint.selfDisplay(os);
	os << " [Weight] " << r.myWeight;
	return os;
}

template<typename T>
bool operator==(const Weighting<T> &e, const Weighting<T>& r)
{
	return (e.myPoint==r.myPoint && e.myWeight==r.myWeight);
}


#endif