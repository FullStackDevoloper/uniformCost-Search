/*
* List.cpp
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/


#include "includes.h"
//#include <iostream>
//#include <vector>

using namespace std;
void List::setGoal(char goal) {
	this->goal = goal;
}
char List::getGoal() {
	return this->goal;
}
List::List() {
	this->pFirstNode = this->pLastNode = NULL;
	this->size = 0;
	this->goal = 0;

}
List::List(Node &newNode) {
	this->pFirstNode = this->pLastNode = &newNode;
	this->pFirstNode->setParent(0);
	this->pLastNode->setNext(0);
	this->size++;
	//cout<<pFirstNode->getName();
}
List::~List() {
	//cout<<"Object Terminated! "<<endl;
}
void List:: operator=(List &list) {

	this->pFirstNode = list.pFirstNode;
	this->pLastNode = list.pLastNode;


}
void List::append(Node* node) {
	//Node* node = new Node(name, cost, exp, parent, NULL);
	if (pFirstNode == NULL) {
		pFirstNode = node;
	}
	else {
		pLastNode->setNext(node);
	}
	pLastNode = node;
}
int List::getSize() {
	return this->size;
}
Node* List::getNode(Node* node) {

	Node* current = this->pFirstNode;
	Node* output=0;

	while (current != 0) {
		if (current == node) {
			output = current;
		}

		current = current->getNext();
	}

	return output;
}
vector<Node> List::getNodes() {
	vector<Node> vec;
	Node* current = this->pFirstNode;
	while (current != 0) {
		vec.push_back(*current);
		current = current->getNext();
	}
	return vec;
}
void List::printList() {
	Node* current = pFirstNode;
	Node* parent;
	while (current!=NULL) {
		parent = current->getParent();
		if (parent == NULL) {
			cout << "Name("<<current->getName() << ") Parent(" <<0<< ") Cost(" << current->getCost() <<")"<< endl;
		}else
		cout << "Name(" << current->getName() << ") Parent(" << parent->getName() << ") Cost(" << current->getCost() << ")" << endl;
		current = current->getNext();
	}
}
void List::printList(Node* node) {
	Node* current = pFirstNode;
	Node* parent;
	while (current != NULL) {
		if (current == node) {
			parent = current->getParent();
			if (parent == NULL) {
				cout << "Name(" << current->getName() << ") Parent(" << 0 << ") Cost(" << current->getCost() << ")" << endl;
			}
			else
				cout << "Name(" << current->getName() << ") Parent(" << parent->getName() << ") Cost(" << current->getCost() << ")" << endl;
		}
		current = current->getNext();
		}
}
Node* List::getFirstNode() {
	return pFirstNode;
}
Node* List::getLastNode() {
	return pLastNode;
}
void List::setExplored(Node* node) {
	Node* current = this->pFirstNode;
	while (current != 0) {
		if (current == node) {
			current->setExplored(true);
			break;
		}
	}
}

bool List::costCheck(Node* node) {
	Node* current = pFirstNode;
	float minCost=1000000;
	if (node->getParent() == NULL)
		return true;
	else if (node->getName() == goal)
		return true;
	else {
		while (current != NULL) {
			if (node->getParent()==current->getParent() && current->getCost() < minCost) {
				minCost = current->getCost();
			}
			if (current->getName() == goal) {
				minCost = current->getCost();
				break;
			}
			current = current->getNext();
		}
		if (node->getCost() == minCost)
			return true;
		else
			return false;
	}
}
Node* List::exists(Node* node) {
	Node* current = pFirstNode;
	Node* current2=0;

	while (current != 0) {
		if (current->getName() == node->getName()) {
			current2 = current;
			break;
		}
		else {
			current2 = 0;
		}
		current = current->getNext();
	}
	return current2;
}
void List::printResult() {
	Node* current = pFirstNode;
	Node* cp;
	int counter=0;
	
	while (current != NULL) {
		if (current->isExplored() == true) {
			cp = current->getParent();
			if (cp == NULL) {
				cout << current->getName() << " " << current->getCost() << " " << '0' << endl;
				counter++;
			}
			else {
				cout << current->getName() << " " << current->getCost() << " " << cp->getName() << endl;
				counter++;
			}
		}
		current = current->getNext();
	}
	cout << "Number Of Nodes Expanded : " << counter<<endl;
}

void List::deleteThis(Node* node) {
	Node* current = pFirstNode;
	while (current != 0) {
		if (current->getNext() == node) {
			current->setNext(node->getNext());
			node->setNext(NULL);
		}
		current = current->getNext();
	}
}

Node* List::getThis(Node* node) {
	Node* current = pFirstNode;
	while (current != NULL) {
		if (current == node) {
			return current;
			}
		}
}
void List::setpFirst(Node* node) {
	this->pFirstNode = node;
}
void List::setpLast(Node* node) {
	this->pLastNode->setNext(node);
	node = pLastNode;
	pLastNode->setNext(NULL);
}


