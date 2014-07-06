/*********************************************************
//#	Author: xuechenglong --dukanglu@126.com
#	Last modified:23:48 06-07-2014
#	Filename:TreeCreate.cpp
#	Description:
#*********************************************************/

#include <iostream>
#include <string>
#include <time.h>



typedef struct treeNode{
	int m_value;
	struct treeNode* leftNode;
	struct treeNode* rightNode;
}TREENODE;

TREENODE* Construct(int *preorder, int *inorder, int length) {
	if (preorder == NULL || inorder == NULL || length <= 0) {
		return NULL;
	}

	return ConstructCore(preorder, preorder + length - 1, 
			inorder, inorder + length -1);
}

CosntructCore(int* preStartNode, int* preEndNode, int* inStartNode, int* inEndNode) { 
	int rootValue = preStartNode[0];
	TREENDOE* newroot = new TREENODE();
	newroot->m_value = rootValue;
	newroot->leftNode = newroot->rightNode = NULL;

	if(preStartNode == preEndNode) {
		if (inStartNode == inEndNode && *preStartNode == *inStartNode) { //Here check the preorder list is matched with the inorder list 
			return root;
		} else {
			throw std::exception("Invalid input")
		}
	}

	
}

int main(int argc, char** argv) {
	TREENODE* treeroot = new TREENODE();
	

	delete treeroot;
}
