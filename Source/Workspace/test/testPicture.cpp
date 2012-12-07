
#include "./include/Picture.h"
#include "./include/PointND.h"


using namespace std;

int main(int argc, char** argv)
{
PointND<int> monSuper(6,10,50);
PointND<int> mon(5,10,50);


Picture<int> myPicture();

Picture<int> myNewPicture(2,1);

myNewPicture.addPoint(monSuper);
myNewPicture.addPoint(mon);


Picture<int> mySecondPicture(myNewPicture);

cout << "x = " << mySecondPicture.getX() << " y = " << mySecondPicture.getY() << endl;

cout << mySecondPicture << endl;

return 0;
}

