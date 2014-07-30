/*********************************************************
 *	Author: xuechenglong --dukanglu@126.com
 *	Last modified:11:05 28-07-2014
 *	Filename:numberapperonce.cpp
 *	Description:
 **********************************************************/
#include <iostream>
#include <set>

bool IsBit(int data, int indexof1) {
	int tempi = 1 << indexof1;
	if ((data & tempi) != 0) return true;
	return false;
}

//check out which bit is 1
unsigned int FindBitIs(const int data) {
	unsigned int flag = 1;
	int tempdata = data;
	while(tempdata & 0x0001 != 1){
		flag++;
		tempdata = tempdata >> 1;
	}
	return flag;
}

void FindNumsAppearOnce(int data[], int length, int& num1, int& num2) {
	if (data == NULL || length < 2 ){
		return;
	}

	int OrResult = 0;
	for (int i = 0; i < length; ++i){
		OrResult ^= data[i];
#ifdef DEBUG
		std::cout << OrResult << " : ";
#endif 
	}
	std::cout << std::endl;
	
	unsigned int indexof1 = FindBitIs(OrResult);
	num1 = num2 = 0;

	for(int i = 0; i < length; ++i){
		if (IsBit(data[i], indexof1)){
			num1 ^= data[i];
		} else {
			num2 ^= data[i];
		}
	}
}

int main(int argc, char** argv){
	int list_n = 0;
	if ((std::cin >> list_n) && list_n <= 0) return -1;

	int* columnlist = new int[list_n];
	int input_num;
	int output_1, output_2;
	for (int i = 0; i < list_n; ++i) {
		std::cin >> *(columnlist+i);
	}
	
	FindNumsAppearOnce(columnlist, list_n, output_1, output_2);
	input_num = 0;
	for (int i = 0; i < list_n; ++i)
		input_num ^= data[i];

	
	std::cout << output_1 << " " << output_2 << std::endl;
	delete columnlist;
}



