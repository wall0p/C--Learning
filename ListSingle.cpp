/**********************************************************
#	Author: xuechenglong --dukanglu@126.com
#	Last modified23:17 02 07 2014
#	Filename:ListSingle.cpp
#	Description:
#*********************************************************/


#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>

typedef struct ListNode {
	int m_Value;
	ListNode* next;

}LISTNODE;


void addNode(LISTNODE* chead, int value) { // void addNode(LISTNODE* * chead, int value) {}
	if (chead == NULL) {
		return;
	}
/*
	if (chead->next == NULL) {
		LISTNODE* tempnode = (LISTNODE*)malloc(sizeof(LISTNODE));
		tempnode->m_Value = value;
		tempnode->next = NULL;
		chead->next = tempnode;
	}
*/	
	LISTNODE* flagnode = chead;

	while(flagnode->next != NULL) {
		flagnode = flagnode->next;
	}

	//LISTNODE* tempnode = (LISTNODE*)malloc(sizeof(LISTNODE));   //Here is c style program, using malloc
	LISTNODE* tempnode = new LISTNODE();	//Here is real C++ style program, using new 
	tempnode->m_Value = value;
	tempnode->next = NULL;
	flagnode->next = tempnode;
	
}

void delNode(LISTNODE* chead, int value) {
	if (chead == NULL) {
		return;
	}
	
	LISTNODE* pdelte = NULL;
	LISTNODE* flagnode = chead;
	
	while(flagnode->next != NULL && flagnode->next->m_Value != value){
		flagnode = flagnode->next;
	}
	
	if(flagnode->next == NULL) return;
	else if (flagnode->next->m_Value == value){
		pdelte = flagnode->next->next;
		flagnode->next->m_Value = pdelte->m_Value;
		flagnode->next->next = pdelte->next;
		delete pdelte;

	} else {
		std::cout << "Unkown error!" << std::endl;
		return;
	}
	
}

void print(LISTNODE* chead) {
	LISTNODE* outNode = chead->next;
	while(outNode != NULL){
		std::cout << outNode->m_Value << " ";	
		outNode = outNode->next;
	}
	std::cout << std::endl;
}

void releasePrint(LISTNODE* chead) {
	if(chead->next == NULL) {
		return;
	}
	std::stack<LISTNODE*> nodes;

	LISTNODE* lnode = chead->next;
	while(lnode != NULL) {
		nodes.push(lnode);
		lnode = lnode->next;
	}

	while(!nodes.empty()) {
		lnode = nodes.top();
		std::cout << lnode->m_Value << " ";
		nodes.pop();
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	
	LISTNODE* chead = new LISTNODE();
	chead->next = NULL;

	int value = 0;

	while(std::cin >> value && value != '#'){
		addNode(chead, value);
	}
	std::cout << "singlist number: "<<std::endl;
	print(chead);
	std::cout << "\ninput Delete number: " << std::endl;

/*	int delValue = 0;
	while(std::cin >> delValue && delValue != -1){
		delNode(chead, delValue);
		std::cout << "After delete " << delValue << " : " << std::endl;
		print(chead);
	}
	*/
	releasePrint(chead);
	return 0;
}
