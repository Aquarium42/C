#pragma once
#include<vector>
#include"graph.h"
using namespace std;

class finder_ways {
public:
	void find_ways(const graph_& g, double& my_way, double& real_way) const;
private:
		double find_way(const graph_& g) const ;
		double find_real_way( const graph_& g) const;
		void build_ostov_tree(int n, const graph_ & g, vector <vector<int> >& next_vertex) const;
		void make_odd_vertex(vector <int>& count, const graph_ & g, vector<vector<int> >& next_vertex) const;
		void pre_order(int vertex, vector <int>& path, vector <bool>& color, vector<vector<int> >&const next_vertex) const;
		
};