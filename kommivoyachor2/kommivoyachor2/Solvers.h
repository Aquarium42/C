#pragma once
#include<vector>
#include"graph.h"
class Solver_for_one_parameter{
public:
	Solver_for_one_parameter(int n_, int count_test) {
		n = n_;
		count = count_test;
		mean_square = 0;
		calculate_metrics();
	}
	double get_average_deviation() const;
	double get_mean_square() const;
private:
	void calculate_metrics();
	std::vector<double> norms;
	int n, count, time;
	double average;
	double mean_square;
};
class Solver_for_many_parameters {
public:Solver_for_many_parameters(int a, int b, int count_test) {
		start = a;
		end = b;
		count = count_test;
	}
	   void find_solve();
	   void get_averages(std::vector<double>& averages);
	   void get_mean_squares(std::vector<double>& mean_squares);
private:
	std::vector<double>averages;
	std::vector<double> mean_squares;
	int start, end, count;
};

