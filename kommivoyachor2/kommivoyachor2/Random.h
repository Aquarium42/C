#pragma once
	namespace random_{
	double get_random(int t);
	double get_s(double& const x, double& const y);
	void get_z(double& const x, double& const y, double& z0, double &z1, double& const s);
	void take_random(double& z0, double& z1, int& time);
	}