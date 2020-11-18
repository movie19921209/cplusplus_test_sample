#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
	std::cout << "Hello World\n" << std::flush;
	auto start = std::chrono::system_clock::now();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end -start;
	std::cout << std::fixed  << std::setprecision(3) << "Waited " << diff.count()  << " ms\n";
}
