//General
#include "./include/PointND.h"
#include "./include/Picture.h"

//Metric
#include "./include/CLocalPremetric.h"
#include "./include/CMetric.h"
#include "./include/CSeparableMetric.h"
#include "./include/CMetricInducedByNorm.h"
#include "./include/CChamferMetric.h"

//Mask
#include "./include/Mask.h"
#include "./include/SymetricMask.h"
#include "./include/ChamferMask.h"

//Mask Generator
#include "./include/ChamferMaskGenerator.h"

//Algorithm
#include "./include/MedialAxis.h"
#include "./include/DistanceTransform.h"
#include "./include/ChamferDistanceTransform.h"


using namespace std;

int main(int argc, char** argv)
{
PointND<int> monSuper(6,10,50);
PointND<int> mon(5,10,50);


Picture<int> myPicture;

Picture<int> myNewPicture(2,1);

myNewPicture.addPoint(monSuper);
myNewPicture.addPoint(mon);


Picture<int> mySecondPicture(myNewPicture);

cout << "x = " << mySecondPicture.getX() << " y = " << mySecondPicture.getY() << endl;

cout << mySecondPicture << endl;

return 0;
}

