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
cPathfinder(double a_boundingBoxWidth, double a_boundingBoxHeight,
		int a_maxUp,int a_maxDown , int a_maxDistance);


/*Typical usage: (Pseudocode)
 * Cmonster::MoveToPosition(myPathfinder.getPathPoint(my_position,player_position));
 *
 * Returns a point indicating where the mob should move next in order to reach
 * EndingPoint.
 *
 * If the path is not calculated yet, calculates some of the path.
 * The function will not calculate the entire path in a single call
 * in order to prevent blocking.
 *
 * Note that this function does not necessarily calculate a new path: If the mob is
 * far enough a new path will only be re-calculated once every many calls.
 * Therefore, it is safe to call this every tick
 * (or better: everytime the mob reaches the point returned by the previous getPathPoint)
 *
 * If a path is not calculated yet (typically happens on the first few calls), the returned value will be
 * determined by the variable "guesswork":
 * If false: currentPoint will be returned, effectively freezing the mob until the path is calculated.
 * If true: The returned points will make the mob move in a dumb straight path
 * towards the target until the path is calculated.
 * */
const Vector3d & getPathPoint(const Vector3d & a_currentPoint, const Vector3d & a_endingPoint, bool guesswork);



};

