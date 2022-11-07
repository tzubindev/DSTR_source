# include <iostream>
using namespace std;

template <class T>
class Queue 
{
    T* arr;
    T Data;


public:
    /*Queue(int size = SIZE);*/

    int capacity, front, rear, count;
 

    Queue(int size = 100)
    {
        if (size <= 0) {
            cout << "Queue size should be positive number.\n";
            abort();
        }
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }


    bool isFull()
    {
        return (size() == capacity);
    }

    bool isEmpty()
    {
        return (size() == 0);
    }

    int size() {
        return count;
    }

    void enqueue (T elem) {
        if (count < capacity) {
           // cout << "Inserting " << elem << endl;
            rear = (rear + 1) % capacity;
            arr[rear] = elem;
            count++; 
        }
        else {
            cout << "Queue is full!" << endl;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            abort();
        }
        int frontIndex = front;
        front = (front + 1) % capacity;
        count--;
        return arr[frontIndex];
    }

    T peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }

    void show() {
        if (!isEmpty()) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << "\t" << endl;
            }
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }

    int first()
    {
        return (!isEmpty()) ? arr[front] : -1;
    }

    int last()
    {
        return (!isEmpty()) ? arr[rear] : -1;
    }
};