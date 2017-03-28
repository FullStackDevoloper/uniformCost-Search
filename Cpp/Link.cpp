/*
* Link.cpp
*
*  Created on: Mar 18, 2017
*      Author: Mustafa
*/

#include "includes.h"
#include "Link.h"


Link::Link() {
	this->c1 = 0;
	this->c2 = 0;
	this->linkCost = 0.0;
}

Link::Link(char c1, char c2, float linkCost) {
	this->c1 = c1;
	this->c2 = c2;
	this->linkCost = linkCost;
}
Link::~Link() {
	//cout<<"Object Terminated!"<<endl;;
}
void Link:: operator=(Link &link) {

	this->c1 = link.c1;
	this->c2 = link.c2;
	this->linkCost = link.linkCost;

}

char Link::getC1() {
	return c1;
}

char Link::getC2() {
	return c2;
}

float Link::getLinkCost() {
	return linkCost;
}



/*class Link{
private:
char c1,c2;
float linkCost;
public:
Link(){
c1=0;
c2=0;
linkCost=0;
};
Link(char c1, char c2, float linkCost){
this->c1=c1;
this->c2=c2;
this->linkCost=linkCost;
};

char getC1(){
return c1;
}
char getC2(){
return c2;
}
float getLinkCost(){
return linkCost;
}

};

*/
