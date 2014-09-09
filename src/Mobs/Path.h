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

	const Vector3d & setFirstPoint();
	const Vector3d & setNextPoint();


	private:
	/*An std vector of Vector3d points*/
	/*current index*/
	/*last index*/
};
