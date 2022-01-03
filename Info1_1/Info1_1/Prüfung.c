#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

// printf("%i", i);
// scanf("%i", &i);


struct date { unsigned char Tag; unsigned char Monat; int Jahr; };
struct zeit { unsigned char Stunden; unsigned char Minuten; unsigned char Sekunden; };
enum einheit { Volt, Ampere, Watt, GradCelsius };

struct messung {
	struct date Datum;
	struct zeit Zeit;
	double Wert;
	enum einheit Einheit;
};

struct messung erzeuge_messung(struct date d, struct zeit z, double wert, enum einheit e)
{
	struct messung aktuell = {d,z,wert,e};
	return aktuell;
}

int main()
{
	struct messung feld[3] = {
		erzeuge_messung((struct date){ 25,2,2021 }, (struct zeit){ 12,55,10 }, 218, Volt),
		erzeuge_messung((struct date){ 25,2,2021 }, (struct zeit){ 12,55,10 }, 17.9, Ampere),
		erzeuge_messung((struct date){ 25,2,2021 }, (struct zeit){ 12,55,10 }, 67.9, GradCelsius)
	};
	return 0;
}



//int alle_vz_gleich(double* feld, int n)
//{
//	if (n < 2)
//		return 0;
//	int vz0 = 1;
//	int vzp = 1;
//	int vzn = 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (feld[i] <= 0)
//			vzp = 0;
//		if (feld[i] >= 0)
//			vzn = 0;
//		if (feld[i] != 0)
//			vz0 = 0;
//	}
//	if ((vzp == 1 && vzn == 0 && vz0 == 0) || (vzp == 0 && vzn == 1 && vz0 == 0) || (vzp == 0 && vzn == 0 && vz0 == 1))
//		return 1;
//		
//	return 0;
//}
//
//int main()
//{
//	int n = 1;
//	double feld[1] = { 1 };
//
//	printf("%i", alle_vz_gleich(feld, n));
//	return 0;
//}


//double R_reihe(double Rx, double Ry)
//{
//    return Rx + Ry;
//}
//
//double R_parallel(double Rx, double Ry)
//{
//    return 1.0 / (1.0 / Rx + 1.0 / Ry);
//}
//
//int main()
//{
    // Variable und Widerstandswerte in der Einheit Ohm
    double R1 = 100, R2 = 80, R3 = 150, R4 = 10, R5 = 200, R6 = 20;
    double R;

    // R5 - R4
    R = R_parallel(R4, R_parallel(R5, R6));

    // R3 + R
    R = R_reihe(R3, R);

    // R1 + R2, R
    R = R_parallel(R, R_reihe(R1, R2));

    printf("Gesamtwiderstand: %lf\n", R);
//}

int main()
{
	int g;
	printf("Grenze g eingeben: ");
	scanf("%i", &g);

	if (g > 1)
	{
		int i = 1;
		int fak = 1;

		do
		{
			printf("%i\n", fak);
			fak = fak * i;
			i = i + 1;
		} while (fak < g);
		return 0;
	}
	else
	{
		printf("Grenze größer als 1 gefordert");
		return 0;
	}
	return 0;
}

