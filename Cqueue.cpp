/**********************************************************
#	Author: xuechenglong --dukanglu@126.com
#	Last modified22:20 07 07 2014
#	Filename:Cqueue.cpp
#	Description:
#*********************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>

template <typename T>
class Cqueue{
	public:
		Cqueue():length(0){};
		~Cqueue(){};

		void appendTail(const T& node);
		T deletehead();
		int getength(){int a = length; return a;};
	private:
		std::stack<T> stack_a;  //using for input
		std::stack<T> stack_b;	//using for output
		int length;
};


template <typename T> 
void Cqueue<T>::appendTail(const T& node){
	stack_a.push(node);
	length++;
}

template <typename T>
T Cqueue<T>::deletehead(){

	if (stack_b.empty() && stack_a.empty()){
	//		throw new std::exception("Queue is empty!");
		std::cout << " Queue is empty!'" << std::endl;
		return NULL;
	}

	if (!stack_b.empty()){
		T a = stack_b.top();
		stack_b.pop();
		length--;
		return a;
	}

	while(!stack_a.empty()){
		stack_b.push(stack_a.top());
		stack_a.pop();
	}

	T b = stack_b.top();
	stack_b.pop();
	length--;
	return b;
}

int main(int argc, char** argv) {
	int value = 0;

	Cqueue<int> queueByStack;
	while(std::cin >> value && value != -1){
		queueByStack.appendTail(value);
	}
	int length = queueByStack.getength();
	for(int i = 0; i < length; ++i){
		int tempnode = queueByStack.deletehead();
		std::cout << tempnode << " " << std::endl;

	}

	return 0;
}
