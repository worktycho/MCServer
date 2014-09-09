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
 * Get feedback regarding header before implementing
 * Modify the header to follow the project's code conventions
 * */


/*Calculate paths using a* and spits them out as cPath instances.*/

#pragma once

class cPathfinder
{


cPathfinder(double a_boundingBoxWidth, double a_boundingBoxHeight,
		int a_maxUp,int a_maxDown , int a_maxDistance);
/*I could make the cPathfinder a static class, but then we'll have to forward the above
 *  rarely changing parameters each call*/


cPath & createPath(const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool a_guesswork);




};

