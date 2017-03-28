/*
* List.h
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/
#ifndef LIST_H
#define LIST_H

#include "includes.h"
//#include <iostream>
//#include <vector>

using  namespace std;

class List {
private:
	
	vector<Node> list;
	Link* links;
	int size;
	char goal;
public:
	Node* pFirstNode;
	Node* pLastNode;
	List();
	List(Node &newNode);
	~List();
	void operator=(List &list);
	int getSize();
	void append(Node* node);
	Node* getNode(Node* node);
	vector<Node> getNodes();
	void setExplored(Node* node);
	void printList(void);
	void printList(Node* node);
	Node* getFirstNode();
	Node* getLastNode();
	bool costCheck(Node* node);
	Node* exists(Node* node);
	void setGoal(char goal);
	char getGoal();
	void printResult();
	void deleteThis(Node* node);
	Node* getThis(Node* node);
	void setpFirst(Node* node);
	void setpLast(Node* node);


};
#endif
