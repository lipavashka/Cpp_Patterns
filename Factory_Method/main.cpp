// example from http://cpp-reference.ru/patterns/creational-patterns/builder/

#include <assert.h> 
#include <iostream>
#include <vector>
using namespace std;

//// ���������� �������� Factory Method �� ������ ����������� ������������
//
//enum Warrior_ID { Infantryman_ID = 0, Archer_ID, Horseman_ID };
//
//// �������� ������� ������� ����������
//class Warrior
//{
//public:
//	virtual void info() = 0;
//	virtual ~Warrior() {}
//	// ������������������� ����������� ��������� �����
//	static Warrior* createWarrior(Warrior_ID id);
//};
//
//class Infantryman : public Warrior
//{
//public:
//	void info() {
//		cout << "Infantryman" << endl;
//	}
//};
//
//class Archer : public Warrior
//{
//public:
//	void info() {
//		cout << "Archer" << endl;
//	}
//};
//
//class Horseman : public Warrior
//{
//public:
//	void info() {
//		cout << "Horseman" << endl;
//	}
//};
//
//
//// ���������� �������������������� ���������� ������
//Warrior* Warrior::createWarrior(Warrior_ID id)
//{
//	Warrior * p = 0;
//	switch (id)
//	{
//	case Infantryman_ID:
//		p = new Infantryman();
//		break;
//	case Archer_ID:
//		p = new Archer();
//		break;
//	case Horseman_ID:
//		p = new Horseman();
//		break;
//	default:
//		assert(false);
//	}
//	return p;
//};
//
//
//// �������� �������� ��� ������ �������������������� ���������� ������
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

// ������������ ���������� �������� Factory Method

// �������� ������� ������� ����������
class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {}
};

class Infantryman : public Warrior
{
public:
	void info() {
		cout << "Infantryman" << endl;
	};
};

class Archer : public Warrior
{
public:
	void info() {
		cout << "Archer" << endl;
	};
};

class Horseman : public Warrior
{
public:
	void info() {
		cout << "Horseman" << endl;
	};
};


// ������� ��������
class Factory
{
public:
	virtual Warrior* createWarrior() = 0;
	virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Infantryman;
	}
};

class ArchersFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Archer;
	}
};

class CavalryFactory : public Factory
{
public:
	Warrior* createWarrior() {
		return new Horseman;
	}
};


// �������� �������� ��� ������ ������ ��������
int main()
{
	InfantryFactory* infantry_factory = new InfantryFactory;
	ArchersFactory*  archers_factory = new ArchersFactory;
	CavalryFactory*  cavalry_factory = new CavalryFactory;

	vector<Warrior*> v;
	v.push_back(infantry_factory->createWarrior());
	v.push_back(archers_factory->createWarrior());
	v.push_back(cavalry_factory->createWarrior());

	for (int i = 0; i<v.size(); i++)
		v[i]->info();
	// ...
}