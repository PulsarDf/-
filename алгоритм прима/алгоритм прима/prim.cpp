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
    int no_edge;            // ����� �����

    // ������� ������ ��� ������������ ��������� �������
    // ��������� ������ ��������, ����� ������
    int selected[V];

    // ���������� ������� ������
    memset(selected, false, sizeof(selected));

    // ���������� ���������� ����� ������ 0
    no_edge = 0;

    // ���������� egde � ����������� ��������� ������ �����
    // ������ ������ (V -1), ��� V � ���������� ������ � �����

// �������� 0-� ������� � ������ �� ��������
    selected[0] = true;

    int x;            // ����� ������
    int y;            // ����� ������

    // ������ ��� ����� � ����
    std::cout << "Edge" << " : " << "Weight";
    std::cout << std::endl;
    int minosttree = 0;
    while (no_edge < V - 1) {

        //��� ������ ������� ��������� S ����� ��� ������� �������,���������� ���������� �� �������, ��������� �� ���� 1.
        // ���� ������� ��� ���� � ��������� S, � ��������� ������ ����������� ��
        //�������� ������ �������, ��������� � ��������� ������� �� ���� 1.

        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G.getm(i, j)) { // �� � ���������� � ���� �����
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