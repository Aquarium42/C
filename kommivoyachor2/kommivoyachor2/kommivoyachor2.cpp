// kommivoyachor2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include"find_ways.h"
#include<random>
#include "Solvers.h"
using namespace std;
void write_array(vector<double>& const arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n, count_test;
	cin >> n>> count_test;
	Solver_for_one_parameter one_parameter(n, count_test);
	Solver_for_many_parameters some_parameters(2, 7, count_test);
	cout<<"one_parameter average "<<one_parameter.get_average_deviation()<<endl;
	cout << "one_parameter mean square " << one_parameter.get_mean_square()<<endl;
	vector<double> averages_some;
	vector<double> mean_squares_some;
	some_parameters.get_averages(averages_some);
	some_parameters.get_mean_squares(mean_squares_some);
	
	cout << "some_parameters" << endl;
	write_array(averages_some);
	write_array(mean_squares_some);
	return 0;
}