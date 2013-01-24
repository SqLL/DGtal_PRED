/*!
 * \file CMetric.h
 * \brief a CMetric
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent an abstract CMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CMetric_H_
#define _CMetric_H_


#include <iostream>
#include <cmath>
#include "CLocalPremetric.h"
#include "Mask.h"
#include "SymmetricMask.h"
#include "Weighting.h"








template <typename W,typename T>
class CMetric;

template <typename T>
class Weighting;

template <typename W,typename T>

/*!
   * \fn ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric)
   * \brief Allows an easy way to display an instance of the class
*/
ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric);

/*! \class CMetric
   *
   * \brief Abstract class to make a metric
   *
*/

template <typename W,typename T>
class CMetric : public CLocalPremetric<W,T>
{

   typedef Weighting< T > WeightedPoint;

   protected:
   Mask< Weighting <T> > *myMask;

   public:



   /*!
      *   \fn CMetric();
      *   \brief Constructor of a CMetric without parameters
   */
   CMetric();

   /*!
      * \fn CMetric(const Mask<T>& refMask)
      * \brief Constructor used to make a copy of the Mask used as parameter
   */
   CMetric(const Mask<T>& refMask);

   /*!
      * \fn CMetric(const SymmetricMask< WeightedPoint >& refMask)
      * \brief Constructor used to make a copy of the SymmetricMask used as parameter
   */
   CMetric(const SymmetricMask< WeightedPoint >& refMask);

   /*!
      * \fn CMetric<W,T>& operator=(const CMetric<W,T>& refMetric)
      * \brief Allocation operator for the CMetric class
   */
   CMetric<W,T>& operator=(const CMetric<W,T>& refMetric);

   /*!
      * \fn ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric)
      * \brief Allows an easy way to display an instance of the class
   */
   friend ostream& operator<< <>(ostream & os, const CMetric<W,T> &refMetric);

   /*!
      * \fn CMetric(const CMetric &refCMetric)
      * \brief Constructor used to make a copy of the CMetric used as parameter
   */
   CMetric(const CMetric<W,T> &refCMetric);


   const Mask< Weighting <T> >& getMask();

   /*!
      * \fn ~CMetric();
      * \brief To desalloc memory use by the CMetric
   */
    ~CMetric();

};

template <typename W,typename T>
CMetric<W,T>::CMetric()
{
   myMask=new Mask<WeightedPoint>();
}

template <typename W,typename T>
CMetric<W,T>::CMetric(const Mask<T>& refMask)
{
   myMask=new Mask<WeightedPoint>(refMask);
}

template <typename W,typename T>
CMetric<W,T>::CMetric(const SymmetricMask< WeightedPoint >& refMask)
{
   myMask=new SymmetricMask< WeightedPoint >(refMask);
}

template <typename W,typename T>
CMetric<W,T>::CMetric(const CMetric<W,T>& refCMetric)
{
   cout << *(refCMetric.myMask) << endl;
   myMask=new Mask< WeightedPoint >(*(refCMetric.myMask));
}

template <typename W,typename T>
CMetric<W,T>& CMetric<W,T>::operator=(const CMetric<W,T>& refCMetric)
{
   delete myMask;
   myMask=new Mask< WeightedPoint >(*(refCMetric.myMask));
   return *this;
}

template <typename W,typename T>
const Mask<Weighting<T> >& CMetric<W,T>::getMask()
{
   return *this->myMask;
}

template <typename W,typename T>
ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric)
{
   os << "[Mask] " << *(refMetric.myMask) << endl;
   return os;
}

template <typename W,typename T>
CMetric<W,T>::~CMetric()
{
   delete myMask;
}

#endif // _CMetric_H_
