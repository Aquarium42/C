#pragma once
#include<algorithm>
#include<vector>
using namespace std;
struct Vertex {
	double x;
	double y;
};
class graph_ {
public:
	graph_(int n);
	double weigth(int left, int right)const;
	int get_vertex_size() const;
	pair <double, pair<int, int> > get_edge(int i)const;
	void add_edge(int i, int j);
	void add_vertex( double x, double y);
	int get_edge_size() const;
private:
	vector<Vertex> graphself;
	vector <pair <double, pair<int, int> > > edges;
	int n, time, index =  0;
};
