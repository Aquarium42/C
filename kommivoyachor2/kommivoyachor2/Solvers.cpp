#include"stdafx.h"
#include"Solvers.h"
#include<vector>
#include<iostream>
#include "find_ways.h"
using namespace std;

void Solver_for_one_parameter::calculate_metrics()
{
	double norma = 0;
	double average_norm = 0;
	int time = 1;
	for (int j = 0; j < count; j++) {
		finder_ways finder;
		graph_ g;
		double my_way, real_way;
		g.graph_init(n, time);
		finder.find_ways(g, my_way, real_way);
		time++;
		norms.push_back(my_way/real_way);
		average_norm += my_way / real_way;
		}
	average = average_norm / count;
	double average_way = get_average_deviation();
	for (int i = 0; i < norms.size(); i++) {
		mean_square += pow(norms[i] - average_way, 2);
	}
	mean_square = mean_square / norms.size();
	mean_square = sqrt(mean_square);


}

double Solver_for_one_parameter::get_average_deviation() const
{
	return average;
}
double Solver_for_one_parameter::get_mean_square() const
{
	return mean_square;
}

void Solver_for_many_parameters::find_solve() {
	for (int i = start; i < end; i++) {
		Solver_for_one_parameter test(i, count);
		averages.push_back(test.get_average_deviation());
		mean_squares.push_back(test.get_mean_square());
	}
}
void Solver_for_many_parameters::get_averages(vector<double>& averages_) {
	if (averages.empty()) {
		find_solve();
	}
	averages_ = averages;
}
void Solver_for_many_parameters::get_mean_squares(vector<double>& mean_squares_) {
	if (averages.empty()) {
		find_solve();
	}
	mean_squares_ = mean_squares;
}