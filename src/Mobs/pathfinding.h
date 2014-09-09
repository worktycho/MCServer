 /*I AM JUST PLAYING AROUND WITH SOME PSEUDO-CODE, DO NOT USE
 * THIS BRANCH FOR ANYTHING WHATSOEVER
 * IT PROBABLY DOES NOT EVEN COMPILE YET*/

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


#pragma once

class cPathfinder
{

/*
 * boundingBoxWidth - The bounding box width of the mob wishing to use this Pathfinder
 * boundingBoxHeight - The bounding box height of the mob wishing to use this Pathfinder
 * maxUp - How many vertical blocks can this mob move upwards?
 * 			(e.g. Silverfish: 0, Zombie: 1, Spider: ~20)
 * maxDown - How many vertical blocks can this mob move downwards?
 * 		(e.g. Silverfish: 1, Zombie: 1, Spider: ~3?)
 * maxDistance - The maximum distance allowed for the Pathfinder
 * When calling moveToByPath, an exception (TODO) will be thrown if startingPoint
 * is outside an imaginry cube which has an edge the size of maxDistance and its
 * origin is at endingPoint */
cPathfinder(double boundingBoxWidth, double boundingBoxHeight,
		int maxUp,int maxDown , int maxDistance);


/*Typical usage: (Pseudocode)
 * Cmonster::MoveToPosition(myPathfinder.getPathPoint(my_position,player_position));
 *
 * Note that this function does not necessarily calculate a new path: If the mob is
 * far enough a new path will only be re-calculated once every many calls.
 * Therefore, it is safe to call this every tick
 * (or better: everytime the mob reaches the point returned by the previous getPathPoint)
 *
 * If a path is not calculated yet (typically happens on first call), the returned value will be
 * determined by the variable "guesswork":
 * If false: currentPoint will be returned, effectively freezing the mob until the path is calculated.
 * If true: The returned points will make the mob movein a dumb straight path
 * towards the target until the path is calculated.
 * */
const Vector3d & getPathPoint(const Vector3d & currentPoint, const Vector3d & endingPoint, bool guesswork);



};

