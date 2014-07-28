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

TREENODE* ConstructCore(int* preStartNode, int* preEndNode, int* inStartNode, int* inEndNode) { 
	int rootValue = preStartNode[0];
	TREENDOE* newroot = new TREENODE();
	newroot->m_value = rootValue;
	newroot->leftNode = newroot->rightNode = NULL;

	//is all nodes has been found?
	if(preStartNode == preEndNode) {
		if (inStartNode == inEndNode && *preStartNode == *inStartNode) { //Here check the preorder list is matched with the inorder list 
			return root;
		} else {
			throw std::exception("Invalid input")
		}
	}
	
	//Looking for the root node of constructed sub tree
	int* temproot = inStartNode;
	while(temproot <= inEndNode && *temproot != rootValue) {
		++temproot;
	}
	

	if (temproot == inEndNode && *temproot != rootValue) {
		throw std::exception("Invalid input");
	}

	int leftLength = temproot - inStartNode;
	int* preLeftEnd = preStartNode + leftLength;

	if (leftLength > 0) {
		newroot->leftNode = ConstructCore(preStartNode + 1, preLeftEnd, inStartNode, tempnode - 1);
	}
	
	if (leftLength < (preEndNode - preStartNode)) {
		newroot->rightNode = ConstructCore(preLeftEnd + 1, preEndNode, tempnode + 1, inEndNode);
	}

	return newroot;
}

int main(int argc, char** argv) {
	TREENODE* treeroot = new TREENODE();
	

	delete treeroot;
}
