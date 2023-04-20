#include <iostream>
#include "graph.h"
#include <vector>
#include <queue>
#include <stack>

using std::queue;
using std::stack;
using std::vector;
using std::pair;

graph::graph(int n)
{
	v_count = n;
	matr = new int* [v_count];
	for (int i = 0; i < v_count; ++i)
		matr[i] = new int[v_count];
	for (int i = 0; i < v_count; ++i)
		for (int j = 0; j < v_count; ++j)
			matr[i][j] = 0;
}

graph::~graph()
{
	for (int i = 0; i < v_count; ++i)
		delete[] matr[i];
	delete[] matr;
}

int graph::getsize()
{
	return v_count;
}

void graph::insert(int v, int w, int weight)
{
	if (v > v_count or w > v_count)
		return;
	matr[v][w] = weight;
	matr[w][v] = weight;
}

void graph::remove(int v, int w)
{
	if (v > v_count or w > v_count)
		return;
	matr[v][w] = 0;
	matr[w][v] = 0;
}

void graph::clear()
{
	for (int i = 0; i < v_count; ++i)
		for (int j = 0; j < v_count; ++j) {
			matr[i][j] = 0;
			matr[j][i] = 0;
		}
}

std::vector<pair<int, int>> graph::create_list_vertices(int v)
{
	std::vector<pair<int, int>> vec;
	if (v > v_count) return vec;
	for (int i = 0; i < v_count; ++i)
		if (matr[v][i] != 0) {
			pair<int, int> p;
			p.first = i;
			p.second = matr[v][i];
			vec.push_back(p);
		}
	return vec;
}

void graph::print()
{
	std::cout << "v:";
	for (int i = 0; i < v_count; ++i)
		std::cout << "[" << i << "]";
	std::cout << '\n';
	for (int i = 0; i < v_count; ++i) {
		std::cout << "[" << i << "]";
		for (int j = 0; j < v_count; ++j)
			std::cout << matr[i][j] << ' ' << ' ';
		std::cout << '\n';
	}
}
//поиск цикла в неоргафе
bool graph::loop_factor(int v, vector<bool>& used)
{
	used[v] = 1;
	vector<pair<int, int>> vec = this->create_list_vertices(v);
	//vec.erase(vec.begin());
	for (auto& vertex : vec) {
		int _ = vertex.first;
		if (!used[_]) {
			return loop_factor(_, used);
		}
		else {
			return 1;
		}
	}
	return 0;
}

bool graph::loop_search(int v)
{
	vector<bool> used;
	used.resize(v_count);
	int prev = -1;
	return loop_factor(v, used);
}

void graph::show(int v)
{
	auto vec = create_list_vertices(v);
	for (auto& it : vec)
		std::cout << it.first << ' ';
}



void DFS_rec(graph*& g, int vertex, vector<bool>& isVisited) {
	std::cout << vertex << "\n";
	isVisited[vertex] = 1;

	vector<pair<int, int>> av = g->create_list_vertices(vertex);
	for (auto& v : av)
	{
		int currentVertex = v.first;
		if (!isVisited[currentVertex])
			DFS_rec(g, currentVertex, isVisited);
	}
}

void DFS_rec(graph*& g, int vertex) {
	vector<bool> isVisited(g->getsize());
	DFS_rec(g, vertex, isVisited);
}

int graph::getm(int f, int s) {
	return matr[f][s];
}