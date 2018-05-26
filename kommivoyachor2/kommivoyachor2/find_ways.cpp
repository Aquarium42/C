#include"stdafx.h"
#include <iostream>
#include<vector>
#include "dsu.h"
#include "find_ways.h"
using namespace std;

void finder_ways::make_odd_vertex( vector <int>& count, const graph_ & g, vector<vector<int> >& next_vertex) const {
	vector<int> odd;//нечетные вершины
	for (int i = 0; i < g.get_vertex_size(); i++) {
		if (count[i] % 2 != 0) {
			odd.push_back(i);
		}
	}
	vector <pair <double, pair<int, int> > > new_edges;
	for (int i = 0; i < odd.size(); i++) {
		for (int j = i + 1; j < odd.size(); j++) {
			new_edges.push_back(make_pair(g.weigth(odd[i], odd[j]), make_pair(odd[i], odd[j])));
		}
	}
	//у нас все новые вершины теперь есть в new_edges. Мы хотим там построить минимальное паросочетание. Полученные пары будут добавочными ебрами.

	sort(new_edges.begin(), new_edges.end());//отсортировали по весу, чтобы объединять пары.
	for (int i = 0; i < new_edges.size(); i++) {
		if (count[new_edges[i].second.first] != -1 && count[new_edges[i].second.second] != -1) {
			next_vertex[new_edges[i].second.first].push_back(new_edges[i].second.second);
			next_vertex[new_edges[i].second.second].push_back(new_edges[i].second.first);
			count[new_edges[i].second.first] = -1;
			count[new_edges[i].second.second] = -1;
		}
	}
}

void finder_ways::pre_order(int vertex, vector <int>& path, vector <bool>& color, vector<vector<int> >&const next_vertex) const{
	color[vertex] = 1;
	path.push_back(vertex);
	for (int i = 0; i < next_vertex[vertex].size(); i++) {
		if (color[next_vertex[vertex][i]] == false) {
			pre_order(next_vertex[vertex][i], path, color, next_vertex);
		}
	}
}

void finder_ways::build_ostov_tree(int n, const graph_ & g, vector <vector<int> >& next_vertex) const{
	vector <int> parent(n);
	vector<int> size(n);
	vector <pair <double, pair<int, int> > > my_edges;
	for (int i = 0; i < g.get_edge_size(); i++) {
		my_edges.push_back(g.get_edge(i));
	}
	sort(my_edges.begin(), my_edges.end());
	dsu dsu_;
	for (int i = 0; i < n; i++) {
		dsu_.make_set(i, parent, size);
	}
	for (int i = 0; i < my_edges.size(); i++) {
		if (dsu_.find_set(my_edges[i].second.first, parent) != dsu_.find_set(my_edges[i].second.second, parent)) {
			dsu_.union_sets(my_edges[i].second.first, my_edges[i].second.second, parent, size);
			next_vertex[my_edges[i].second.first].push_back(my_edges[i].second.second);
			next_vertex[my_edges[i].second.second].push_back(my_edges[i].second.first);
		}
	}
}
double finder_ways::find_way(const graph_& g) const
{
	double way = 0;
	int n = g.get_vertex_size();
	vector <vector<int> > next_vertex(n);
	build_ostov_tree(n, g, next_vertex);
	//получила осовное дерево в виде ребер. Теперь нужно найти все вершины нечетной степени и соединить их.
	vector <int>count(n); // показывает четности вершин
	for (int i = 0; i < next_vertex.size(); i++) {
		for (int j = 0; j < next_vertex[i].size(); j++) {
			count[next_vertex[i][j]]++;
		}
	}
	make_odd_vertex(count, g, next_vertex);
	vector<bool> color(n);
	vector<int> path;
	pre_order(0, path, color, next_vertex);
	for (int i = 0; i < path.size(); i++) {
		if (i != path.size() - 1) {
			way += g.weigth(path[i], path[i + 1]);
		}
	}
	return way;
}
double finder_ways::find_real_way(const graph_& g) const
{
	int n = g.get_vertex_size();
	double min_way = _MAX_INT_DIG;
	double way = 0;
	vector<int> index(n);
	for (int i = 0; i < n; i++) {
		index[i] = i;
	}
	do {
		way = 0;
		for (int i = 0; i < index.size() -1; i++) {
			way = way + g.weigth(index[i], index[i + 1]);
		}
		if (min_way > way) {
			min_way = way;
		}

	} while (next_permutation(index.begin(), index.end()));
	return min_way;
}

void finder_ways::find_ways(const graph_ &graphself,  double& my_way, double& real_way) const {

	my_way = find_way( graphself);
	real_way = find_real_way(graphself);
}