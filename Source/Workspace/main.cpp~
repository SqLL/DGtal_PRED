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

using namespace std;

typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned char> Image;

typedef DGtal::GrayscaleColorMap<unsigned char> Gray;

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

SymmetricMask<point2dWeighting> myMask;
SymmetricMaskGenerator<point2dWeighting> generateur;
myMask = generateur.generateMask(vectorPoints);

// definition of metric
CMetric<int,point2d> myMetric(myMask);
DistanceTransform<int,point2d> myDistance(myMetric);

const std::string examplesPath= "/home/remi/Pred/DGtal_PRED/Source/Workspace/Ressources/";	
std::string filename =  examplesPath + "contourS.pgm";
Image image = DGtal::PNMReader<Image>::importPGM(filename); 
myDistance.applyAlgorithm(image,135,true);



/**
 DGtal::Board2D aBoard;
  aBoard << image.domain();  
  //aBoard.saveSVG("imageDomainTuto.svg");
  aBoard.clear();
  Display2DFactory::drawImage<Gray>(aBoard, image, (unsigned char)0, (unsigned char)255);
  //aBoard.saveEPS("imageDomainTuto2.eps");

	//cout << image.range() << endl;
	//cout << image.constRange() << endl;
	cout << image.size() << endl;
	//cout << image.extent() << endl;
	//cout << image.domain() << endl;
	//cout << image << endl;
	image.selfDisplay(cout);




	typename Image::Domain::ConstIterator dit= image.domain().begin();	
	for(;dit != image.domain().end();++dit)
	{
			cout << (*dit) << " : " << (int)image(*dit) << endl;			
	}

	//for(image.Iterator =(image.Iterator.begin()) ; image.Iterator!= image.Iterator.end(); image.Iterator++){
		//cout << *i << endl;
	//}

  typedef IntervalForegroundPredicate<Image> Binarizer; 
  Binarizer b(image,1, 135);
 
  typedef DGtal::DistanceTransformation<Z2i::Space, Binarizer, 2> DTL2;
  typedef DTL2::OutputImage OutputImage;
  DTL2 dt(image.domain(),b);

  OutputImage result = dt.compute(); 

  OutputImage::Value maxDT = (*std::max_element(result.begin(), 
                                                result.end()));
  typedef DGtal::HueShadeColorMap<OutputImage::Value,2> HueTwice;

  aBoard.clear();
  Display2DFactory::drawImage<HueTwice>(aBoard, result, (OutputImage::Value)0, (OutputImage::Value)maxDT);
  //aBoard.saveEPS("imageDomainTuto3.eps");
**/
return 0;
}

