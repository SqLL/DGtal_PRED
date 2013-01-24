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
const char* outputNameFile= "distanceTransform4connexityOutput";


void make4Connexity(vector<point2dWeighting>& myWeightingVector)
{
	vector<point2d> mySimpleVector;

	// point creation in a DGtal point vector
	mySimpleVector.push_back(point2d(0,0));
	mySimpleVector.push_back(point2d(-1,0));
	mySimpleVector.push_back(point2d(0,1));

	// Creation of Weighting Point
	for (std::vector<point2d>::const_iterator it = mySimpleVector.begin() ; it != mySimpleVector.end(); ++it)
	{
		myWeightingVector.push_back(point2dWeighting(*it,1));
	}
}

void make8Connexity(vector<point2dWeighting>& myWeightingVector)
{
	vector<point2d> mySimpleVector;

	// point creation in a DGtal point vector
	mySimpleVector.push_back(point2d(0,0));
	mySimpleVector.push_back(point2d(-1,0));
	mySimpleVector.push_back(point2d(0,1));
	mySimpleVector.push_back(point2d(-1,1));
	mySimpleVector.push_back(point2d(1,1));

	// Creation of Weighting Point
	for (std::vector<point2d>::const_iterator it = mySimpleVector.begin() ; it != mySimpleVector.end(); ++it)
	{
		myWeightingVector.push_back(point2dWeighting(*it,1));
	}
}

void makeSimpleChamfrein(vector<point2dWeighting>& myWeightingVector)
{
	point2d base(0,0);
	point2d pointNegatif(1,0);
	point2d pointPositif(0,1);
	point2d pointFullPositif(1,1);
	point2d pointHalfPositif(-1,1);
	point2d pointChamfer1(-1,2);
	point2d pointChamfer2(1,2);
	point2d pointChamfer3(2,1);
	point2d pointChamfer4(-2,1);

	myWeightingVector.push_back(point2dWeighting(pointNegatif,5));
	myWeightingVector.push_back(point2dWeighting(pointPositif,5));
	myWeightingVector.push_back(point2dWeighting(pointFullPositif,7));
	myWeightingVector.push_back(point2dWeighting(pointHalfPositif,7));
	myWeightingVector.push_back(point2dWeighting(pointChamfer1,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer2,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer3,11));
	myWeightingVector.push_back(point2dWeighting(pointChamfer4,11));

}


int main(int argc, char** argv)
{

if(argc != 4)
{
	cout << argc << endl;
	cout << "to use this program you have to enter this command line ./main path/of/the/picture connexity threshold " << endl;
	cout << "Threshold should be in 0-255" << endl;
	cout << "connexity should be 4connexity or 8connexity or chamfer5711" << endl;
}
else 
{
	int threshold = atoi(argv[2]);

	if(threshold <= 255 && threshold >= 0 && ( (strcmp(argv[3],"4connexity") == 0 ) || (strcmp(argv[3],"8connexity") == 0 ) || strcmp(argv[3],"chamfer5711") == 0) )
	{
		vector<point2dWeighting> myWeightingVector;

	   if(strcmp(argv[3],"4connexity") == 0 )
	   {
		   make4Connexity(myWeightingVector);
	   }
	   else if(strcmp(argv[3],"8connexity") == 0)
	   {
		   make8Connexity(myWeightingVector);
	   }
	   else
	   {
		   makeSimpleChamfrein(myWeightingVector);
	   }


      // mask creation
      SymmetricMask<point2dWeighting> myMask;
      SymmetricMaskGenerator<point2dWeighting> generateur;
      myMask = generateur.generateMask(myWeightingVector);



      // CMETRIC and distance Transform instanciation
      CChamferMetric<int,point2d> myMetric(myMask);
      ChamferDistanceTransform<int,point2d> myDistance(myMetric);



      Image image = DGtal::PNMReader<Image>::importPGM(argv[1], true); 


      /** distance transformation **/
      ImageInt output = myDistance.applyAlgorithm(image,threshold,true);


      /** output colorisation **/
      DGtal::Board2D aBoard;
      ImageInt::Value maxDT = (*std::max_element(output.begin(), 
                                                      output.end()));
      typedef DGtal::HueShadeColorMap<ImageInt::Value,2> HueTwice;
      aBoard.clear();
      Display2DFactory::drawImage<HueTwice>(aBoard, output, (ImageInt::Value)0, (ImageInt::Value)maxDT);
      aBoard.saveEPS(outputNameFile);

      /** distance transformation numeric output **/
      /*
      typename Image::Domain::ConstIterator dit= image.domain().begin();	
      for(;dit != image.domain().end();++dit)
      {
		      cout << (*dit) << " : " << (int)output(*dit) << endl;			
      }*/
	}
}
return 0;
}

