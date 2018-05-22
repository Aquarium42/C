#include"stdafx.h"
#include "Random.h"
#include<cmath>
#include <iostream>
#include <random>
using namespace random_;
double random_::get_random(int t)  {
	std::mt19937 twister(t);
	std::uniform_real_distribution<double> uniformInt(-1, 1);
	return(uniformInt(twister));
}

double random_::get_s(double& const x, double& const y) {
	double s = pow(x, 2) + pow(y, 2);
	return s;
}

void random_::get_z(double& const x, double& const y, double& z0, double &z1, double& const s) {
	z0 = x * sqrt(-2 * log(s) / s);
	z1 = y * sqrt(-2 * log(s) / s);
}
void random_::take_random(double& z0, double& z1, int& time) {
	double s = -1, x, y;
	while (s <= 0 || s > 1) {
		x = get_random(time);
		time++;
		y = get_random(time);
		time++;
		s = get_s(x, y);
	}
	get_z(x, y, z0, z1, s);
}
