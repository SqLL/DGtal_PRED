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



#include <string>





typedef DGtal::ImageContainerBySTLVector< Z2i::Domain, unsigned char> Image;
typedef DGtal::GrayscaleColorMap<unsigned char> Gray;
int main()
{
	const std::string examplesPath= "/home/remi/pred/DGtal_PRED/Source/Experience/";	
	std::string filename =  examplesPath + "samples/contourS.pgm";
  Image image = DGtal::PNMReader<Image>::importPGM(filename); 
  DGtal::trace.info() << "Imported image: "<<image<<endl;


 DGtal::Board2D aBoard;
  aBoard << image.domain();  
  aBoard.saveSVG("imageDomainTuto.svg");
  aBoard.clear();
  Display2DFactory::drawImage<Gray>(aBoard, image, (unsigned char)0, (unsigned char)255);
  aBoard.saveEPS("imageDomainTuto2.eps");


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
  aBoard.saveEPS("imageDomainTuto3.eps");
}

