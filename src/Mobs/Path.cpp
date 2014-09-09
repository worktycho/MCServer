#include "Path.h";

cPath::cPath()
{
	this->points=new std::vector<Vector3d>;
	this->length=0;
}





Vector3d & cPath::GetPoint(int index)
{
	return new Vector3d(0,0,0);
}





int cPath::GetLength()
{
	return 0;
}
