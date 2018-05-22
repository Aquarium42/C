#include"stdafx.h"
#include "dsu.h"
#include<vector>
#include<iostream>
void dsu::make_set(int vertex, std::vector<int>& parent, std::vector<int>& size) {
	size[vertex] = 1;
	parent[vertex] = vertex;
}

int dsu::find_set(int vertex, std::vector <int>& parent) {
	if (vertex == parent[vertex]) {
		return vertex;
	}
	return parent[vertex] = find_set(parent[vertex], parent);
}

void dsu::union_sets(int one, int two, std::vector<int>&parent, std::vector <int>& size) {
	one = find_set(one, parent);
	two = find_set(two, parent);
	if (one != two) {
		if (size[one] < size[two]) {
			std::swap(one, two);
		}
		parent[two] = one;
		size[one] += size[two];
	}
}
