// Example from  http://cpp-reference.ru/patterns/structural-patterns/composite/
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// Component 
class Unit
{
public:
	virtual int getStrength() = 0;
	virtual void addUnit(Unit* p) {
		assert(false);
	}
	virtual ~Unit() {}
};

// Primitives
class Archer : public Unit
{
public:
	virtual int getStrength() {
		return 1;
	}
};

class Infantryman : public Unit
{
public:
	virtual int getStrength() {
		return 2;
	}
};

class Horseman : public Unit
{
public:
	virtual int getStrength() {
		return 3;
	}
};


// Composite
class CompositeUnit : public Unit
{
public:
	CompositeUnit() { cout << "constructor CompositeUnit" << endl; }
	int getStrength() {
		int total = 0;
		for (int i = 0; i<c.size(); ++i)
			total += c[i]->getStrength();
		return total;
	}
	void addUnit(Unit* p) 
	{
		c.push_back(p);
	}
	~CompositeUnit() 
	{
		cout << "distructor CompositeUnit" << endl;
		for (int i = 0; i<c.size(); ++i)
			delete c[i];
	}
private:
	vector<Unit*> c;
};


// ��������������� ������� ��� �������� �������
CompositeUnit* createLegion()
{
	// ������� ������ ��������:
	CompositeUnit* legion = new CompositeUnit;
	// 3000 ������� ����������
	for (int i = 0; i<3000; ++i)
		legion->addUnit(new Infantryman);
	// 1200 ������ ����������
	for (int i = 0; i<1200; ++i)
		legion->addUnit(new Archer);
	// 300 ���������
	for (int i = 0; i<300; ++i)
		legion->addUnit(new Horseman);

	return legion;
}

int main()
{
	// ������� ����� ������� �� 4-� ��������
	CompositeUnit* army = new CompositeUnit;
	for (int i = 0; i<4; ++i)
		army->addUnit(createLegion());

	cout << "Roman army damaging strength is " << army->getStrength() << endl;
	// �
	delete army;
	return 0;
}
