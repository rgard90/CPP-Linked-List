#pragma once
#include "LinkedListInterface.h"
#include <sstream>

template <typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    int num_items = 0;
    struct Node {
        T data;
        Node* next;
        Node(T tInfo, Node* nextValue) {
        	data = tInfo;
            next = nextValue;
        }
        ~Node() {}
        
    };
    Node* head = NULL;
    Node* temp;
    
public:
    LinkedList(void) {};
    ~LinkedList(void) {};
    
    /*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
    
    void insertHead(T value) {
        if (head == NULL) {
			head = new Node(value, NULL);
			num_items++;
		}
		else {
			head = new Node(value, head);
			num_items++;
		}
    };

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
	    if (head == NULL) {
	        head = new Node(value, NULL);
	        num_items++;
	    }
	    else {
	        Node* listPtr = head;
	        while (listPtr->next != NULL) {
	            listPtr = listPtr->next;
	        }
	        listPtr->next = new Node(value, NULL);
	        num_items++;
	    }
	    
	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
	    bool duplicate = find(value);
	    if (duplicate != true) {
	        bool insrtPlace = find(insertionNode);
	        if (insrtPlace != true) {
	        	return;
	        }
	        if (head != NULL) {
	            Node* listPtr = head;
	            while (listPtr->data != insertionNode) {
	                listPtr = listPtr->next;
	            }
	            Node* newListPtr = listPtr;
	            listPtr = new Node(value, newListPtr->next);
	            newListPtr->next = listPtr;
	            num_items++;
	        }   
	        
	    }
	    
	};
	    
	
	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
	    if (head == NULL) {
	    	return;
	    }
    
        if (value == head->data) {
            Node* tempPtr = head;
            head = head->next;
            delete tempPtr;
            num_items--;
        }
        else {
	        bool checkExist = find(value);
	        if (checkExist != true) {
	            return;
	        }
	        else {
	            Node* listPtr = head;
	            Node* listPtr2 = NULL;
	            while (listPtr->data != value) {
	                listPtr2 = listPtr;
	                listPtr = listPtr->next;
	            }
	            Node* tempPtr = listPtr2;
	            listPtr2 = listPtr2->next;
	            Node* tempPtr2 = listPtr2->next;
	            delete listPtr2;
	            tempPtr->next = tempPtr2;
	            listPtr2 = listPtr;
	            num_items--;
	        }
	    } 
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
	    if (head != NULL) {
	        Node* tempPtr;
	        Node* listPtr;
	        tempPtr = head;
	        listPtr = tempPtr;
	        while (listPtr->next != NULL) {
	            tempPtr = listPtr->next;
	            delete listPtr;
	            listPtr = tempPtr;
	        }
	        delete listPtr;
	        listPtr = head;
	        head = NULL;
	    }
	    num_items = 0;
	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
		Node* listPtr = head;
	    int listSize = 0;
        while (listPtr != NULL) {
            ++listSize;
            listPtr = listPtr->next;
        }
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("At Error");
        }
        else {
            int location = 0;
            Node* current = head;
            while (location < index) {
                current = current->next;
                location++;
            }
            return(current->data);
        }
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
	    int listSize = 0;
	    Node* listCount = head;
	    if (listCount == NULL) {
	    	return 0;
	    }
	    else {
	    	while (listCount->next != NULL) {
	    		listSize++;
	    		listCount = listCount->next;
	    	}
	    	return (listSize + 1);
	    }
	};

	/*
	printList
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string printList() {
		int listSize = size();
		Node* listPtr = head;
		if (head == NULL) {
			return "";
		}
		stringstream SS;
		for (int i = 0; i < listSize; i++) {
			SS << listPtr->data;
			if (listPtr->next != NULL) {
				SS << " ";
			}
			listPtr = listPtr->next;
		}
		string output = SS.str();
		return output;
	};

    
    
    bool find(T value) {
        Node* listPtr = head;
        while (listPtr != NULL) {
        	if (listPtr->data == value) {
            return true;
        	}
            listPtr = listPtr->next;
        }
        return false;
    }; 
};

