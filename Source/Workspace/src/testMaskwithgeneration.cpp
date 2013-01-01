/*!
 * \file testMaskwithgeneration.cpp
 * \brief File test for generate a symmetric mask
 * \author Author Matéo Rémi
 * \version Version 0.0
 * \date 19/12/2012
 *
 * This file is a test file to generated a mask in this case that is simply octane
 *
 */

//General
#include "DGtal/kernel/PointVector.h"

//STL
#include <vector>

//Point
#include "./include/Weighting.h"

//Metric
#include "./include/CLocalPremetric.h"
#include "./include/CMetric.h"
#include "./include/CChamferMetric.h"

//Mask
#include "./include/Mask.h"
#include "./include/SymmetricMask.h"
#include "./include/ChamferMask.h"

//Mask Generator
#include "./include/MaskGenerator.h"
#include "./include/ChamferMaskGenerator.h"

//Algorithm
#include "./include/MedialAxis.h"
#include "./include/DistanceTransform.h"
#include "./include/ChamferDistanceTransform.h"

//To generate a Mask
#include "./include/SymmetricMaskGenerator.h"

using namespace std;

int main(int argc, char** argv)
{
/**																													 *
	*	Construction des differents point pour un masque simple ***
	*																													 *
**/																													

//Renommage obligatoire pour les template
typedef PointVector <2, int> point2d;
typedef Weighting< point2d > point2dWeighting;

//Création des points
point2d base(0,0);
point2d pointNegatif(-1,0);
point2d pointPositif(0,1);
/*
	*	Cela correspond a 	*
	*									 	 **
*/


//Creation d'un WeightingPoint
Weighting< point2d > pointponderer(base,1);

//Creation du vector de point
vector <point2dWeighting > vectorPoints;

//Ajouts
point2dWeighting basep(base,1);
Weighting< point2d > pointNegatifp(pointNegatif,1);
Weighting< point2d > pointPositifp(pointPositif,1);

vectorPoints.push_back(basep);
vectorPoints.push_back(pointNegatifp);
vectorPoints.push_back(pointPositifp);

cout << "Here it's the vector of points " << endl;
//Affichage de ces points

vector<point2dWeighting>::const_iterator it;
for(it=vectorPoints.begin();it!=vectorPoints.end();++it)
{
	cout << (*it);
}
cout << " end " << endl;

//Creation du masque avec generation de ce dernier
SymmetricMask<point2dWeighting> masque;
SymmetricMaskGenerator<point2dWeighting> generateur;
masque = generateur.generateMask(vectorPoints);

cout << "Here it's SymmetricMask generated " << endl;
cout << masque << endl;

return 0;
}

