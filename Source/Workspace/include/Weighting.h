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



template <typename T>
class Weighting;

template <typename T>
/*!
   * \fn operator<<(ostream& os, const Weighting<T>& r);
   * \brief Allows an easy way to display an instance of the class
*/
std::ostream& operator<<(std::ostream& os, const Weighting<T>& r);

template <typename T>
/*!
   * \fn bool operator==( const Weighting<T> & a, const Weighting<T> & b );
   * \brief You can compare two point with this method
*/
bool operator==( const Weighting<T> & a, const Weighting<T> & b );

/*! \class Weighting
   *
   * \brief Class of Weighting which got a PointVector of DGtal
   *
*/
template <typename T>
class Weighting
{

   private:
   T* myPoint;
   int* myWeight;

   public:


   /*!
      *   \fn Weighting();
      *   \brief Constructor of a WeightPoint without parameters
   */
   Weighting();

   /*!
      *   \fn Weighting(const T &refpoint, const int &myWeight);
      *   \brief Constructor of weighting with all it need
   */
   Weighting(const T &refpoint, const int &myWeight);

   /*!
      * \fn Weighting(const Weighting<T> &refWeighting);
      * \brief Constructor to make a copy of the Weighting used as parameters
   */
   Weighting(const Weighting<T> &refWeighting);

   /*!
      * \fn ~Weighting();
      * \brief To desalloc memory use by the Weighting
   */
   ~Weighting();

   /*!
      * \fn Weighting<T>& operator=(const Weighting<T>& refWeighting);
      * \brief Allow you to use the operator affectation
   */
   Weighting<T>& operator=(const Weighting<T>& refWeighting);

  /*!
     * \fn operator<<(ostream& os, const Weighting<T>& r);
     * \brief Allows an easy way to display an instance of the class
  */
   friend std::ostream& operator<< <>(std::ostream& os, const Weighting<T>& r);


  /*!
     * \fn bool operator==( const Weighting<T> & a, const Weighting<T> & b );
     * \brief You can compare two point with this method
  */
   friend bool operator==<>( const Weighting<T> & a, const Weighting<T> & b );

   /*!
      * \fn reverse();
      * \brief return the reverse point of the current point.
   */
   Weighting<T> reverse();

   /*!
      * \fn int Weight();
      * \brief return the Weight of the current weighting Point
   */
   int Weight();

   /*!
      * \fn    T& Point();
      * \brief return a reference to the Point of dgtal
   */
   T& Point();
};


//constructeur
template <typename T>
Weighting<T>::Weighting()
{
   myPoint=new T();
   myWeight=new int();
}

template <typename T>
Weighting<T>::Weighting(const T &refpoint, const int &refWeight)
{
   myPoint=new T(refpoint);
   myWeight=new int(refWeight);
}

template <typename T>
Weighting<T>::Weighting( const Weighting<T> &refWeighting)
{
   myPoint=new T(*(refWeighting.myPoint));
   myWeight=new int(*(refWeighting.myWeight));
}

template<typename T>
Weighting<T>::~Weighting()
{
   delete myPoint;
   delete myWeight;
}

template <typename T>
Weighting<T>& Weighting<T>::operator=(const Weighting<T>& refWeighting)
{
   delete myPoint;
   delete myWeight;
   myPoint=new T(*(refWeighting.myPoint));
   myWeight=new int(*(refWeighting.myWeight));
   return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Weighting<T>& r)
{
   r.myPoint->selfDisplay(os);
   os << " [Weight] " << *(r.myWeight);
   return os;
}

template<typename T>
bool operator==(const Weighting<T> &e, const Weighting<T>& r)
{
   return (*(e.myPoint)==*(r.myPoint) && *(e.myWeight)==*(r.myWeight));
}

template<typename T>
Weighting<T> Weighting<T>::reverse()
{
   // Voir si dans DGtal il n'y a pas moyen d'obtenir un reverse de pointVector sinon on applique comme cela
   Weighting<T> result(*this);
   //typename vector< PointVector <int N, T>>::const_iterator it;// = this->myPoint.begin();

   typename T::Iterator it=this->myPoint->begin();
   for(it=result.myPoint->begin(); it!=result.myPoint->end();++it)
   {
      *it = (*it) * (-1);
   }

   return result;
}

template<typename T>
int Weighting<T>::Weight()
{
   return *myWeight;
}

template<typename T>
T& Weighting<T>::Point()
{
   return *myPoint;
}


#endif
