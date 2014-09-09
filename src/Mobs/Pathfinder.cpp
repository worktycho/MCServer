/* pathfinding.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Wiseoldman95
 *      Implementing Pathfinding, see the following links for info:
 *      http://forum.mc-server.org/showthread.php?tid=1571
 *      https://github.com/mc-server/MCServer/issues/1391
 *
 */

#include "Pathfinder.h"

cPathfinder::cPathfinder(double boundingBoxWidth, double boundingBoxHeight,
		int maxUp,int maxDown , int maxDistance)
{

}

const Vector3d & getPathPoint(const Vector3d & currentPoint, const Vector3d & endingPoint, bool guesswork)
{
	return new const Vector3d(0,0,0);
}
