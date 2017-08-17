// example from http://cpp-reference.ru/patterns/creational-patterns/prototype/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//// ���������� �������� Ptototype �� ������ ����������� ������������
//
//// �������������� ���� ����� �����
//enum Warrior_ID { Infantryman_ID, Archer_ID, Horseman_ID };
//
//class Warrior;  // ����������� ����������
//typedef map<Warrior_ID, Warrior*> Registry;
//
//// ������ ���������� ��������� � ���� Singleton �������
//Registry& getRegistry()
//{
//	static Registry _instance;
//	return _instance;
//}
//
//// ������������ ���������� ����� ������ - ������ � ������ �������
//// ������������ ��� �������� ����������
//class Dummy { };
//
//// ����������� ������� �����. ����� ����� ��������� ����������� 
//// ���������� ����������� ��� �������� ������ ������ ���� ����� �����
//class Warrior
//{
//public:
//	virtual Warrior* clone() = 0;
//	virtual void info() = 0;
//	virtual ~Warrior() {}
//	// ������������������� ����������� ����� ��� �������� ������ 
//	// ���� ����� �����
//	static Warrior* createWarrior(Warrior_ID id) {
//		Registry& r = getRegistry();
//		if (r.find(id) != r.end())
//			return r[id]->clone();
//		return 0;
//	}
//protected:
//	// ���������� ��������� � ��������� ����������
//	static void addPrototype(Warrior_ID id, Warrior * prototype) {
//		Registry& r = getRegistry();
//		r[id] = prototype;
//	}
//	// �������� ��������� �� ��������� ����������
//	static void removePrototype(Warrior_ID id) {
//		Registry& r = getRegistry();
//		r.erase(r.find(id));
//	}
//};
//
//
//// � ����������� ������� ��������� ����� ����� � ���� ����������� 
//// ������-������ ������������ ��������������� ���������
//class Infantryman : public Warrior
//{
//public:
//	Warrior* clone() {
//		return new Infantryman(*this);
//	}
//	void info() {
//		cout << "Infantryman" << endl;
//	}
//private:
//	Infantryman(Dummy) {
//		Warrior::addPrototype(Infantryman_ID, this);
//	}
//	Infantryman() {}
//	static Infantryman prototype;
//};
//
//class Archer : public Warrior
//{
//public:
//	Warrior* clone() {
//		return new Archer(*this);
//	}
//	void info() {
//		cout << "Archer" << endl;
//	}
//private:
//	Archer(Dummy) {
//		addPrototype(Archer_ID, this);
//	}
//	Archer() {}
//	static Archer prototype;
//};
//
//class Horseman : public Warrior
//{
//public:
//	Warrior* clone() {
//		return new Horseman(*this);
//	}
//	void info() {
//		cout << "Horseman" << endl;
//	}
//private:
//	Horseman(Dummy) {
//		addPrototype(Horseman_ID, this);
//	}
//	Horseman() {}
//	static Horseman prototype;
//};
//
//
//Infantryman Infantryman::prototype = Infantryman(Dummy());
//Archer Archer::prototype = Archer(Dummy());
//Horseman Horseman::prototype = Horseman(Dummy());
//
//
//int main()
//{
//	vector<Warrior*> v;
//	v.push_back(Warrior::createWarrior(Infantryman_ID));
//	v.push_back(Warrior::createWarrior(Archer_ID));
//	v.push_back(Warrior::createWarrior(Horseman_ID));
//
//	for (int i = 0; i<v.size(); i++)
//		v[i]->info();
//	// ...
//}

// ���������� �������� Prototype � ������� ����������� ������ - �������

// �������� ������� ������� ����������
// ����������� ������� �����
class Warrior
{
public:
	virtual Warrior* clone() = 0;
	virtual void info() = 0;
	virtual ~Warrior() {}
};


// ����������� ������ ��������� ����� �����
class Infantryman : public Warrior
{
	friend class PrototypeFactory;
public:
	Warrior* clone() {
		return new Infantryman(*this);
	}
	void info() {
		cout << "Infantryman" << endl;
	}
private:
	Infantryman() {}
};

class Archer : public Warrior
{
	friend class PrototypeFactory;
public:
	Warrior* clone() {
		return new Archer(*this);
	}
	void info() {
		cout << "Archer" << endl;
	}
private:
	Archer() {}
};

class Horseman : public Warrior
{
	friend class PrototypeFactory;
public:
	Warrior* clone() {
		return new Horseman(*this);
	}
	void info() {
		cout << "Horseman" << endl;
	}
private:
	Horseman() {}
};


// ������� ��� �������� ������ ������ ���� ����� �����
class PrototypeFactory
{
public:
	Warrior* createInfantrman() {
		static Infantryman prototype;
		return prototype.clone();
	}
	Warrior* createArcher() {
		static Archer prototype;
		return prototype.clone();
	}
	Warrior* createHorseman() {
		static Horseman prototype;
		return prototype.clone();
	}
};


int main()
{
	PrototypeFactory factory;
	vector<Warrior*> v;
	v.push_back(factory.createInfantrman());
	v.push_back(factory.createArcher());
	v.push_back(factory.createHorseman());

	for (int i = 0; i<v.size(); i++)
		v[i]->info();
	// ...
}