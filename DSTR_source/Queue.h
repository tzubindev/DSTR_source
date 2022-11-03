# include <iostream>
using namespace std;

#define SIZE 100

template <class T>
class Queue 
{
    T* arr;


public:
    /*Queue(int size = SIZE);*/

    int capacity, front, rear, count;
 

    Queue(int size)
    {
        arr = new T[size];
        capacity = size;
        front = rear = -1;
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
        if (rear != capacity-1) {
            cout << "Inserting " << elem << endl;
            if (front == -1 && rear == -1) {
                front++;
                arr[++rear] = elem;
            }
            else {
                arr[++rear] = elem;
            }
        }
        else {
            cout << "Queue is full!" << endl;
        }
    }

    void dequeue() {
        if (front != -1 && rear != -1 && front <= rear) {
            cout << "Removing " << arr[front] << endl;
            front = (front + 1) % capacity;
            count--;
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }

    T peek() {
        if (front != -1 && rear != -1 && front <= rear) {
            return arr[front];
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }

    void show() {
        if (front != -1 && rear != -1 && front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << capacity[i] << "t" << endl;
            }
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }
};