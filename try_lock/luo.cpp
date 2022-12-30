#include <iostream>
#include <mutex>
#include <thread>

unsigned int apple = 0;
unsigned int orange = 0;
std::mutex shuiguodao;

void eatApple() {
	for (int i = 0; i < 100000; i++) {
		if (shuiguodao.try_lock()) {
			apple++;
			shuiguodao.unlock();
		}
		else {
			orange++;
		}
	}
}

int main() {
	std::thread t1(eatApple);
	std::thread t2(eatApple);
	t1.join();
	t2.join();
	std::cout << "apple: " << apple << std::endl;
	std::cout << "orange: " << orange << std::endl;

	std::cin.get();
}
