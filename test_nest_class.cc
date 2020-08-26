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
	DD(int param){
		std::cout << "DD create, " << "param = " << param <<std::endl;	
	}
	DD(){
		std::cout << "DD create"<<std::endl;	
	}

	~DD() {
		std::cout << "DD delete" << std::endl;	

	}

	int dd_;

};


class Another : public Derive::DD {
public:
	Another() : Derive::DD(3) {
		std::cout << "Another create" << std::endl;	
	}

	~Another() {
		std::cout << "Another delete" << std::endl;	

	}
};

int main() {
	std::cout << "------------" << std::endl;

	Derive::DD *inner = new Derive::DD(99);
	delete inner;

	std::cout << "-----8888888-------" << std::endl;

	Another *another = new Another();
	delete another;

	std::cout << "------end------" << std::endl;
	return 0;
}
