/*!
 * \file CChamferMetric.h
 * \brief a CChamferMetric
 * \author Author Matéo Rémi
 * \version Version 0.5
 * \date 04/12/2012
 *
 * This file represent a CChamferMetric which will be use to know a distance between points with a distance
 *
 */


#ifndef _CCHAMFERMETRIC_H_
#define _CCHAMFERMETRIC_H_


#include <iostream>
#include <cmath>
#include "ChamferMask.h"
#include "CChamferMetric.h"
#include "Weighting.h"

template <typename W,typename T>
class CChamferMetric;

template <typename T>
class Weighting;




template <typename W,typename T>
/*!
   * \fn ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric)
   * \brief Allows an easy way to display an instance of the class
*/
std::ostream& operator<<(std::ostream & os, const CChamferMetric<W,T> &refMetric);


/*! \class CChamferMetric
   *
   * \brief Abstract class to make a chamfer metric
   *
*/

template <typename W,typename T>
class CChamferMetric : public CMetric<W,T>
{

   typedef Weighting< T > WeightedPoint;


   public:

   /*!
      *   \fn CChamferMetric();
      *   \brief Constructor of a CChamferMetric without parameters
   */
   CChamferMetric();

   /*!
      * \fn CMetric(const Mask<T>& refMask)
      * \brief Constructor used to make a copy of the Mask used as parameter
   */
   CChamferMetric(const Mask<T>& refMask);

   /*!
      * \fn CMetric(const SymmetricMask< WeightedPoint >& refMask)
      * \brief Constructor used to make a copy of the SymmetricMask used as parameter
   */
   CChamferMetric(const SymmetricMask< WeightedPoint >& refMask);

   /*!
      * \fn CMetric<W,T>& operator=(const CMetric<W,T>& refMetric)
      * \brief Allocation operator for the CMetric class
   */
   CChamferMetric<W,T>& operator=(const CChamferMetric<W,T>& refMetric);


   /*!
      * \fn ostream& operator<<(ostream & os, const CMetric<W,T> &refMetric)
      * \brief Allows an easy way to display an instance of the class
   */
   friend std::ostream& operator<< <>(std::ostream & os, const CChamferMetric<W,T> &refMetric);

   /*!
      * \fn CChamferMetric(const CChamferMetric &refCChamferMetric);
      * \brief Constructor to make a copy of the CChamferMetric used as parameters
   */
   CChamferMetric(const CChamferMetric &refCChamferMetric);

   /*!
      * \fn ~CChamferMetric();
      * \brief To desalloc memory use by the CChamferMetric
   */
   ~CChamferMetric();

};

template <typename W,typename T>
CChamferMetric<W,T>::CChamferMetric():CMetric<W,T>()
{
}

template <typename W,typename T>
CChamferMetric<W,T>::CChamferMetric(const Mask<T>& refMask):CMetric<W,T>(refMask)
{
}

template <typename W,typename T>
CChamferMetric<W,T>::CChamferMetric(const SymmetricMask< WeightedPoint >& refMask):CMetric<W,T>(refMask)
{
}

template <typename W,typename T>
CChamferMetric<W,T>::CChamferMetric(const CChamferMetric<W,T>& refCChamferMetric)
{
   std::cout << *(refCChamferMetric.myMask) << std::endl;
   this.myMask=new Mask< WeightedPoint >(*(refCChamferMetric.myMask));
}

template <typename W,typename T>
CChamferMetric<W,T>& CChamferMetric<W,T>::operator=(const CChamferMetric<W,T>& refCChamferMetric)
{
   delete CChamferMetric<W,T>::myMask;
   CChamferMetric<W,T>::myMask=new Mask< WeightedPoint >(*(refCChamferMetric.myMask));
   return *this;
}

template <typename W,typename T>
std::ostream& operator<<(std::ostream & os, const CChamferMetric<W,T> &refMetric)
{
   os << "[Mask] " << *(refMetric.myMask) << std::endl;
   return os;
}

template <typename W,typename T>
CChamferMetric<W,T>::~CChamferMetric()
{
}



#endif // _CChamferMetric_H_
