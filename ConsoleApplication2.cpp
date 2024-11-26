/*#include <iostream>
using namespace std;

class GameSetting {
	static GameSetting* instance;
	int brightness;
	int width;
	int height;
	GameSetting() :brightness(100),width(100),height(250){}
public:
	static GameSetting* getInstance() {
		if (instance == NULL) {
			instance = new GameSetting();
		}
		return instance;
	}
	void setBrightness(int bright) { brightness = bright; }
	void setWidth(int wid) { width = wid; };
	void setHeight(int high) { height = high; }
	int getBrightness() { return brightness; }
	int getHeight() { return height; }
	int getWidth() { return width; }
	void display() {
		cout << "Brightness : " << getBrightness() << endl;
		cout << "Height : " << getHeight() << endl;
		cout << "Width : " << getWidth() << endl;
	}
};

GameSetting* GameSetting::instance = NULL;
void anotherMethod() {
	GameSetting* setting2 = GameSetting::getInstance();
	setting2->display();
}

int main() {
	GameSetting* setting = GameSetting::getInstance();
	setting->display();
	setting->setBrightness(90);
	anotherMethod();
	
	return 0;
}*/

/*#include <iostream>
using namespace std;

class Vechile {
public:
	virtual void transportation() = 0;
};

class Bike :public Vechile {
	void transportation() override {
		cout << "Bike Travels on Road...." << endl;
	}
};

class Train :public Vechile {
	void transportation() override {
		cout << "Train travels thorugh Railway Tracks.." << endl;
	}
};

class Plane :public Vechile {
	void transportation() override {
		cout << "Plane tavels in air... Air Way.." << endl;
	}
};

class VechileFactory {
public:
	virtual Vechile* getObject() = 0;
};

class BikeFactory :public VechileFactory {
	Vechile* getObject() {
		return new Bike();
	}
};

class TrainFactory :public VechileFactory {
	Vechile* getObject() {
		return new Train();
	}
};

class PlaneFactory : public VechileFactory {
	Vechile* getObject() {
		return new Plane();
	}
};

int main() {
	int opt;
	cout << "Welcome...." << endl;
	cout << "Choose which object needs to be created... (Or) Enter 0 to Exit...\n";
	while (1) {
		cout << "1 -> Bike\n2 -> Train\n3-> Plane\n";
		cin >> opt;
		if (!opt) {
			break;
		}
		VechileFactory* vechileFactory = nullptr;
		switch (opt)
		{
		case 1:
			cout << "Creating object for Bike...\n";
			vechileFactory = new BikeFactory();
			break;
		case 2:
			cout << "Creating object for Train...\n";
			vechileFactory = new TrainFactory();
			break;
		case 3:
			cout << "Creating object for Plane...\n";
			vechileFactory = new PlaneFactory();
			break;
		default:
			cout << "Enter a valid option...\n";
			continue;
		}
		if (vechileFactory) {
			Vechile* vechile = vechileFactory->getObject();
			vechile->transportation();
		}
	}
	
	return 0;
}
*/


#include <iostream>
#include <vector>
using namespace std;

class Subscriber {
public:
	virtual void notify(string msg) = 0;
};

class User :public Subscriber {
	int userId;
public:
	User(int userId) {
		this->userId = userId;
	}
	void notify(string msg) {
		cout << "User " << userId << " You have a new msg : " << msg << endl;
	}
};

class Group {
	vector<Subscriber*> users;
public:
	void subscribeUser(Subscriber* user) {
		users.push_back(user);
	}
	void unSubscribeUser(Subscriber* user) {
		users.erase(remove(users.begin(), users.end(), user), users.end());
	}
	void notify(string msg) {
		for (auto user : users) {
			user->notify(msg);
		}
	}
};

int main() {
	Group* group = new Group();

	User* user1 = new User(1);
	User* user2 = new User(2);
	User* user3 = new User(3);
	User* user4 = new User(4);

	group->subscribeUser(user1);
	group->subscribeUser(user2);
	group->subscribeUser(user3);
	group->subscribeUser(user4);

	group->notify("Dear customer your product is in sale now..");
	group->unSubscribeUser(user2);
	group->notify("Sale is live now..");

	return 0;
}