# include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T username;
    T password;
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
        cout << "--- Constructing the Doubly LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtbeginning(T elem)
    {
        cout << "Inserting = " << elem << endl;
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->prev = nullptr;
        newNode->data = elem;

        if (head == NULL) {
            newNode->next = nullptr;
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            this->head = newNode;
        }

        size++;
    }

    // update this
    void insertAtEnd(T username, T password)
    {
        cout << "Inserting = " << elem << endl;
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->prev->next = newNode;
        }
        size++;
    }

    
    void insertItemAt(T username, T password, int index)
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


    // Need this
    T getItem(int index) {
        
    }

    
    void deleteFirst() {

    }

    void deleteLast() {

    }

    void deleteItemAt(int index) {

    }
};

