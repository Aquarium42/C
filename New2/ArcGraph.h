#pragma once
#include <vector>
#include "Graph.h"
class CArcGraph : public IGraph {
public:
	CArcGraph (int vertex_count);
	void AddEdge(int from, int to) override;
	CArcGraph (const IGraph* obj);
	int VerticesCount() const override;
	void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
	std::vector< std::vector<int> > graph;
	int count;
};