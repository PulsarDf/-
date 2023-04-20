#include <cstring>
#include <iostream>
#include "graph.h"
#define INF 9999999


int main() {
    const int V = 6;
    graph G(V);
    G.insert(0, 1, 6);
    G.insert(0, 2, 1);
    G.insert(0, 3,5 );
    G.insert(1, 2, 5);
    G.insert(1, 4, 3);
    G.insert(2, 3, 5);
    G.insert(2, 4, 6);
    G.insert(2, 5, 4);
    G.insert(3, 5, 2);
    G.insert(4, 5, 6);
    int no_edge;            // номер ребра

    // создаем массив для отслеживания выбранной вершины
    // выбранное станет истинным, иначе ложным
    int selected[V];

    // заполнение массива нулями
    memset(selected, false, sizeof(selected));

    // установить количество ребер равным 0
    no_edge = 0;

    // количество egde в минимальном связующем дереве будет
    // всегда меньше (V -1), где V — количество вершин в графе

// выбираем 0-ю вершину и делаем ее истинной
    selected[0] = true;

    int x;            // номер строки
    int y;            // номер столбц

    // печать для ребра и веса
    std::cout << "Edge" << " : " << "Weight";
    std::cout << std::endl;
    int minosttree = 0;
    while (no_edge < V - 1) {

        //Для каждой вершины множества S найти все смежные вершины,рассчитаем расстояние от вершины, выбранной на шаге 1.
        // если вершина уже есть в множестве S, в противном случае отбрасываем ее
        //выбираем другую вершину, ближайшую к выбранной вершине на шаге 1.

        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G.getm(i, j)) { // не в выделенном и есть ребро
                        if (min > G.getm(i,j)) {
                            min = G.getm(i, j);
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        std::cout << x+1 << " - " << y+1 << " :  " << G.getm(x,y);
        minosttree += G.getm(x, y);
       std:: cout << std::endl;
        selected[y] = true;
        no_edge++;
    }
    std::cout << minosttree;

    return 0;
}