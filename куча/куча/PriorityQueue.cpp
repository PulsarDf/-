#include "PriorityQueue.h"

    // ������� �������� `A[i]`
    // �� ��������� ��� �������, ���� `i` ��� �������� �������� �����
    int PriorityQueue::PARENT(int i) {
        return (i - 1) / 2;
    }

    // ������� ������ ������� `A[i]`
    int PriorityQueue::LEFT(int i) {
        return (2 * i + 1);
    }

    // ������� ������� ������� `A[i]`
    int PriorityQueue::RIGHT(int i) {
        return (2 * i + 2);
    }

    // ����������� �������� shift_down.
    // ���� � �������� `i` � ��� ��� ������ �������
    // �������� �������� ����
    void PriorityQueue::shift_down(int i)
    {
        // �������� ����� � ������ ������� ���� � �������� `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // ���������� `A[i]` � ��� ����� � ������ ��������� ����������
        // � ������� ���������� ��������
        if ((left < size()) && (A[left] > A[i])) {
            largest = left;
        }

        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }

        // ���������� ������� � ��������, ������� ������� �������� �
        // �������� shift-down ��� ��������� ��������
        if (largest != i)
        {
            swap(A[i], A[largest]);
            shift_down(largest);
        }
    }

    // ����������� �������� shift_up
    void PriorityQueue::shift_up(int i)
    {
        // ���������, �� �������� �� ���� � �������� `i` � ��� �������� �������� ����
        if (i && A[PARENT(i)] < A[i])
        {
            // �������� �� �������, ���� �������� ���� ��������
            swap(A[i], A[PARENT(i)]);

            // �������� heapify-up ��� ��������
            shift_up(PARENT(i));
        }
    }

    // ���������� ������ ����
    unsigned int PriorityQueue::size() {
        return A.size();
    }

    // ������� ��� ��������, ����� �� ���� ��� ���
    bool PriorityQueue::empty() {
        return size() == 0;
    }

    // ��������� ����� � ����
    void PriorityQueue::push(int key)
    {
        // ��������� ����� ������� � ����� �������
        A.push_back(key);

        // �������� ������ �������� � �������� ��������� shift-up
        int index = size() - 1;
        shift_up(index);
    }

    // ������� ��� �������� �������� � ��������� ����������� (������������ � �����)
    void PriorityQueue::pop()
    {
            // ���� � ���� ��� ���������, ����������� ����������
            if (size() == 0)
            {
                cout << "No elements" << "\n";
            }
            else {
                // �������� ������ ���� ��������� ���������
                // �������
                A[0] = A.back();
                A.pop_back();

                // �������� shift-down �� �������� ����
                shift_down(0);
            }
        
    }

    // ������� ��� �������� �������� � ��������� ����������� (������������ � �����)
    int PriorityQueue::top()
    {
            // ���� � ���� ��� ���������, ����������� ����������
        if (size() == 0)
            cout << "No elements";
            else
            // ����� ���������� ������� (������) �������
            return A.front();//��� A[0],�� front ������� ��������
    }
    //���������� ����
    PriorityQueue::PriorityQueue(int x) 
    {
        A.resize(0);
    }
    //���������� ����
    PriorityQueue::~PriorityQueue()
    {
        clear();
    }
    // ������� ����
    void PriorityQueue::clear()
    {
        A.clear();
    }
    //����� ����� �������
    void PriorityQueue::printAsArray()
    {
        for (int i = 0; i < size(); i++)
        {
            cout << A[i] << ' ';
        }
    }
    //����� ����� ������
    void PriorityQueue::printAsTree(int p,int level)
    {
        if (p - 1 < A.size()) 
        {
            printAsTree(p * 2 + 1, level + 1);
            for (int i = 0; i < level; i++)
                cout << "   ";
            cout << A[p - 1] << endl;
            printAsTree(p * 2, level + 1);
        }
    }