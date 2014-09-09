/* pathfinding.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Wiseoldman95
 *      Implementing Pathfinding, see the following links for info:
 *      http://forum.mc-server.org/showthread.php?tid=1571
 *      https://github.com/mc-server/MCServer/issues/1391
 *
 */


/*TODO
 * Get feedback regarding header before implementing <
 * Modify the header to follow the project's code conventions
 * Better comments
 * */


/*Calculate paths using a* and spits them out as cPath instances.*/

#pragma once
#include "Path.h";

class cPathfinder
{


cPathfinder(double a_boundingBoxWidth, double a_boundingBoxHeight,
		int a_maxUp,int a_maxDown , int a_maxDistance);
/*I could make the cPathfinder a static class, but then we'll have to forward the above
 *  rarely changing parameters each call*/


/* Creates a path using a*, takes bounding boxes into account*/
cPath & createPath(const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool a_guesswork);

/* just like createPath, but overrides an existing path. Saves memory allocations!*/
cPath & updatePath(const Vector3d & a_path, const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool a_guesswork);




};

