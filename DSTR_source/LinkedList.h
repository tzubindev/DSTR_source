# include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template<class T>
class LinkedList
{
public:

    Node<T>* head;
    int size;

    LinkedList()
    {
        cout << "--- Constructing the LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
    }

    void insertAtbeginning(T elem)
    {

        Node<T>* newNode = new Node<T>;
        newNode->data = elem;
        if (head == NULL) {
            head = newNode;
            cout << "Inserting = " << elem << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Inserting = " << elem << endl;

    }

    // update this
    void insertAtEnd(T elem)
    {
        cout << "Inserting = " << elem << endl;
        Node<T>* newNode = new Node<T>;
        newNode->data = elem;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* last = head;
            while (last->next != nullptr)
                last = last->next;
            last->next = newNode;
        }
        size++;
    }


    void insertItemAt(T elem, int index)
    {
        if (index >= size)
        {
            cout << "Out of Range\n";
            abort();
        }

        cout << "Inserting = " << elem << endl;

        DoublyNode<T>* newNode = new DoublyNode<T>;
        DoublyNode<T>* cur = this->head;

        newNode->data = elem;

        while (index != 0 && cur->next != NULL) {
            cur = cur->next;
        }

        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;

        size++;

    }

    int getSize()
    {
        return size;
    }


    // Ghassan
    T getItem(int index) {

        Node<T>* cur = head;

        int count = 0;

        while (cur != NULL) {
            if (count == index)
                return (cur->data);
            count++;
            cur = cur->next;
        }
        return -1;
    }


    void deleteFirst() {

    }

    void deleteLast() {

    }

    void deleteItemAt(int index) {

    }
};
