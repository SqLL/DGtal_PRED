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

#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"

#include "DGtal/base/BasicFunctors.h"
#include "DGtal/kernel/BasicPointPredicates.h"
#include "DGtal/kernel/sets/DigitalSetInserter.h"

#include "DGtal/images/ImageContainerBySTLVector.h"
#include "DGtal/images/ImageHelper.h"
#include "DGtal/geometry/volumes/distance/DistanceTransformation.h"
#include "DGtal/images/imagesSetsUtils/IntervalForegroundPredicate.h"

#include "DGtal/io/boards/Board2D.h"
#include "DGtal/io/readers/PNMReader.h"
#include "DGtal/io/colormaps/HueShadeColorMap.h"
#include "DGtal/io/colormaps/GrayscaleColorMap.h"

/**
	This is the property of Polytech Nantes and University of Provence
	This files is example of Discret Geometry's Algorithm
	This files has been written by Rémi Matéo
**/

using namespace std;

typedef PointVector <2, int> point2d;
typedef Weighting< point2d > point2dWeighting;
typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned char> Image;
typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned int> ImageInt;
typedef DGtal::GrayscaleColorMap<unsigned char> Gray;
const std::string examplesPath= "/home/remi/Pred/DGtal_PRED/Source/Workspace/Ressources/";
const char* outputNameFile= "distanceTransform4connexityOutput";


void make4Connexity(vector<point2dWeighting>& myWeightingVector)
{
	vector<point2d> mySimpleVector;

	//Creation du point dans un vector de point DGtal
	mySimpleVector.push_back(point2d(0,0));
	mySimpleVector.push_back(point2d(-1,0));
	mySimpleVector.push_back(point2d(0,1));

	//Creation de Weighting Point
	for (std::vector<point2d>::const_iterator it = mySimpleVector.begin() ; it != mySimpleVector.end(); ++it)
	{
		myWeightingVector.push_back(point2dWeighting(*it,1));
	}
}

void make8Connexity(vector<point2dWeighting>& myWeightingVector)
{
	vector<point2d> mySimpleVector;

	//Creation du point dans un vector de point DGtal
	mySimpleVector.push_back(point2d(0,0));
	mySimpleVector.push_back(point2d(-1,0));
	mySimpleVector.push_back(point2d(0,1));
	mySimpleVector.push_back(point2d(-1,1));
	mySimpleVector.push_back(point2d(1,1));

	//Creation de Weighting Point
	for (std::vector<point2d>::const_iterator it = mySimpleVector.begin() ; it != mySimpleVector.end(); ++it)
	{
		myWeightingVector.push_back(point2dWeighting(*it,1));
	}
}

void makeSimpleChamfrein(vector<point2dWeighting>& myWeightingVector)
{
	point2d base(0,0);
	point2d pointNegatif(-1,0);
	point2d pointPositif(0,1);
	point2d pointFullPositif(1,1);
	point2d pointHalfPositif(-1,1);
	point2d pointChamfer1(-1,2);
	point2d pointChamfer2(1,2);
	point2d pointChamfer3(2,1);
	point2d pointChamfer4(2,-1);

	myWeightingVector.push_back(point2dWeighting(pointNegatif,5));
	myWeightingVector.push_back(point2dWeighting(pointPositif,5));
	myWeightingVector.push_back(point2dWeighting(pointFullPositif,7));
	myWeightingVector.push_back(point2dWeighting(pointChamfer1,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer2,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer3,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer4,11));

}


int main(int argc, char** argv)
{

/**																													 *
	*	Construction des differents point pour un masque simple ***
	*																													 *
**/																													




//vector<point2d> mySimpleVector;
vector<point2dWeighting> myWeightingVector;


makeSimpleChamfrein(myWeightingVector);

//Création du mask
SymmetricMask<point2dWeighting> myMask;
SymmetricMaskGenerator<point2dWeighting> generateur;
myMask = generateur.generateMask(myWeightingVector);



// Instance de CMETRIC et distance Transform
CMetric<int,point2d> myMetric(myMask);
DistanceTransform<int,point2d> myDistance(myMetric);


std::string filename =  examplesPath + "contourS.pgm";
Image image = DGtal::PNMReader<Image>::importPGM(filename, true); 


/** On applique l'algo **/
ImageInt output = myDistance.applyAlgorithm(image,135,true);


/** Colorisation de l'image **/
DGtal::Board2D aBoard;
ImageInt::Value maxDT = (*std::max_element(output.begin(), 
                                                output.end()));
typedef DGtal::HueShadeColorMap<ImageInt::Value,2> HueTwice;
aBoard.clear();
Display2DFactory::drawImage<HueTwice>(aBoard, output, (ImageInt::Value)0, (ImageInt::Value)maxDT);
aBoard.saveEPS(outputNameFile);

/**
typename Image::Domain::ConstIterator dit= image.domain().begin();	
for(;dit != image.domain().end();++dit)
{
		cout << (*dit) << " : " << (int)image(*dit) << endl;			
}
**/

return 0;
}

