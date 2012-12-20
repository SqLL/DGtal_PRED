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


//Algorithm
#include "./include/MedialAxis.h"
#include "./include/DistanceTransform.h"
#include "./include/ChamferDistanceTransform.h"


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

In file included from /home/remi/Pred/DGtal_PRED/Source/Workspace/main.cpp:32:0:
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMaskGenerator.h: In member function ‘SymmetricMask<T> SymmetricMaskGenerator<T>::generateMask(const std::vector<T>&) [with T = Weighting<DGtal::PointVector<2u, int> >]’:
/home/remi/Pred/DGtal_PRED/Source/Workspace/main.cpp:104:46:   instantiated from here
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMaskGenerator.h:63:3: error: no matching function for call to ‘SymmetricMask<Weighting<DGtal::PointVector<2u, int> > >::add(const Weighting<DGtal::PointVector<2u, int> >&)’
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMaskGenerator.h:63:3: note: candidate is:
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h:84:6: note: void SymmetricMask<T>::add(const Weighting<T>&) [with T = Weighting<DGtal::PointVector<2u, int> >]
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMask.h:84:6: note:   no known conversion for argument 1 from ‘const Weighting<DGtal::PointVector<2u, int> >’ to ‘const Weighting<Weighting<DGtal::PointVector<2u, int> > >&’
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMaskGenerator.h:65:3: error: no matching function for call to ‘Weighting<DGtal::PointVector<2u, int> >::reverse() const’
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/SymmetricMaskGenerator.h:65:3: note: candidate is:
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/Weighting.h:121:14: note: Weighting<T> Weighting<T>::reverse(const Weighting<T>&) [with T = DGtal::PointVector<2u, int>]
/home/remi/Pred/DGtal_PRED/Source/Workspace/./include/Weighting.h:121:14: note:   candidate expects 1 argument, 0 provided
make[2]: *** [CMakeFiles/main.dir/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/main.dir/all] Error 2
make: *** [all] Error 2
**/

//Creation du masque avec generation de ce dernier

SymmetricMask<point2dWeighting> masque;
SymmetricMaskGenerator<point2dWeighting> generateur;

//masque = generateur.generateMask(vectorPoints);




return 0;
}

