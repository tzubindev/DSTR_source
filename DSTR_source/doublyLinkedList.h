# include <iostream>
using namespace std;

template<class T>
class DoublyNode
{
public:
    T data;
    DoublyNode<T>* prev;
    DoublyNode<T>* next;
    DoublyNode<T>* down;

    DoublyNode() {
        prev = nullptr;
        next = nullptr;
        down = NULL;
    }
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

    void insertAtBeginning(T elem)
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
        DoublyNode<T>* newNode = new DoublyNode<T>();
        newNode->data = elem;
        newNode->next = NULL;
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
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

    // Dont change
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

        while (cur != NULL) {
            if (index == cnt) {
                break;
            }
            else {
                cur = cur->next;
                cnt++;
            }
        }
        while (cur != NULL) {
            if (cur->down == NULL) {
                cur->down = newNode;
                break;
            }
            else {
                cur = cur->down;
            }
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

    // Dont change
    T getItem(int x) {
        DoublyNode<T>* curNode = head;
        int cnt = 0;

        if (x >= size) {
            cout << "Out of range: get item\n";
        }

        while (curNode != NULL) {
            if (cnt == x) {
                return curNode->data;
            }
            else {
                curNode = curNode->next;
                cnt++;
            }
        }
    }

    T getItem(int x, int y) {
        DoublyNode<T>* curNode = head;
        int cnt = 0;

        if (x >= size || y >= height) {
            cout << "Out of range in get item\n";
        }

        while (curNode != NULL) {
            if (cnt == x) {
                break;
            }
            else {
                curNode = curNode->next;
                cnt++;
            }
        }

        cnt = 0;
        while (curNode != NULL) {
            if (cnt == y) {
                return curNode->data;
            }
            else {
                curNode = curNode->down;
                cnt++;
            }
        }

    }


    void deleteFirst() {

       if (head != NULL){
           DoublyNode<T>* toDeleteNode = head;

           if (head->next != NULL) head = head->next;
           else head = NULL;
           delete toDeleteNode;
           if (head != NULL)
               head->prev = NULL;
           size--;
       }
       else {
           cout << "The head is null\n";
       }
    }

    void deleteLast() {
        DoublyNode<T>* toDeleteNode = tail;

        if (head == NULL) {
            abort();
        }
        else if (head->next == NULL) {
            head = NULL;
            delete(head);
        }else {
            toDeleteNode = tail;
            tail = tail->prev;
            toDeleteNode->prev->next = NULL;
        }
        
        delete toDeleteNode;
        size--;
        
    }

    void deleteItemAt(int index) {
        if (index <= 0 || index >= size) {
            cout << "\n Wrong Index\n";
            abort();
        }
        
		DoublyNode<T>* temp = head;
		for (int i = 0; i < index; i++) {
			if (temp != NULL) {
				temp = temp->next;
			}
		}

        // A B C
        // if A !NULL AND C !NULL
        // del = B
        // A->next = A->next->next(C)
        // so A->next = C
        // A->next(C)->prev(B) = A (changed)
		if (temp != NULL && temp->next->next != NULL) {
			DoublyNode<T>* nodeToDelete = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			delete nodeToDelete;
            size--;
		}
		else {
			cout << "\nThe node is already null.";
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

