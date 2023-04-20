#pragma once
#include <vector>

struct _pair {
	int first; // вершина 
	int second; // вес
};

class graph
{
	int** matr;
	int v_count;
public:
	graph(int n);
	~graph();
	int getsize();
	void insert(int v, int w, int weight);
	void remove(int v, int w);
	void clear();
	std::vector<std::pair<int, int>> create_list_vertices(int v);
	void print();
	bool loop_factor(int v, std::vector<bool>& used);
	bool loop_search(int v);
	void show(int v);
	int getm(int f, int s);
};

