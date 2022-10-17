#pragma once
#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int Test()
{
	DoublyLinkedList<int> lst;

	lst.insertAtbeginning(22);
	lst.insertAtbeginning(33);
	lst.insertAtbeginning(44);
	lst.deleteItemAt(1);
	lst.deleteFirst();
	lst.getSize();
	lst.showForward();
	return 1;
}