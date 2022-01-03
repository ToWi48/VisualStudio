#include <iostream>
#include <math.h>
using namespace std;

class vektor
{
private:
	double x, y, z; // Vektor mit 3 Komponenten
public:
	vektor() //Default-Konstruktor
	{   // Compiler warnt, wenn Elemente nicht initialisiert werden
		x = 0; y = 0; z = 0;
	}
	vektor(double a, double b, double c) // Konstruktor
	{
		x = a; y = b; z = c;
	}
	void drucke()
	{
		cout << "\n(" << x << "," << y << "," << z << ")";
	}
	double betrag()
	{
		return sqrt(x * x + y * y + z * z);
	}
	double abstand(vektor p)
	{
		double dx, dy, dz;
		dx = x - p.x; dy = y - p.y; dz = z - p.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}
};

// Hauptprogramm mit Nutzung der Klasse Vektor
int main()
{
	cout << "Nutzung der Klasse Vektor\n";

	vektor a(1, 1, 0), b(3, 5, 1),  // Deklaration mit
		c(2, 0, 2), n(1, 1, 1);  // Konstruktor
	vektor x, neu;  // Deklaration mit Default-Konstruktor

	x = a;
	neu = n;      // Wertzuweisungen

	x.drucke();
	b.drucke();
	neu.drucke();

	cout << "\nAbstand=" << a.abstand(n);
	cout << "\nBetrag=" << n.betrag();
	cout << "\nProgrammende";

	return 0;
}