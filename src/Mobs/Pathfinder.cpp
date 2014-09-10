/* BLEEDING EDGE - Unstable, might not compile, most parts not implemented yet*/

#include "Pathfinder.h"
#include <cmath>

typedef cPathfinder::pathPoint pathPoint;





static bool cPathfinder::IsAtSameBlock(Vector3d a_v1, Vector3d a_v2)
{
	if 	(
		floor(a_v1.x)-floor(a_v2.x)==0 &&
		floor(a_v1.y)-floor(a_v2.y)==0 &&
		floor(a_v1.z)-floor(a_v2.z)==0
		)
		return true;
	return false;
}





static int cPathfinder::ManhattanDistance(Vector3d a_v1, Vector3d a_v2)
{
	return
		(
		abs(floor(a_v1.x) - floor(a_v2.x)) +
		abs(floor(a_v1.y) - floor(a_v2.y)) +
		abs(floor(a_v1.z) - floor(a_v2.z))
		);
}





Vector3d cPathfinder::PathPointToVector(pathPoint & point)
{
	return Vector3d(point.x, point.y, point.z);
}





static int cPathfinder::CalculateG(int a_deltaX, int a_deltaY, int a_deltaZ)
{
	return 100*round(sqrt(a_deltaX*a_deltaX+a_deltaY*a_deltaY+a_deltaZ*a_deltaZ));
	// TODO there are only a handful of possible G values, pre calculate them and return the right one
	// using a simple switch for maximum performance
}






void cPathfinder::OpenListAdd(const Vector3d & a_point, int a_g)
{
	pathPoint newPoint;
	newPoint.x=a_point.x;
	newPoint.y=a_point.y;
	newPoint.z=a_point.z;
	newPoint.h=100*ManhattanDistance(a_point, m_target);
	newPoint.g=a_g;
	newPoint.f=newPoint.h+newPoint.g;
	points[a_point]=newPoint;


	// Insert our new point to the F list. (An ascending list, smallest F first at m_smallestF)
	if (m_smallestF==NULL)  // Case 1, first in the list
	{
		m_smallestF=points[a_point];
		m_smallestF.nextF=NULL;
	}
	else
	{
		pathPoint & currentPoint=m_smallestF;
		pathPoint & previousPoint;

		while (true)
		{
			previousPoint=currentPoint;
			currentPoint=currentPoint.nextF;

			if (currentPoint.nextF==NULL)  // Case 2, We're the biggest on the list
			{
				currentPoint.nextF=points[a_point];
				points[a_point].nextF=NULL;
				break;
			}

			if (currentPoint.f > points[a_point].f)  // Case 3, We're somewhere in the middle
			{
				previousPoint.nextF=points[a_point];
				points[a_point].nextF=currentPoint;
				break;
			}
		}
	}
}





static int cPathfinder::FindPath(double a_boundingBoxWidth, double a_boundingBoxHeight,
int a_maxUp, int a_maxDown, int a_maxDistance, int a_maxSearch,
cPath & a_resultPath, const Vector3d & a_startPoint, const Vector3d & a_endingPoint)
{

	if (ManhattanDistance(a_startPoint, a_endingPoint) > a_maxDistance)
	{
		// TODO This should never happen, throwing an exception here is a good idea.
		// Or we could simply ditch the a_maxDistance parameter and hope the AI behaves correctly.
		// Better go for throwing an exception and crashing the server while debugging.
		// The paremeter can be removed later.
		return 0;

	}
	// TODO custom allocator for zero dynamic allocations.
	points.rehash(ceil(500 / points.max_load_factor()));
	// c++11 equavilant: Points.reserve(500);

	m_smallestF=NULL;
	m_boundingBoxWidth=a_boundingBoxWidth;
	m_boundingBoxHeight=a_boundingBoxHeight;
	m_maxDown=a_maxDown;
	m_maxUp=a_maxUp;
	m_target=a_startPoint;



	// Add the starting point to the open list.
	OpenListAdd(a_endingPoint, 0);  // We actually start from the end, this is more efficient for tracing a* parents.
	pathPoint currentPoint;
	Vector3d currentVector;
	int searchedPoints=0;
	while (1)
	{
		// Look for the lowest F cost on the open list.
		if (m_smallestF==NULL || searchedPoints++>a_maxSearch) return 0;  // No path.
		currentPoint=m_smallestF;
		m_smallestF=m_smallestF.nextF;
		currentVector=PathPointToVector(currentPoint);

		// Scan the ajacent blocks.
		Vector3d neighbor;
		for (int x=-1;x<=1;x+=1)
		{
			for (int y=-1;y<=1;y+=1)
			{
				for (int z=-1;z<=1;z+=1)
				{
					if (x==0 && y==0 && z==0) continue;  // No point in checking oneself.
					if (x==0 && y==0 && z==-1) continue;  // No point in checking directly beneath self.
					// TODO There are more things with no point checking.

					neighbor = Vector3d(currentVector.x+x, currentVector.y+y, currentVector.z+z);

					if (IsAtSameBlock(neighbor, m_target))
					{
						// TODO write to a_resultPath.
						return 1;
					}

					// TODO Check if already at open list, compare G's.
					// TODO Do not add solids to the open list. cChunk stuff here!
					// TODO Let openListAdd / some other function handle partials and bounding boxes (slabs, etc).
					// Note to self: handling means: 1. checking bounding boxes 2. modifying currentPoint's xyz (the avg thing)
					// 3. checking if the modifyed xyz are out of currentPoint's limits, if so, mark as closed
					OpenListAdd(neighbor, CalculateG(x, y, z));
				}
			}
		}
	}
	return 0;  // Useless, stops some compilers from complaining.
}
