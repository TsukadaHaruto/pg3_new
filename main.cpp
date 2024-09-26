#include <stdio.h>
#include <thread>
#include<iostream>
using namespace std;

void Quadruple(int num) {
	num *= 4;
	std::cout << "thread 1 =" << std::this_thread::get_id() << std::endl;
}

void AddFour(int num) {
	num += 4;
	std::cout << "thread 2 =" << std::this_thread::get_id() << std::endl;
}

void subtract(int num) {
	num -= 4;
	std::cout << "thread 3 =" << std::this_thread::get_id() << std::endl;
}

int main() {
	int num = 3;

	std::thread th1(Quadruple, num);
	th1.join();

	std::thread th2(AddFour, num);
	th2.join();

	std::thread th3(subtract, num);
	th3.join();

	return 0;
}