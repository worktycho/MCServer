/* Pathfinder.h - Prototype interface V6

Implementing Pathfinding, see the following links for info:
http://forum.mc-server.org/showthread.php?tid=1571
https://github.com/mc-server/MCServer/issues/1391


TODO
Anything comments before I start implementing?

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
#include <tr1/unordered_map>

using std::tr1::unordered_map;

class cPathfinder
{
public:
	/** Finds a path using a*,

	Returns 1 on success and fills the given cPath. Returns 0 otherwise.
	You are encouraged to give the function an already used cPath to save
	allocations.


	*/
	static int FindPath(
			double a_boundingBoxWidth, //The character's boundingBox Width
			double a_boundingBoxHeight, //The character's boundingBox Height
			int a_maxUp, //What is the highest wall this character can climb / jump? *
			int a_maxDown, //How far down is the character willing to fall? TODO more flexibility here
			int a_maxDistance, //Maximum distance between startPoint and endPoint as defined in manhattanDistance
			int a_maxSearch,
			cPath & a_resultPath,
			const Vector3d & a_startPoint,
			const Vector3d & a_endingPoint
			);




	/*TODO: The current interface calculates the path immediately, could this cause blocking?*/

	/*Interface ends here*/
	struct pathPoint
		{
			public:
				double x;
				double y;
				double z;
				int h;
				int f;
				int g;
				bool closedList;
				pathPoint & nextF; // The next smallest node in our open list
				pathPoint & parent; // A* parent

		};
private:

	// Parameters that are frequently used accross different functions
	static double m_boundingBoxWidth;
	static double m_boundingBoxHeight;
	static int m_maxUp;
	static int m_maxDown;
	static Vector3d m_target;


	// A* fields
	static unordered_map<Vector3d,pathPoint> points; //maps real points to pathfinding points
	static pathPoint & m_smallestF; // The node with the smallest F in our open list

	// A* stuff
	static Vector3d pathPointToVector(pathPoint & point);
	static void openListAdd(const Vector3d & a_point,int a_g);
	static int calculateG(int a_deltaX, int a_deltaY, int a_deltaZ);

	// Vector comparison stuff
	static int manhattanDistance(Vector3d a_v1,Vector3d a_v2);
	static bool isAtSameBlock(Vector3d a_v1,Vector3d a_v2);
};


