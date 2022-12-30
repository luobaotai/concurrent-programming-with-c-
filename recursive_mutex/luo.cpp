#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

unsigned int number = 0;
std::recursive_mutex shuiguodao;

//data race 数据竞跑
void eatApple() {
	for (int i = 0; i < 10000000; i++) {
		shuiguodao.lock();
		number++;
		shuiguodao.unlock();
	}
}

void func1() {
	shuiguodao.lock();
	number++;
	std::cout << "can you see" << std::endl;
	shuiguodao.unlock();
}
void func2() {
	shuiguodao.lock();
	shuiguodao.lock();
	number++;
	std::cout << "can you see" << std::endl;
	shuiguodao.unlock();
	shuiguodao.unlock();
}

int main() {
	std::thread t1(func2);
	std::thread t2(eatApple);

	t1.join();
	t2.join();
	std::cout << "we eat " << number << " apples" << std::endl;

	std::cin.get();
	
}
