#include <iostream>
#include <set>

using namespace std;

class MessageHandlerBase;
class Runtime {
 public:
  static Runtime& GetInstance();

  void RegisterMessageHandler(MessageHandlerBase* handler_base);

  void OnResponse(string msg);
   
 private:
  Runtime() {};
  ~Runtime() {};

  set<MessageHandlerBase*> message_handlers_;
};


class MessageHandlerBase{
 public:
  MessageHandlerBase() {
     cout << "create MessageHandlerbase"<< endl;
     Runtime::GetInstance().RegisterMessageHandler(this);
  }

  ~MessageHandlerBase() {

  }
  
  void SendMessage(string msg) {
    cout << "SendMessage :" << msg << endl;
  }

  virtual void RecvMessage(string msg) = 0;
};


class Car : public MessageHandlerBase {
 public:
  Car(int id) {
    id_ = id;
    cout << "create car"<< endl;
  }
  
  ~Car() {
    cout << "delete car"<< endl;
  }

  void RecvMessage(string msg) {
    cout << "id = " << id_ <<" recv:" << msg << endl;
  }
 private:
  int id_;
};



Runtime& Runtime::GetInstance() {
	static Runtime s_instance;
    return s_instance;
  }

 
void Runtime::RegisterMessageHandler(MessageHandlerBase* handler_base) {
   cout << "RegisterMessageHandler" << endl;
   message_handlers_.insert(handler_base); 
}

void Runtime::OnResponse(string msg) {
    for (auto handler : message_handlers_) {
      handler->RecvMessage(msg);
    }
}


int main() {
	Car *car1 = new Car(1);
    car1->SendMessage("12345");
	
	Car *car2 = new Car(2);
    car2->SendMessage("7890");
    //MessageHandlerBase *base = car;
    //base->RecvMessage("00000");

	Runtime::GetInstance().OnResponse("88888888888888");
}




