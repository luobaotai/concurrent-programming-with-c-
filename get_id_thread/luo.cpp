#include <iostream>
#include <chrono>
#include <thread>

void cpuWaster() {
	std::cout << "process: " << _getpid() << std::endl;//打印进程
	std::cout << "thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
	std::cout << "process: " << _getpid() << std::endl;
	std::cout << "thread: " << std::this_thread::get_id() << std::endl;

	std::thread t1(cpuWaster);
	std::thread t2(cpuWaster);

	std::cin.get();
	
}
