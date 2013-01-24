/*!
 * \file DistanceTransform.h
 * \brief a DistanceTransform
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 *
 *
 * This file represent a DistanceTransform it's a class which contains a symetric mask and can apply it to a picture
 *
 */


#ifndef _DistanceTransform_H_
#define _DistanceTransform_H_


#include <iostream>
#include <cmath>
#include <climits>
#include "Weighting.h"
#include "CMetric.h"
#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/images/ImageContainerBySTLVector.h"



typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned char> ImageChar; //more efficient for color/gray values
typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned int> ImageInt; // used for distance transform maps

template <typename W,typename T>
class DistanceTransform;

template <typename W,typename T>

/*!
   * \fn ostream& operator<<(ostream &os, const DistanceTransform<W,T> &refDistance);
   * \brief Allows an easy way to display an instance of the class
*/
ostream& operator<<(ostream &os, const DistanceTransform<W,T> &refDistance);


/*! \class DistanceTransform
   *
   * \brief Abstract class to make a DistanceTransform
   *
*/

template <typename W,typename T>
class DistanceTransform
{

   private:
   CMetric<W,T> myMetric;



   public:

   /*!
      *   \fn DistanceTransform();
      *   \brief Constructor of a DistanceTransform without parameters
   */
   DistanceTransform();

   /*!
      * \fn DistanceTransform(const DistanceTransform &refDistanceTransform);
      * \brief Constructor to make a copy of the DistanceTransform used as parameters
   */
   DistanceTransform(const DistanceTransform &refDistanceTransform);

   /*!
      * \fn DistanceTransform(const CMetric<W,T>& myNewMetric);
      * \brief Constructor to make a copy of the metric
   */
   DistanceTransform(const CMetric<W,T>& myNewMetric);

   /*!
     * \fn ostream& operator<<(ostream &os, const DistanceTransform<W,T> &refDistance);
     * \brief Allows an easy way to display an instance of the class
  */
   friend ostream& operator<< <>(ostream &os, const DistanceTransform<W,T> &refDistance);

   /*!
      * \fn ~DistanceTransform();
      * \brief To desalloc memory use by the DistanceTransform
   */
   ~DistanceTransform();

   /*!
      * \fn void applyAlgorithm();
       * \cite distancefunctions
      * \cite sequencialprocessing
      *   \brief Method who apply an algorithm using the metric member.
   */
   ImageInt applyAlgorithm(ImageChar input, unsigned char threshold, bool outrangeAtZero);
};

template <typename W,typename T>
DistanceTransform<W,T>::DistanceTransform()
{
}

template <typename W,typename T>
DistanceTransform<W,T>::~DistanceTransform()
{
}

#endif // _DistanceTransform_H_
