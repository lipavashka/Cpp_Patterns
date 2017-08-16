#include <iostream>
using namespace std;

enum typeSensor { Fahrenheit, DS18B20, TMP160, WRONG};

class FahrenheitSensor
{
public:
	float getFahrenheitTemp() {
		float t = 75.0;
		// ... 
		return t;
	}
protected:
	void adjust() { cout << "adjust Fahrenheit \n"; } // защищенный метод
};

class DS18B20Sensor
{
public:
	float getDS18B20Temp() {
		float t = 25.0;
		// ... 
		return t;
	}
protected:
	void adjust() { cout << "adjust DS18B20 \n"; } // защищенный метод
};

class TMP160Sensor
{
public:
	float getTMP160Temp() {
		float t = 35.0;
		// ... 
		return t;
	}
protected:
	void adjust() { cout << "adjust TMP160 \n"; } // защищенный метод
};

class Sensor
{
public:
	virtual ~Sensor() {}
	virtual float getTemperature(typeSensor sens) = 0;
	virtual void adjust(typeSensor sens) = 0;
};

class Adapter : public Sensor, private FahrenheitSensor, private DS18B20Sensor, private TMP160Sensor
{
public:
	Adapter() { }

	float getTemperature(typeSensor sens)
	{
		if (sens == Fahrenheit)
		{
			return (getFahrenheitTemp() - 32.0)*5.0 / 9.0;
		}
		else if (sens == DS18B20)
		{
			return getDS18B20Temp();
		}
		else if (sens == TMP160)
		{
			return getTMP160Temp();
		}
		else
		{
			cout << "ERROR getTemperature: wrong sensor type  \n";
			return -99999;
		}
	}
	void adjust(typeSensor sens)
	{
		if (sens == Fahrenheit)
		{
			FahrenheitSensor::adjust();
		}
		else if (sens == DS18B20)
		{
			DS18B20Sensor::adjust();
		}
		else if (sens == TMP160)
		{
			TMP160Sensor::adjust();
		}
		else
		{
			cout << "ERROR adjust: wrong sensor type  \n";
		}
	}
};

int main()
{
	Sensor * p = new Adapter();
	p->adjust(Fahrenheit);
	cout << "Celsius temperature = " << p->getTemperature(Fahrenheit) << endl;

	p->adjust(DS18B20);
	cout << "DS18B20 temperature = " << p->getTemperature(DS18B20) << endl;

	p->adjust(TMP160);
	cout << "TMP160 temperature = " << p->getTemperature(TMP160) << endl;

	p->adjust(WRONG);
	cout << p->getTemperature(WRONG) << endl;
	delete p;
	return 0;
}
