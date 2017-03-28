/*
* main.cpp
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/

#include "functions.h"
#include "acquireLinks.h"
#include "includes.h"
using namespace std;



int main() {

	vector<Link> links;
	acquireLinks1(links);
	for (unsigned int i = 0; i<links.size(); i++) {
		cout << "C1 : " << links[i].getC1() << " C2 : " << links[i].getC2() << " LinkCost : " << links[i].getLinkCost() << endl;

	}
	char startCity,cityGoal;
	cout << "Please Enter Start City : " << endl;
	cin >> startCity;
	cout << "Please Enter Goal City : " << endl;
	cin >> cityGoal;
	Node* n2 = new Node(startCity, 0, false, NULL,NULL);
	
	
	List* pFrontier = new List(*n2);
	
	pFrontier->setGoal(cityGoal);
	
	
	
	int expandCount = 0;
	Node* pCurrentNode = pFrontier->pFirstNode;
	while (pCurrentNode != NULL) {

		if (pCurrentNode->isGoal(cityGoal) == true) {
			cout << "goal reached";
			pCurrentNode->expand(links,pFrontier);
			expandCount++;
			pFrontier->printList();
			pFrontier->printResult();
			
		}
		else {
			pCurrentNode->expand(links, pFrontier);
			expandCount++;
		}
			pCurrentNode = pCurrentNode->getNext();
		}
	cout << "Expand method has been called : " << expandCount << " times" << endl;
	
	int h;
	cin >> h;


//	List* pFrontier = new List(*n2);

//	pFrontier->setGoal('G');


	//pFrontier->deleteThis(n7);
	//pFrontier->printList();
	
//	n2->expand(links,pFrontier);
//	pFrontier->printList();
	//pFrontier->printResult();

	/*n6->pushNodeToList(pFrontier);
	n7->pushNodeToList(pFrontier);
	n4->pushNodeToList(pFrontier);
	n5->pushNodeToList(pFrontier);
	pFrontier->printList();
	pFrontier->printResult();
	cout << n8->isGoal(pFrontier->getGoal()) << endl;
	cout << n8->isQualified(pFrontier);*/
	//cout<<*n9;
	//Node* n ;
	//cout<<n2->getParentName();// isn't working.... can't get the pParent name!!!
	getchar();
	return 0;

}

