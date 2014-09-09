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
class cPath;
#include "Pathfinder.h"
#include <vector>

class cPath
{
public:
	cPath();
	Vector3d GetPoint(int index) const;
	int GetLength() const;
private:
	std::vector<Vector3d> points;
	int length;  // The length is needed because vector->resize will deallocate everything out of range.
	// However we'd like to minimize de-allocations and re-allocations, and cPath might be reused.

	friend class aPathfinder;
};

