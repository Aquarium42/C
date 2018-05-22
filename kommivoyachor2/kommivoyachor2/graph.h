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
	double weigth(Vertex left, Vertex right) const;
	int get_size() const;
	void get_edges(vector <pair <double, pair<int, int> > >& p)const;
	Vertex get_graph_self(int p) const;
	pair <double, pair<int, int> > get_edge(int i)const;
	int get_edge_size() const;
	void add_edge(int i, int j);
	void sort_edges();
	void resize(int n_);
	void set_vertex(int to, Vertex vertex);
	private:
	vector<Vertex> graphself;
	vector <pair <double, pair<int, int> > > edges;
	int n, time;
};
