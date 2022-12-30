#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

unsigned int number = 0;
std::mutex shuiguodao;

void eatApple() {
	
	for (int i = 0; i < 10000000; i++) {
		shuiguodao.lock();
		number++;
		shuiguodao.unlock();
	}
	
}

int main() {
	std::thread t1(eatApple);
	std::thread t2(eatApple);

	t1.join();
	t2.join();
	std::cout << "we eat " << number << " apples" << std::endl;

	std::cin.get();
	
}
