// example from http://cpp-reference.ru/patterns/structural-patterns/flyweight/

#include <iostream>
#include <string.h>

using namespace std;

// before
//class Image
//{
//	int m_id;
//	static int s_next;
//public:
//	Image()
//	{
//		m_id = s_next++;
//		cout << "   $$ ctor: " << m_id << '\n';
//	}
//	~Image()
//	{
//		cout << "   dtor: " << m_id << '\n';
//	}
//	void draw()
//	{
//		cout << "   drawing image " << m_id << '\n';
//	}
//};
//int Image::s_next = 1;
//
//int main()
//{
//	Image images[5];
//
//	for (int i; true;)
//	{
//		cout << "Exit[0], Image[1-5]: ";
//		cin >> i;
//		if (i == 0)
//			break;
//		images[i - 1].draw();
//	}
//}

// after
//class RealImage
//{
//	int m_id;
//public:
//	RealImage(int i)
//	{
//		m_id = i;
//		cout << "   $$ ctor: " << m_id << '\n';
//	}
//	~RealImage()
//	{
//		cout << "   dtor: " << m_id << '\n';
//	}
//	void draw()
//	{
//		cout << "   drawing image " << m_id << '\n';
//	}
//};
//
//// 1. Класс-обертка с "дополнительным уровнем косвенности"
//class Image
//{
//	// 2. Класс-обертка содержит указатель на реальный класс
//	RealImage *m_the_real_thing;
//	int m_id;
//	static int s_next;
//public:
//	Image()
//	{
//		m_id = s_next++;
//		// 3. Инициализируется нулевым значением
//		m_the_real_thing = 0;
//	}
//	~Image()
//	{
//		delete m_the_real_thing;
//	}
//	void draw()
//	{
//		// 4. Реальный объект создается при поступлении 
//		//    запроса "на первом использовании"
//		if (!m_the_real_thing)
//			m_the_real_thing = new RealImage(m_id);
//		// 5. Запрос всегда делегируется реальному объекту
//		m_the_real_thing->draw();
//	}
//};
//int Image::s_next = 1;
//
//int main()
//{
//	Image images[5];
//
//	for (int i; true;)
//	{
//		cout << "Exit[0], Image[1-5]: ";
//		cin >> i;
//		if (i == 0)
//			break;
//		images[i - 1].draw();
//	}
//}

// Паттерн Proxy: защитный proxy контролирует доступ к основному объекту

//class Person
//{
//	string nameString;
//	static string list[];
//	static int next;
//public:
//	Person()
//	{
//		nameString = list[next++];
//	}
//	string name()
//	{
//		return nameString;
//	}
//};
//string Person::list[] =
//{
//	"Tom", "Dick", "Harry", "Bubba"
//};
//int Person::next = 0;
//
//class PettyCashProtected
//{
//	int balance;
//public:
//	PettyCashProtected()
//	{
//		balance = 500;
//	}
//	bool withdraw(int amount)
//	{
//		if (amount > balance)
//			return false;
//		balance -= amount;
//		return true;
//	}
//	int getBalance()
//	{
//		return balance;
//	}
//};
//
//class PettyCash
//{
//	PettyCashProtected realThing;
//public:
//	bool withdraw(Person &p, int amount)
//	{
//		if (p.name() == "Tom" || p.name() == "Harry" || p.name() == "Bubba")
//			return realThing.withdraw(amount);
//		else
//			return false;
//	}
//	int getBalance()
//	{
//		return realThing.getBalance();
//	}
//};
//
//int main()
//{
//	PettyCash pc;
//	Person workers[4];
//	// string* pString;
//	for (int i = 0, amount = 100; i < 4; i++, amount += 100)
//		if (!pc.withdraw(workers[i], amount))
//		{
//			// pString = &workers[i].name();
//			cout << "No money for " <<  workers[i].name().c_str() << '\n';
//		}
//
//		else
//		{
//			// pString = &workers[i].name();
//			cout << amount << " dollars for " << workers[i].name().c_str() << '\n';
//		}
//	cout << "Remaining balance is " << pc.getBalance() << '\n';
//}


// Паттерн Proxy: операторы "->" and "." дают различные результаты

class Subject
{
public:
	virtual void execute() = 0;
};

class RealSubject : public Subject
{
	string str;
public:
	RealSubject(string s)
	{
		str = s;
	}
	/*virtual*/void execute()
	{
		cout << str.c_str() << '\n';
	}
};

class ProxySubject : public Subject
{
	string first, second, third;
	RealSubject *ptr;
public:
	ProxySubject(string s)
	{
		int num = s.find_first_of(' ');
		first = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		second = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		third = s.substr(0, num);
		s = s.substr(num + 1);
		ptr = new RealSubject(s);
	}
	~ProxySubject()
	{
		delete ptr;
	}
	RealSubject *operator->()
	{
		cout << first.c_str() << ' ' << second.c_str() << ' ';
		return ptr;
	}
	/*virtual*/void execute()
	{
		cout << first.c_str() << ' ' << third.c_str() << ' ';
		ptr->execute();
	}
};

int main()
{
	ProxySubject obj(string("the quick brown fox jumped over the dog"));
	obj->execute();
	obj.execute();
}