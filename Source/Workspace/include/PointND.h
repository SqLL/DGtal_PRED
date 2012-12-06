/*!
 * \file PointND.h
 * \brief a PointND is a list of positions
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a PointND in ND dimensions
 *
 */


#ifndef _POINTND_H_
#define _POINTND_H_

#include <sstream>
#include <iostream>
#include <cmath>


/*! \DGtal
	* 
	* We use datatype of DGtal 
	* 
*/
using namespace std;


/*! \PointND
	*	
	* \brief Simple class which represent a list of PointND with dimension
	*
*/


template <typename T>
class PointND;

template <typename T>
ostream& operator<<(ostream &, const PointND<T> &);

template <typename T>
bool operator==(const PointND<T> &, const PointND<T> &);

template <typename T>
PointND<T> operator+(const PointND<T> &, const PointND<T> &);

template <typename T>
PointND<T> operator-(const PointND<T> &, const PointND<T> &);

template <typename T>
PointND<T> operator*(const PointND<T> &, const PointND<T> &);

template <typename T>
class PointND 
{
	private:

	list<T> myPositions; /*!< myPositions is a list of Positions which compose the PointND */																																					

	public:

	PointND();
	/*!
		*	\fn PointND(T);
		*	\brief Constructor 1D
	*/
	PointND(T d);
	/*!
		*	\fn PointND(T,T);
		*	\brief Constructor 2D
	*/
	PointND(T d1,T d2);
	/*!
		*	\fn PointND(T,T,T);
		*	\brief Constructor 3D
	*/
	PointND(T d1,T d2,T d3);
	/*!
		* \fn Picture(const Picture &refpicture);
		* \brief Constructor to make a copy of the picture used as parameters
	*/
	PointND(const PointND &refPointND);
	


	friend ostream& operator<< <>(ostream& os, const PointND<T>& r);

	/*!
		* \fn ~Picture();
		* \brief To desalloc memory use by the picture
	*/
	~PointND();

	PointND<T> & operator+=( const PointND<T> & other );

	PointND<T> & operator-=( const PointND<T> & other );
	
	PointND<T> & operator*=( const PointND<T> & other );

	/**
	template <typename W>
	PointND<T> & operator/=( W s );
	**/

	T get(const int & number);

	friend bool operator==<>( const PointND<T> & a, const PointND<T> & b );

	
	friend	PointND<T> operator+<>(const PointND<T> &, const PointND<T> &);
	friend	PointND<T> operator-<>(const PointND<T> &, const PointND<T> &);
	friend	PointND<T> operator*<>(const PointND<T> &, const PointND<T> &);
};


//constructeur
template <typename T>
PointND<T>::PointND()
{
}

//constructeur
template <typename T>
PointND<T>::PointND(T d)
{
	myPositions.push_back(d);
}

template <typename T>
PointND<T>::PointND(T d1,T d2)
{
	myPositions.push_back(d1);
	myPositions.push_back(d2);
}

template <typename T>
PointND<T>::PointND(T d1,T d2,T d3)
{
	myPositions.push_back(d1);
	myPositions.push_back(d2);
	myPositions.push_back(d3);
}

template <typename T>
PointND<T>::PointND(const PointND &refPointND)
{
	myPositions.clear();
	typename list<T>::const_iterator it,itEnd;
	itEnd=(refPointND.myPositions.end());
  for (it = (refPointND.myPositions.begin()); it != itEnd; ++it)
	{		
		myPositions.push_back(*it);
	}
}

template<typename T>
ostream& operator<<(ostream& os, const PointND<T>& r)
{
	typename list<T>::const_iterator it,itEnd;
	itEnd=(r.myPositions.end());
  for (it = (r.myPositions.begin()); it != itEnd; ++it)
	{		
		os << "(" << *it << ")";
	}
	os << endl;	
	return os;
}


template <typename T>
PointND<T>::~PointND()
{
	myPositions.clear();
	cout << "Destructeur" << endl;
}

template <typename T>
PointND<T> & PointND<T>::operator+=( const PointND<T> & other )
{
	typename list<T>::iterator it;
	typename list<T>::const_iterator it2,itEnd;
	it2=other.myPositions.begin();
	itEnd=other.myPositions.end();
	for (it = (myPositions.begin()); it != myPositions.end() || it2 != itEnd ; ++it,++it2 )
	{
		(*it)+=(*it2);
	}
}

