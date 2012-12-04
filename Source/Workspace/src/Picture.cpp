#include "../include/Picture.h"





Picture::Picture()
: myX(0), myY(0)
{

}

Picture::Picture(const Picture &refpicture)
: myX(refpicture.myX), myY(refpicture.myY)
{

/**
	boost::ptr_list<Point>::iterator iterList;
	for(iterList = refpicture.myPoints.begin(); iterList != refpicture.myPoints.end(); iterList++)
	{
		myPoints.push_front(iterList);   
	}
**/
}

Picture::~Picture()
{
	myPoints.clear();
}

