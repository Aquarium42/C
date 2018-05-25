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
	void add_edge(int i, int j);//чисто для более общего интерфейса сделан публичным.
	//А в рамках этой задачи нам в любом случае надо добавить все возможные комбинации ребер, поэтому смысла делать это от имени пользователя нет. 
	//Пользователь должен добавлять  именно вершины с определенными координатами
	void add_vertex( double x, double y);
	void build_edges();//соединяет все добавленные вершины ребрами.
	int get_edge_size() const;
private:
	void sort_edges();
	vector<Vertex> graphself;
	vector <pair <double, pair<int, int> > > edges;
	int n, time, index =  0;
};