template <typename T>
PointND<T> & PointND<T>::operator-=( const PointND<T> & other )
{
	typename list<T>::iterator it;
	typename list<T>::const_iterator it2,itEnd;
	it2=other.myPositions.begin();
	itEnd=other.myPositions.end();
	for (it = (myPositions.begin()); it != myPositions.end() || it2 != itEnd ; ++it,++it2 )
	{
		(*it)-=(*it2);
	}
}

template <typename T>
PointND<T> & PointND<T>::operator*=( const PointND<T> & other )
{
	typename list<T>::iterator it;
	typename list<T>::const_iterator it2,itEnd;
	it2=other.myPositions.begin();
	itEnd=other.myPositions.end();
	for (it = (myPositions.begin()); it != myPositions.end() || it2 != itEnd ; ++it,++it2 )
	{
		(*it)*=(*it2);
	}
}

template <typename T>
bool operator==( const PointND<T> & a, const PointND<T> & b )
{
	bool result=true,end=false;
	if(a.myPositions.size()!= b.myPositions.size())
	{
		result=false;
	}
	else
	{
		typename list<T>::const_iterator it,itEnd;
		typename list<T>::const_iterator it2,itEnd2;
		itEnd2=b.myPositions.end();
		itEnd=a.myPositions.end();
		for (it = (a.myPositions.begin()), it2=(b.myPositions.begin()); (it != a.myPositions.end() || it2 != itEnd2) && end != true ; ++it,++it2 )
		{
			if((*it)!=(*it2))
			{
				result=false;
				end=true;
			}
		}
	}
	return result;
}

template <typename T>
PointND<T> operator+( const PointND<T> & a, const PointND<T> & b )
{
	PointND<T> result;
	if(a.myPositions.size()!= b.myPositions.size())
	{
		result=false;
	}
	else
	{
		typename list<T>::const_iterator it,itEnd;
		typename list<T>::const_iterator it2,itEnd2;
		itEnd2=b.myPositions.end();
		itEnd=a.myPositions.end();
		
		for (it = (a.myPositions.begin()), it2=(b.myPositions.begin()); it != a.myPositions.end(); ++it,++it2 )
		{
			result.myPositions.push_back( (*it)+(*it2) );
		}
	}
	return result;
}

template <typename T>
PointND<T> operator-( const PointND<T> & a, const PointND<T> & b )
{
	PointND<T> result;
	if(a.myPositions.size()!= b.myPositions.size())
	{
		result=false;
	}
	else
	{
		typename list<T>::const_iterator it,itEnd;
		typename list<T>::const_iterator it2,itEnd2;
		itEnd2=b.myPositions.end();
		itEnd=a.myPositions.end();
		
		for (it = (a.myPositions.begin()), it2=(b.myPositions.begin()); it != a.myPositions.end(); ++it,++it2 )
		{
			result.myPositions.push_back( (*it)-(*it2) );
		}
	}
	return result;
}

template <typename T>
PointND<T> operator*( const PointND<T> & a, const PointND<T> & b )
{
	PointND<T> result;
	if(a.myPositions.size()!= b.myPositions.size())
	{
		result=false;
	}
	else
	{
		typename list<T>::const_iterator it,itEnd;
		typename list<T>::const_iterator it2,itEnd2;
		itEnd2=b.myPositions.end();
		itEnd=a.myPositions.end();
		
		for (it = (a.myPositions.begin()), it2=(b.myPositions.begin()); it != a.myPositions.end(); ++it,++it2 )
		{
			result.myPositions.push_back( (*it)*(*it2) );
		}
	}
	return result;
}

template <typename T>
T PointND<T>::get(const int & number)
{
	bool end=false;
	T result;
	int compteur=0;
	if(number >= 0 && number <= myPositions.size())
	{
			typename list<T>::iterator it;
			for (it = (myPositions.begin()); it != myPositions.end() && end!=true; ++it, ++compteur)
			{
				if(compteur==number)
				{
					result=(*it);
					end=true;
				}
			}	
	}	
	return result;
}

#endif // _PointND_H_
