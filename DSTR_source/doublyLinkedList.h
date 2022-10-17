# include <iostream>
using namespace std;

template<class T>
class DoublyNode
{
public:
    T data;
    DoublyNode<T>* prev = nullptr;
    DoublyNode<T>* next = nullptr;
};

template<class T>
class DoublyLinkedList
{
public:

    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    int size;

    DoublyLinkedList()
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

    void insertAtEnd(T elem)
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

    T getItem(int index) {

    }

    void deleteFirst() {

       if (head != Null){
           DoublyNode* toDeleteNode = head;

           head = head->next;
           free(toDeleteNode);

           if(head != NULL)
               head->prev = NULL;
       }
    }

    void deleteLast() {
        DoublyNode* toDeleteNode = tail;

        if (toDeleteNode->prev != nullptr) {
            toDeleteNode->prev->next = nullptr;
            tail = tail->prev;
        }
        
        del toDeleteNode;
        
    }

    void deleteItemAt(struct DoublyNode** head_ref,int index) {
        if (*head_ref == NULL || index <= 0)
            return;

        struct DoublyNode* curr = *head_ref;

        int i;

        for (int i = 1; current != NULL && i < index; i++) {
            curr = curr -> next
        }

        if(curr == NULL)
            return;

        del head_ref, curr;
    }

    void clear() {
        while (head != NULL) deleteLast();

        cout << "The Doubly Linked List is cleared.\n ";
    }

    void showForward()
    {
        DoublyNode<T>* curr = head;
        cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " " << curr << " " << curr->next << '\n';
            curr = curr->next;

        }
    } // ignore

    void showBackward()
    {
        DoublyNode<T>* curr = tail;
        cout << "\n--- DISPLAY LINKED LIST [BACKWARD] = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
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

