//General
#include "DGtal/kernel/PointVector.h"


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
#include "./include/SymmetricMaskGenerator.h"

//Algorithm
#include "./include/MedialAxis.h"
#include "./include/DistanceTransform.h"
#include "./include/ChamferDistanceTransform.h"




using namespace std;

/*
	* Fichier de test pour construire un Masque
	*
*/

int main(int argc, char** argv)
{
PointVector <2, int> monsuperpoint;
Weighting< PointVector <2, int> > pointponderer(monsuperpoint,2);
Weighting< PointVector <2, int> > pointpareil(pointponderer);
Weighting< PointVector <2, int> > pointdifferent(monsuperpoint,3);

cout << "Display of a Weighting Point " << pointponderer << endl;

if(pointponderer==pointpareil)
{
	cout << pointponderer << "is the same than " << pointpareil << endl;
}


if(pointponderer==pointdifferent)
{
	cout << pointponderer << "is the same than " << pointpareil << endl;
}

return 0;
}

