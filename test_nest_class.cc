#include <iostream>

class Derive{
public:
	Derive() {
		std::cout << "Derive create" << std::endl;
	}

	~Derive() {
		std::cout << "Derive delete" << std::endl;
	}

	void func() {
		std::cout << "Derive func" << std::endl;

	}

	class DD;
};


class Derive::DD : public Derive {
public:
	DD(){
		std::cout << "DD create" << std::endl;	
	}

	~DD() {
		std::cout << "DD delete" << std::endl;	

	}

};

int main() {
	std::cout << "------------" << std::endl;

	Derive::DD *inner = new Derive::DD();
	delete inner;

	std::cout << "------end------" << std::endl;

	return 0;
}
