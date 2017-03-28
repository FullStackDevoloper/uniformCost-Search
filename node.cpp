/*
* node.cpp
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/

#include "includes.h"

using namespace std;


Node::Node() {
	this->name = 's';
	this->pParent = NULL;
	this->pNext = NULL;
	this->cost = 0;
	this->explored = false;
}
Node::Node(char name, float cost, bool explored, Node* pParent,Node* pNext) {
	this->name = name;
	this->pParent = pParent;
	this->pNext = pNext;
	this->cost = cost;
	this->explored = explored;
}
Node::Node(char name, float cost, bool explored) {
	this->name = name;
	this->cost = cost;
	this->explored = explored;
	this->pParent = this;
}
Node::~Node() {
	//cout<<"Object terminated!"<<endl;
}

void Node:: operator=(Node &node) {

	this->cost = node.cost;
	this->explored = node.explored;
	this->name = node.name;
	this->pNext = node.pNext;
	this->pParent = node.pParent;

}

bool Node::isGoal(char name) {
	if (this->name == name) {
		return true;
	}
	else {
		return false;
	}
}
void Node::setParent(Node* newNode) {
	this->pParent = newNode;

}
void Node::setNext(Node* newNode) {
	this->pNext = newNode;
}
char Node::getName() {
	return name;
	 
}
Node* Node::getParent() {
	return this->pParent;
}

Node* Node::getNext() {
	return this->pNext;
}
float Node::getCost() {
	if (pParent != NULL)
		return cost + pParent->getCost();
	else
	return this->cost;
}
void Node::setExplored(bool ex) {
	this->explored = ex;
}
char Node::getParentName() {

	return pParent->getName();
}
bool Node::isExplored() {
	return this->explored;
}
void Node::expand(vector<Link> &links, List* pFrontier) {
	
	bool isPotentialNode = false;;
	Node* tempNode;
	for (unsigned int i = 0; i < links.size(); i++) {
		
		 if (pFrontier->costCheck(this)==true &&this->getName()==links[i].getC1() ) {
			
				isPotentialNode = true;
				tempNode = new Node(links[i].getC2(), links[i].getLinkCost(), false, this, NULL);
				//this->setNext(tempNode);
				cout << " operating on this node (" << tempNode->getName() << ")" << endl;
			
				
			
		}
		else if (pFrontier->costCheck(this)==true && this->getName() == links[i].getC2()) {
			
			
				isPotentialNode = true;
				tempNode = new Node(links[i].getC1(), links[i].getLinkCost(), false, this, NULL);
				//this->setNext(tempNode);
				cout << " operating on this node (" << tempNode->getName() << ")" << endl;

			
			
		}
		else { tempNode = NULL; continue; }
		this->setExplored(true);
		
		if (isPotentialNode == true && tempNode->isQualified(pFrontier) == true) {
			tempNode->pushNodeToList(pFrontier);
		}
		
	}
			


}
void Node::pushNodeToList(List* pFrontier) {

	pFrontier->append(this);
	
	cout << this->getName() << " Node has been pushed to list(pFrontier)!" << endl;


}
bool Node::isQualified(List* pFrontier) {
	Node* current = pFrontier->exists(this);
	if (current != NULL) {
		
		if (current->isExplored() == true)
			return false;
		else if (current->isExplored() == false && current->getCost() <= this->getCost())
			return false;
		else if (current->isExplored() == false && current->getCost() > this->getCost()) {
			pFrontier->deleteThis(current);
			return true;
		}
	}
	else
		return true;
	
		
	


	
}




