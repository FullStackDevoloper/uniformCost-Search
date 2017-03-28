/*
* node.h
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/
#ifndef NODE_H
#define NODE_H


#include "includes.h"



using namespace std;
#include <vector>


class Node {
private:
	
	
	float cost;
	bool explored;
	char name;

public:
	Node *pParent, *pNext;
	Node();
	Node(char name, float cost, bool explored, Node* pParent,Node* pNext);
	Node(char name, float cost, bool explored);
	~Node();
	void  operator=(Node &node);
	bool isGoal(char name);
	char getName();
	void setParent(Node* newNode);
	char getParentName();
	void setNext(Node* newNode);
	Node* getParent();
	Node* getNext();
	float getCost();
	void setExplored(bool ex);
	bool isExplored();
	void expand(vector<Link> &links, List* pFrontier);
	void pushNodeToList(List* pFrontier);
	bool isQualified(List* pFrontier);


};

#endif
