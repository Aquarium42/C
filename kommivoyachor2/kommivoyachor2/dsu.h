#pragma once
#include<vector>
class dsu {
public:
	void make_set(int vertex, std::vector<int>& parent, std::vector<int>& size);
	int find_set(int vertex, std::vector <int>& parent);
	void union_sets(int one, int two, std::vector<int>&parent, std::vector <int>& size);
};
	