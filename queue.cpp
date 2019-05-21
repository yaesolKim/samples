// queue.cpp : use queue for processing tracking data with noses
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <queue>

int main()
{
	std::queue<double> q_tracking;

	q_tracking.push(1);
	q_tracking.push(2);
	q_tracking.push(3);

	//std::cout << "size :" << q_tracking.size() << " front :" << q_tracking.front() << " back :" << q_tracking.back() << std::endl;

	int qq = 4;
	double old = 0, current;
	while (qq < 20)
	{
		current = q_tracking.front() + q_tracking.back();

		//std::cout << "front :" << q_tracking.front() << " back :" << q_tracking.back();

		q_tracking.pop();
		q_tracking.push(qq);

		current = (current + 2 * q_tracking.front()) / 4;

		//std::cout << "mid :" << q_tracking.front() << std::endl;

		double direction = current - old;
		std::cout << "current : " << current  << "old : " << old << "direction : " << direction << std::endl;

		old = current;
		qq += 1;
//		std::cout << " size :" << test.size() << " front :" << test.front() << " back :" << test.back() << std::endl;

	}
	std::cout << std::endl;
}
