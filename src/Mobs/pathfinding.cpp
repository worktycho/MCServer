 /*I AM JUST PLAYING AROUND WITH SOME PSEUDO-CODE, DO NOT USE
 * THIS BRANCH FOR ANYTHING WHATSOEVER, IT'S PSEUDO C AND
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

#include "pathfinding.h"


typedef struct
{
double x;
double y;
double z;
bool passable;
path_point next_point;
} path_point_t;

path_point find_path(
int start_x, int start_y, int start_z,
int end_x, int end_y, int end_z,
double mob_width, double mob_height
)
{
	return NULL;
}
