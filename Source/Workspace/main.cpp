//General
#include "DGtal/kernel/PointVector.h"

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
#include "./include/SymmetricMaskGenerator.h"

//Algorithm
#include "./include/MedialAxis.h"
#include "./include/DistanceTransform.h"
#include "./include/ChamferDistanceTransform.h"


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
	*	Cela correspond a *
	*									 **
*/
base.selfDisplay(cout);
cout << endl;

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

//Affichage de ces points
vector<point2dWeighting>::const_iterator it;
for(it=vectorPoints.begin();it!=vectorPoints.end();++it)
{
	cout << (*it);
}
cout << endl;
/**

beacoup d'erreur sur l'heritage ainsi que sur la signature du maskgenerator..
il y a egalement d'autre questions concernant les templates

In file included from /home/remi/Pred/DGtal_PRED/Source/Workspace/./include/ChamferMask.h:19:0,
                 from /home/remi/Pred/DGtal_PRED/Source/Workspace/./include/CChamferMetric.h:19,
                 from /home/remi/Pred/DGtal_PRED/Source/Workspace/main.cpp:13:
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h: In copy constructor ‘SymmetricMask<T>::SymmetricMask(const SymmetricMask<T>&)’:
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h:66:2: error: ‘myPointsMask’ was not declared in this scope
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h: In copy constructor ‘SymmetricMask<T>::SymmetricMask(const SymmetricMask<T>&) [with T = Weighting<DGtal::PointVector<2u, int> >]’:
/home/remi/Pred/DGtal_PRED/Source/Workspace/main.cpp:80:72:   instantiated from here
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h:68:24: error: ‘const class SymmetricMask<Weighting<DGtal::PointVector<2u, int> > >’ has no member named ‘begin’
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h:68:24: error: ‘const class SymmetricMask<Weighting<DGtal::PointVector<2u, int> > >’ has no member named ‘end’
make[2]: *** [CMakeFiles/main.dir/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/main.dir/all] Error 2
make: *** [all] Error 2
**/

//Creation du masque avec generation de ce dernier

//SymmetricMask<point2dWeighting> masque=SymmetricMask<point2dWeighting>();
//SymmetricMaskGenerator<point2dWeighting> generateur=SymmetricMaskGenerator<point2dWeighting>();
//masque = generateur.generateMask(vectorPoints);




return 0;
}

