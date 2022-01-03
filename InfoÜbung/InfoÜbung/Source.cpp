// demo_zeiger.c
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

double funx(double arg)
{
	return -arg;
}

double funy(double arg)
{
	return arg * 2;
}

int fuer_alle_elemente(int n, double* feld, double (*funktion)(double))
{
	for (int i = 0; i < n; i++)
		feld[i] = funktion(feld[i]);
	return n;
}

void ausgabe(int n, double* feld)
{
	for (int i = 0; i < n; i++)
		printf("%5.2lf  ", feld[i]);

	printf("\n");
}

void swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	//double ff[5] = { 2.2, 3.3, 4.4, 5.5, 6.6 }; // Stack

	int n;

	list<void> zahlen;
	list<void>::iterator lIter; // Iterator definieren

	zahlen.insert(1, 5);

	cin >> n;

	double* gg = new double[n] {2.2, 3.3, 4.4, 5.5, 6.6}; // Heap

	double x = 1, y = 2; // Stack

	//fuer_alle_elemente(5, ff, funy); // hier kann auch funx anstelle funy stehen.

	//swap(&x, &y);

	//printf("x=%lf, y=%lf\n", x, y);
	ausgabe(n, gg);

	delete(gg);

	// Bei Nutzung von funx
	// -2.20  -3.30  -4.40  -5.50  -6.60
	// nach Umschalten auf funy
	// 4.40   6.60   8.80  11.00  13.20
	return 0;
}