
#include "./include/Picture.h"
#include "./include/PointND.h"


using namespace std;

int main(int argc, char** argv)
{

PointND<int> monSuperPoint(5,10,5);
PointND<int> monAutreSuperPoint(5,10,5);
PointND<int> monSuper(6,10,50);
PointND<int> mon(5,10,50);


if(mon == monSuper)
{
	cout << "ils sont egaux" << endl;
}
else
cout << "ils ne sont pas egaux" << endl;


if(monSuperPoint == monAutreSuperPoint)
{
	cout << "ils sont egaux" << endl;
}
else
cout << "ils ne sont pas egaux" << endl;


monSuper+=mon;

PointND<int> newpoint(monSuperPoint);
cout << newpoint << endl;
monSuper=newpoint;

cout << monSuper << endl;

PointND<int> newpoint2;
newpoint2=newpoint+monSuperPoint;
cout << (newpoint2) << "=" << (newpoint+monSuperPoint) << endl;

cout << newpoint2.get(2) << endl;

return 0;
}
