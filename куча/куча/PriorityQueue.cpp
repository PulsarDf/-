#include "PriorityQueue.h"

    // вернуть родителя `A[i]`
    // не вызывайте эту функцию, если `i` уже является корневым узлом
    int PriorityQueue::PARENT(int i) {
        return (i - 1) / 2;
    }

    // вернуть левого потомка `A[i]`
    int PriorityQueue::LEFT(int i) {
        return (2 * i + 1);
    }

    // вернуть правого потомка `A[i]`
    int PriorityQueue::RIGHT(int i) {
        return (2 * i + 2);
    }

    // Рекурсивный алгоритм shift_down.
    // Узел с индексом `i` и два его прямых потомка
    // нарушает свойство кучи
    void PriorityQueue::shift_down(int i)
    {
        // получить левый и правый потомки узла с индексом `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // сравниваем `A[i]` с его левым и правым дочерними элементами
        // и находим наибольшее значение
        if ((left < size()) && (A[left] > A[i])) {
            largest = left;
        }

        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }

        // поменяться местами с потомком, имеющим большее значение и
        // вызовите shift-down для дочернего элемента
        if (largest != i)
        {
            swap(A[i], A[largest]);
            shift_down(largest);
        }
    }

    // Рекурсивный алгоритм shift_up
    void PriorityQueue::shift_up(int i)
    {
        // проверяем, не нарушают ли узел с индексом `i` и его родитель свойство кучи
        if (i && A[PARENT(i)] < A[i])
        {
            // поменять их местами, если свойство кучи нарушено
            swap(A[i], A[PARENT(i)]);

            // вызываем heapify-up для родителя
            shift_up(PARENT(i));
        }
    }

    // возвращаем размер кучи
    unsigned int PriorityQueue::size() {
        return A.size();
    }

    // Функция для проверки, пуста ли куча или нет
    bool PriorityQueue::empty() {
        return size() == 0;
    }

    // вставляем слово в кучу
    void PriorityQueue::push(int key)
    {
        // вставляем новый элемент в конец вектора
        A.push_back(key);

        // получаем индекс элемента и вызываем процедуру shift-up
        int index = size() - 1;
        shift_up(index);
    }

    // Функция для удаления элемента с наивысшим приоритетом (присутствует в корне)
    void PriorityQueue::pop()
    {
            // если в куче нет элементов, выбрасываем исключение
            if (size() == 0)
            {
                cout << "No elements" << "\n";
            }
            else {
                // заменяем корень кучи последним элементом
                // вектора
                A[0] = A.back();
                A.pop_back();

                // вызовите shift-down на корневом узле
                shift_down(0);
            }
        
    }

    // Функция для возврата элемента с наивысшим приоритетом (присутствует в корне)
    int PriorityQueue::top()
    {
            // если в куче нет элементов, выбрасываем исключение
        if (size() == 0)
            cout << "No elements";
            else
            // иначе возвращаем верхний (первый) элемент
            return A.front();//или A[0],но front красиво выглядит
    }
    //констуктор кучи
    PriorityQueue::PriorityQueue(int x) 
    {
        A.resize(0);
    }
    //деструктор кучи
    PriorityQueue::~PriorityQueue()
    {
        clear();
    }
    // очистка кучи
    void PriorityQueue::clear()
    {
        A.clear();
    }
    //вывод ввиде массива
    void PriorityQueue::printAsArray()
    {
        for (int i = 0; i < size(); i++)
        {
            cout << A[i] << ' ';
        }
    }
    //вывод ввиде дерева
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