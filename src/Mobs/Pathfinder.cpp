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

cPath & cPathfinder::createPath(const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool a_guesswork)
{
	return new cPath();
}
