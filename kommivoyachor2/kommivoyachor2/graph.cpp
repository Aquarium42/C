#include"stdafx.h"
#include "graph.h"

double graph_::weigth(int left, int right)const {
	return sqrt(pow(graphself[left].x - graphself[right].x, 2) + pow(graphself[left].y - graphself[right].y, 2));
}
int graph_::get_vertex_size() const {
	return n;
}

graph_::graph_(int n_) {
	n = n_;
	graphself.resize(n_);
}
void graph_::build_edges() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			add_edge(i, j);
		}
	}
	sort_edges();
}


pair <double, pair<int, int> > graph_::get_edge(int i) const {
	return edges[i];
}

int graph_::get_edge_size() const {
	return edges.size();
}
void graph_::add_edge(int i, int j) {
	edges.push_back(make_pair(weigth(i, j), make_pair(i, j)));
}
void graph_::sort_edges() {
	sort(edges.begin(), edges.end());
}
void graph_::add_vertex(double x, double y) {
	Vertex v;
	v.x = x;
	v.y = y;
	graphself[index] = v;
	index++;
}

