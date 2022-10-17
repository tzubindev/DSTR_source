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
	lst.showForward();
}