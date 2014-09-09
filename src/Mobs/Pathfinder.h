/* Pathfinder.h - Prototype interface V2 - Subject to change, not implemented yet.

Created on: Sep 8, 2014
Author: Wiseoldman95

Implementing Pathfinding, see the following links for info:
http://forum.mc-server.org/showthread.php?tid=1571
https://github.com/mc-server/MCServer/issues/1391


TODO
Get feedback regarding header before implementing <
Modify the header to follow the project's code conventions
Better comments
*/





/* Calculates paths using a* and spits them out as cPath instances. */

#pragma once
#include "Path.h";

class cPathfinder
{

/** Creates a new Pathfinder

boundingBoxWidth - The bounding box width of the mob wishing to use this Pathfinder
boundingBoxHeight - The bounding box height of the mob wishing to use this Pathfinder
maxUp - How many vertical blocks can this mob move upwards?
 		(e.g. Silverfish: 0, Zombie: 1, Spider: ~20)
maxDown - How many vertical blocks can this mob move downwards?
 		(e.g. Silverfish: 1, Zombie: 1, Spider: ~3?)
maxDistance - The maximum distance allowed for the Pathfinder.
*/
cPathfinder(double a_boundingBoxWidth, double a_boundingBoxHeight,
		int a_maxUp,int a_maxDown , int a_maxDistance);






/** Creates a path using a*, takes bounding boxes into account

An exception (TODO) will be thrown if a_startPoint is outside an imaginry
cube which has an edge the size of maxDistance and its origin is at a_endingPoint.
*/
cPath & createPath(const Vector3d & a_startPoint, const Vector3d & a_endingPoint, bool a_guesswork);





/** just like createPath, but overrides an existing path. Saves memory allocations! */
cPath & updatePath(const Vector3d & a_path,
		const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool a_guesswork);
};

