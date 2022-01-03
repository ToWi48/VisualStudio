#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Fahrzeuge
{
private:
	int Age = 0;
	string Owner;
	int WheelsCount;
	int x = 26;
public:
	int nV = 48;
	Fahrzeuge() // Standard Constructor
	{
		Owner = "UNKNOWN";
		WheelsCount = 0;
	}
	Fahrzeuge(string L_Owner, int L_wheels) // Constructor
	{
		cout << "Klasse wurde angelegt!" << endl;
		Owner = L_Owner;
		WheelsCount = L_wheels;
	}

	Fahrzeuge(Fahrzeuge &instance) // Copy Constructor
	{
		Owner = instance.Owner;
		Owner.append("-KOPIERT");
		Age = instance.Age + 1;
		WheelsCount = instance.WheelsCount;
	}

	~Fahrzeuge()
	{
		// Destruktor
		cout << "Klasse wurde wird gelöscht!" << endl;
	}

	void printInfo()
	{
		cout << "Fahrzeuginfo: \t" << Age << "\t" << Owner << "\t" << WheelsCount << endl;
	}

	void move(int L_x)
	{
		cout << "Bewege Fahrzeug um: " << L_x << endl;
		x = x + L_x;
	}

	int getPosition()
	{
		cout << "Aktuelle Position: " << x << endl;
		return x;
	}
};

int main()
{
	int i;

	Fahrzeuge BrunosAuto1("Bruno", 4);

	BrunosAuto1.printInfo();

	int istX = BrunosAuto1.getPosition(); // Startposition
	int sollX = 50;

	while (istX < sollX)
	{
		BrunosAuto1.move(1);
		istX = BrunosAuto1.getPosition();
	}
	cout << "Fahrzeug hat sein Ziel erreicht! " << endl;
		

	return 1;
}