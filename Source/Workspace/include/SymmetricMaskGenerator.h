/*!
 * \file SymmetricMaskGenerator.h
 * \brief is a class to generate a symmetric mask using a vector which represent a part of the mask
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 19/12/2012
 *
 *
 */


#ifndef _SYMMETRICMASKGENERATOR_H_
#define _SYMMETRICMASKGENERATOR_H_


#include <iostream>
#include <cmath>
#include <vector>
#include "DGtal/kernel/PointVector.h"
#include "MaskGenerator.h"
#include "SymmetricMask.h"






template <typename T>
class SymmetricMaskGenerator : public MaskGenerator<T>
{
	friend class SymmetricMask<T>;

	public:
	/*!
		*	\fn Weighting();
		*	\brief Constructor of a WeightPoint without parameters
	*/
	SymmetricMaskGenerator();

	/*!
		* \fn ~Weighting();
		* \brief To desalloc memory use by the Weighting
	*/
	~SymmetricMaskGenerator();

	/*!
		* \fn Mask<T> generateMask(const Vector < Weighting<T> > & vector);
		*	\brief In this method you have to make a mask and initial
	*/
	SymmetricMask<T> generateMask(const vector<T>& vectorPoint);
};


// Dans cette fonction le code est vraiment à ameliorer
template<typename T>
SymmetricMask<T> SymmetricMaskGenerator<T>::generateMask(const vector<T> & vectorPoint)
{
	SymmetricMask<T> result;
	T tmp;
	//Pour fabriquer un mask j'utilise les points et j'inverse leurs coordonnées pour obtenir le masque.
	typename vector<T>::const_iterator it;	
	for(it=vectorPoint.begin();it!=vectorPoint.end();++it)
	{
		//Coordonnées basiques
		result.add(*it);
		//Coordonnées inversé
		tmp=(*it);
		tmp=tmp.reverse();
		if( !(tmp == (*it)) )	
		{
			result.add(tmp);
		}
	}
	//On retourne le masque complet
	return result;
}


template <typename T>
SymmetricMaskGenerator<T>::SymmetricMaskGenerator()
{
}

template <typename T>
SymmetricMaskGenerator<T>::~SymmetricMaskGenerator()
{
}






#endif
