/*!
 * \file ChamferMaskGenerator.h
 * \brief a ChamferMaskGenerator
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 04/12/2012
 *
 * This file represent a ChamferMaskGenerator which will be use as mask for a picture
 *
 */


#ifndef _CCHAMFERMASKGENERATOR_H_
#define _CCHAMFERMASKGENERATOR_H_


#include <iostream>
#include <cmath>
#include "ChamferMask.h"
#include <vector>




/*! \class ChamferMaskGenerator
   *
   * \brief Abstract class to generate a ChamferMask
   *
*/

template <typename T>
class ChamferMaskGenerator : public SymmetricMask<T>
{
   private:
   ChamferMask<T> myMask;

   public:

   /*!
      *   \fn ChamferMaskGenerator();
      *   \brief Constructor of a ChamferMaskGenerator without parameters
   */
   ChamferMaskGenerator();

   /*!
      *   \fn ChamferMaskGenerator(const ChamferMaskGenerator &refChamferMaskGenerator);
      *   \brief Constructor to make a copy of the ChamferMaskGenerator used as parameters
   */
   ChamferMaskGenerator(const ChamferMaskGenerator &refChamferMaskGenerator);

   /*!
      *   \fn ~ChamferMaskGenerator();
      *   \brief To desalloc memory use by the ChamferMaskGenerator
   */
   ~ChamferMaskGenerator();

   /*!
      *   \fn maskGenerator(const vector<T> & myData);
      *   \brief Generate a mask with a vector of data as parameters
      *   \return the mask from myData
   */
   ChamferMask<T> maskGenerator(const vector<T> & myData);
};




#endif // _ChamferMaskGenerator_H_
