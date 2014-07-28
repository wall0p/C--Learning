/*********************************************************
 *	Author: xuechenglong --dukanglu@126.com
 *	Last modified:11:05 28-07-2014
 *	Filename:numberapperonce.cpp
 *	Description:
 **********************************************************/
#include <iostream>
#include <set>

bool IsBit(int data, int indexof1) {
	
}


void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
	if (data == NULL || length < 2 ){
		return;
	}

	int OrResult = 0;
	for (int i = 0; i < length; ++i){
		OrResult ^= data[i];
	}

	unsigned int indexof1 = FindBitIs(OrResult);
	*num1 = *num2 = 0;

	for(int i = 0; i < length; ++i){
		if (IsBit(data[i], indexOf1)){
			*num1 ^= data[i];
		} else {
			*num2 ^= data[i];
		}
	}
}

int main(int argc, char** argv){
	int list_n = 0;
	if ((std::cin >> list_n) && list_n <= 0) return -1;
	int* columnlist = new int[list_n];
	int input_num;
	for (int i = 0; i < columnlist; ++i) {
		std::cin >> *(columnlist+i);
	}


}



