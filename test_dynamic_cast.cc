#include <iostream>


class Base{
public:
	Base() {
		std::cout << "Base create" << std::endl;
	}

	~Base() {
		std::cout << "Base delete" << std::endl;
	}

	virtual void func() = 0;

};


class Derive : public Base{
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


int main() {
	std::cout << "------------" << std::endl;
	Base *aa = new Derive();
	Derive *bb = dynamic_cast<Derive *>(aa);		

	delete bb;
	std::cout << "------end------" << std::endl;

	return 0;
}
