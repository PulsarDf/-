#include "PriorityQueue.h"

int main()
{
    PriorityQueue pq(1);

    // Примечание: значение элемента определяет приоритет

    pq.push(3);
    pq.push(2);
    pq.push(15);
    pq.printAsArray();
    cout << "\n";
    pq.printAsTree(1,1);
    cout << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    pq.push(5);
    pq.push(4);
    pq.push(45);

    cout << endl << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();
    
    cout << endl << boolalpha << pq.empty();

    pq.top();    // верхняя операция над пустой кучей
    pq.pop();    // операция извлечения из пустой кучи

    return 0;
}