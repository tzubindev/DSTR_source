# include <iostream>
using namespace std;

template<class T>
class DoublyNode
{
public:
    T data;
    DoublyNode<T>* prev = nullptr;
    DoublyNode<T>* next = nullptr;
    DoublyNode<T>* down = nullptr;
};

template<class T>
class DoublyLinkedList
{
public:

    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    int size, height;

    DoublyLinkedList()
    {
        this->size = 0;
        this->height = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtbeginning(T elem)
    {
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

    void insertAtEnd(T elem)
    {
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->next = NULL;
        newNode->prev = tail;
        tail = newNode;
        if (head == NULL)
            head = newNode;
        else
            newNode->prev->next = newNode;
        size++;
    }

    void insertItemAt(T elem, int index)
    {
        if (index >= size)
        {
            cout << "Out of Range\n";
            abort();
        }

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

    void insertVerticallyAt(T elem, int index) {
        if (index >= size)
        {
            cout << "Out of range\n";
            abort();
            
        }

        DoublyNode<T>* newNode = new DoublyNode<T>;
        DoublyNode<T>* cur = this->head;
        int cnt = 0;

        newNode->data = elem;

        while (cur->next != NULL) {
            if (index == cnt) {
                cnt = 0;
                while (cur->down != NULL) {
                    cur = cur->down;
                    cnt++;
                }
                cur->down = newNode;
                return;
            }

            cur = cur->next;
            cnt++;
        }
    }

    int getSize()
    {
        return size;
    }

    void setHeight(int i) {
        height = i;
    }

    int getHeight() {
        return height;
    }

    T getItem(int index, int Vindex) {
        DoublyNode<T>* curNode = head;
        int count = 0;

        if (index >= size) {
            cout << "Out of range in get item\n";
        }

        while (curNode != NULL) {
            if (count == index) {
                count = 0;
                while (curNode->down != NULL) {

                    if (count == Vindex) {
                        return curNode->data;
                    }
                    curNode = curNode->down;
                }

                // Exception
                cout << "Not found in get item.\n";
                break;
            }
            else {
                curNode = curNode->next;
                count++;
            }
        }
    }


    void deleteFirst() {

       if (head != NULL){
           DoublyNode<T>* toDeleteNode = head;

           head = head->next;
           free(toDeleteNode);

           if(head != NULL)
               head->prev = NULL;
       }
    }

    void deleteLast() {
        DoublyNode<T>* toDeleteNode = tail;

        if (head == NULL) {
            abort();
        }
        else if (head->next == NULL) {
            head = NULL;
            free(head);
        }else {
            toDeleteNode = tail;
            tail = tail->prev;
            toDeleteNode->prev->next = NULL;
        }
        
        delete toDeleteNode;
        
    }

    void deleteItemAt(int index) {
        if (index < 0) {
            cout << "\nindex should be >= 0.";
        }
        else if (index == 0 && head != NULL) {
            DoublyNode<T>* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            if (head != NULL)
                head->prev = NULL;
        }
        else if (index == size-1) {
            DoublyNode<T> * nodeToDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete nodeToDelete;
        }
        else {
            DoublyNode<T>* temp = head;
            for (int i = 0; i < index - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }
            if (temp != NULL && temp->next != NULL) {
                DoublyNode<T>* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                if (temp->next->next != NULL)
                    temp->next->next->prev = temp->next;
                delete nodeToDelete;
            }
            else {
                cout << "\nThe node is already null.";
            }
        }
    }

    void clear() {
        while (head != NULL) deleteLast();
    }

    void showForward()
    {

    } // ignore

    void showBackward()
    {

    } // ignore

    void sort()
    {
        DoublyNode<T>* curr = head;
        DoublyNode<T>* temp = nullptr;

        while (curr->next != NULL) {

            // if next node value > cur node value, swap


        }

        // check

    }
};

