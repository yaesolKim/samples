#include "pch.h"
#include <stdio.h> 
#include <stdlib.h>

#include <iostream>
#include <math.h> 
#include <queue>

double pos_x, pos_y, pos_z;
double pos_x_old, pos_y_old, pos_z_old;
double a, b, c, d;
double theta, y_current, y_old, z_current, z_old, v_y, v_z, v; //calculate using poses
double rot_direction;

//void setRobotPose(int ori, float x, float y, float z, int r, float direction_degree);

int main() 
{
	std::queue<double> q_y, q_z;


	pos_y = 0.0;
	pos_z = 0.0;
	
	y_old = 0.0;
	z_old = 0.0;

	q_y.push(pos_y);
	q_y.push(pos_y);

	q_z.push(pos_z);
	q_z.push(pos_z);

	//std::cout << "size :" << q_tacking.size() << " front :" << q_tacking.front() << " back :" << q_tacking.back() << std::endl;

	int i = 1;
//	double old = 0, current;
	while (i < 20)
	{
		pos_y = -i;
		pos_z = -i;

		y_current = (q_y.front() + 2 * q_y.back() + pos_y) / 4;
		z_current = (q_z.front() + 2 * q_z.back() + pos_z) / 4;

		q_y.pop();
		q_y.push(pos_y);

		q_z.pop();
		q_z.push(pos_z);

		v_y = y_current - y_old;
		v_z = z_current - z_old;
		v = sqrt(pow(v_y, 2) + pow(v_z, 2));


		rot_direction = (asin(v_z / v) * 180) / 3.141592;
		
		if(rot_direction > 0)
			theta = (acos(v_y / v) * 180) / 3.141592;
		else
			theta = (-1)*(acos(v_y / v) * 180) / 3.141592;

		if (theta < 0)
			theta += 360;


		std::cout << " vector: ( " << v_y << " , " << v_z << " ) " << std::endl;
		std::cout << i << "th theta :" << theta << std::endl;

		y_old = y_current;
		z_old = z_current;
		
		i += 1;
//		std::cout << " size :" << test.size() << " front :" << test.front() << " back :" << test.back() << std::endl;

	}
	std::cout << std::endl;
}
