/* Path.h - Prototype interface V4

Implementing Pathfinding, see the following links for info:
http://forum.mc-server.org/showthread.php?tid=1571
https://github.com/mc-server/MCServer/issues/1391


TODO
Should I throw exceptions?
Replace maxDistance with maxPoints? - makes a lot of sense


later:
Run()? - testing will tell
Blacklist, ladder list
Functor instead of maxDown?
Smoother approach to target?

*/


#pragma once
#include "Globals.h"
#include "Pathfinder.h"
#include <vector>

class cPath
{
public:
	cPath();
	Vector3d & GetPoint(int index);
	int GetLength();
private:
	std::vector<Vector3d> & points;
	int length;

	friend class aPathfinder;
};

