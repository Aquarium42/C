// New2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include<memory>


// Graph.cpp: определяет точку входа для консольного приложения.
//
#include "MatrixGraph.h"
#include <iostream>
std::unique_ptr<IGraph> createGraph() {
	return std::make_unique<CMatrixGraph>(9);
}

int main() {
	std::unique_ptr<IGraph> graph = createGraph();
	graph->AddEdge(3, 0);
	graph->AddEdge(3, 1);
	graph->AddEdge(1, 3);
	graph->AddEdge(1, 4);
	graph->AddEdge(4, 5);
	graph->AddEdge(5, 6);
	graph->AddEdge(6, 0);
	graph->AddEdge(1, 2);
	graph->AddEdge(0, 6);
	std::vector<int> v;
	graph->GetNextVertices(0, v);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> u;
	graph->GetPrevVertices(0, u);
	for (int i = 0; i < u.size(); i++) {
		std::cout << u[i] << " ";
	}
	std::cout << std::endl;
	std::cout << graph->VerticesCount();
	return 0;
}

