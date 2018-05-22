#include"stdafx.h"
#include "graph.h"

double graph_::weigth(Vertex left, Vertex right)const {
	return sqrt(pow(left.x - right.x, 2) + pow(left.y - right.y, 2));
}

int graph_::get_size() const {
	return n;
}

void graph_::get_edges(vector <pair <double, pair<int, int> > >& p) const{}

Vertex graph_::get_graph_self(int index) const {
	return graphself[index];
}

pair <double, pair<int, int> > graph_::get_edge(int i) const {
	return edges[i];
}

int graph_::get_edge_size() const {
	return edges.size();
}
void graph_::add_edge(int i, int j) {
	edges.push_back(make_pair(weigth(graphself[i], graphself[j]), make_pair(i, j)));
}
void graph_::sort_edges() {
	sort(edges.begin(), edges.end());

}
void graph_::set_vertex(int to, Vertex v) {
	graphself[to] = v;
}

void graph_::resize(int n_) {
	n = n_;
	graphself.resize(n_);
}
