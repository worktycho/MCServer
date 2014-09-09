/* Path.h - Prototype interface V2 - Subject to change, not implemented yet.

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

#pragma once

class cPath
{
	public:
	cPath();
	~cPath();
	const Vector3d & getFirstPoint();
	const Vector3d & getNextPoint();
	const Vector3d & getPreviousPoint();
	const Vector3d & getLastPoint();

	void setFirstPoint(const Vector3d & a_point);
	void setNextPoint(const Vector3d & a_point);


	private:
	/*An std vector of Vector3d points*/
	/*current index*/
	/*last index*/
};
