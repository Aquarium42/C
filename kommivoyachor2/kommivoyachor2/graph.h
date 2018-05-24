#pragma once
#include<algorithm>
#include "Random.h"
#include<vector>
using namespace std;
struct Vertex {
	double x;
	double y;
};
class graph_ {
public:
	double weigth(int left, int right)const;
	int get_vertex_size() const;
	pair <double, pair<int, int> > get_edge(int i)const;
	void graph_init(int n_, int& time_);
	void add_edge(int i, int j);
	int get_edge_size() const;
	private:
		void sort_edges();
		void resize(int n_);
		void set_vertex(int to, Vertex vertex);
		vector<Vertex> graphself;
	vector <pair <double, pair<int, int> > > edges;
	int n, time;
};
