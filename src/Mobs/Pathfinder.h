/* Pathfinder.h - Prototype interface V4

Implementing Pathfinding, see the following links for info:
http://forum.mc-server.org/showthread.php?tid=1571
https://github.com/mc-server/MCServer/issues/1391


TODO
Should I throw exceptions?
Replace maxDistance with maxPoints? - makes a lot of sense
Anything else before I start implementing?

later:
Run()? - testing will tell
Blacklist, ladder list
Functor instead of maxDown?
Smoother approach to target?

*/





/* Calculates paths using a*. */

#pragma once
class cPathfinder;
#include "Globals.h"
#include "Path.h"

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





/** Finds a path using a*, takes bounding boxes into account

Returns 1 on success and fills the given cPath.
You are encouraged to give the function an already used cPath to save
allocations.

An exception/error (TODO) will be thrown if a_startPoint is outside an imaginry
cube which has an edge the size of maxDistance and its origin is at a_endingPoint.
*/
int FindPath(cPath & resultPath, const Vector3d & a_startPoint, const Vector3d & a_endingPoint);




/*
TODO: The current interface calculates the path immediately, could this cause blocking?

Do we need the following function:

Calculates some of the path, returns true when the path is ready
Return false if path is not ready or if CreatePath was never called
The contents of my_path will only change when this function switches from false to true.
bool Run();

If we need this -
TODO: Handling offset. What happens when the path has finished calculating but the
mob is no longer at the starting point?

One possible solution is offloading that responsibility to the mob AI:
If the mob AI is following a path, and it decides to recalculate, the mob AI
Is responsible for calling CreatePath with a starting point which is a couple of seconds
away from the mob's current location.
*/
};


