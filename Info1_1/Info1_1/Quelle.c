#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

// Primzahl
//int main(void)
//{
//	int z;
//	printf("Zahl:");
//	scanf("%d", &z);
//
//	if (z > 1)
//	{
//		int i = z - 1;
//		while (i > 1)
//		{
//			if ( (z % i) == 0)
//			{
//				printf("%d ist keine Primzahl!\n", z);
//				return 0;
//			}
//			i = i - 1;
//		}
//	};
//
//	printf("Zahl %d ist eine Primzahl\n", z);
//	return 0;
//}

//Schaltjahr
//int main(void)
//{
//	int j1, j2;
//	printf("Zahl:");
//	scanf("%d" "%d", &j1, &j2);
//
//	getLeapYearsFromIntervall(j1, j2);
//
//	return 0;
//};
//
//int getLeapYearsFromIntervall(int j1, int j2)
//{
//	if (j1 >= 1582 && j1 <= j2)
//	{
//		printf("Schaltjahre zwischen %d und %d waren:\n", j1, j2);
//		for (int i = j1; i <= j2; i++)
//		{
//			if ((i % 4 == 0) && ((i % 100 != 0) || (i % 400 == 0)))
//			{
//				printf("%d\n", i);
//			};
//		};
//		printf("Ende\n");
//	}else
//		printf("Fehler, Jahre nicht im Intervall!\n");;
//	return 0;
//};

// Logarithmus#
//double powTom(double x, double y)
//{
//	double back = 1;
//	for (int i = 1; i <= y; i++)
//	{
//		back = back * x;
//	}
//	return back;
//}
//
//double fabsTom(double x)
//{
//	double back = x;
//	if (x < 0)
//		back = back * -1;
//	return back;
//}
//
//double logn_approx(double x, double e)
//{
//	if (x >= 0 && x <= 2)
//	{
//		printf("toll: %f\n", x);
//		double ln = 0;
//		double add = e + 1;
//		for (int i = 1; fabsTom(add) > e; i++)
//		{
//			add = powTom((-1), ((double)i - 1)) * powTom((x - 1), (double)i) / i;
//			printf("add: %lf\n", add);
//			ln = ln + add;
//		};
//		
//		return ln;
//	}
//	else
//		return 0;
//}
//
//int main(void)
//{
//	double x, e;
//	printf("Zahl:");
//	scanf("%lf" "%lf", &x, &e);
//
//	x = logn_approx((double)x, (double)e);
//	
//	printf("Ergebniss: %lf\n", x);
//}

// String

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 80

void entferne_zeilenumbruch(char* s)
{
	// Abschlie�endes '\n' Zeichen entfernen
	if (strlen(s) > 0 && s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
}

int main()
{
	char eingabe[LEN];
	int i = 0;

	printf("Eingabe einer Zeichenkette\n>");
	fgets(eingabe, LEN, stdin);

	entferne_zeilenumbruch(eingabe);

	printf("Ihre Eingabe lautet: %s\n", eingabe);

	for (i = 0; i < strlen(eingabe); i++)
	{
		int e = eingabe[i];

		printf("\n Das ASCII-Zeichen fuer %c ist %i: \n", eingabe[i], eingabe[i]);
	}



	return 0;
}

// enum

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 80

int main(void)
{
    enum biersorte { Carlsberg, Tuborg, Faxe };
    enum biersorte b_heute, b_morgen;

    printf("\nAufzaehlungstyp ...\n");

    b_heute = Tuborg;
    b_morgen = Carlsberg;

    printf("Ausgabe: %i", Faxe);
    /*if (b_heute == b_morgen)
        printf("Gleiche Biersorte\n");
    else
        printf("Verschiedene Biere\n");*/

    return 0;
}

//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 80

int a = 1;
int b = 2;

void berechne();

int main(void)
{
	int feld[2] = { 5, 6 };
	berechne(feld, 1);
	return 0;
}

void berechne(int a[], int i)
{

}

// Primzahlen

int main()
{
	int z = 0;
	printf("Zu prüfende Zahl: ");
	scanf("%i", &z);

	int r = istPrimzahl(z);

	if (r == 1)
		printf("%i ist eine Primzahl", z);
	else
		printf("%i ist keine Primzahl", z);

	return 0;
}

int istPrimzahl(int z)
{
	if (z <= 1)
		return 0;
	else
	{
		for (int i = 2; i < z; i++)
		{
			double rest = (z % i);
			if (rest == 0)
				return 0;
		}
		return 1;
	}
}

 //Bruno

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double powTom(double b, double e)
{
	double r = 1;
	for (int i = 1; i <= e; i++)
	{
		r = r * b;
	}
	return r;
}

double fabsTom(double x)
{
	if (x < 0)
		return x * -1;
	else
		return x;
}

double logn_approx(double x, double e, int* valid)
{
	if (x > 0 && x < 2 && e < 1 && e > 0)
	{
		double dif = 1;
		double r = 0;
		for (int i = 1; fabsTom(dif) > e; i++)
		{
			dif = powTom((-1), (i - 1)) * powTom((x - 1), i) / (i);
			r = r + dif;
		}
		return r;
	}
	else
		*valid = 0;
		return 0;
}

int main()
{
	double x, e;
	int valid = 1;

	scanf("%lf %lf", &x, &e);

	double r = logn_approx(x, e, &valid);

	printf("isValid: %i\n", valid);
	printf("Dein Ergebnis ist: %lf", r);
	return 0;
}

// Mittelwert

double x[10] = { 2.1, 2.2, 1.0, 3.1, 1.5, 4.3, 2.0, 1.55, 3.21, 0 };
int n = 10;

double mittelwert(double x[], int n)
{
	double m = 0;
	for (int i = 0; i <= (n - 1); i++)
	{
		m = m + x[i];
	}
	return m / n;
}

double standardabweichung(double x[], int n)
{
	double m = 0;
	double mw = mittelwert(x, n);
	for (int i = 0; i <= (n - 1); i++)
	{
		m = m + pow(x[i] - mw, 2);
	}
	
	return sqrt(m / (n - 1));
}

int main()
{
	double r[10];
	for (int i = 0; i <= (n - 1); i++)
	{
		r[i] = (x[i] - mittelwert(x, n))/standardabweichung(x,n);
	}

	printf("%lf\n", mittelwert(r, n));
	printf("%lf", standardabweichung(r, n));

	return 0;
}

// Sinus

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define N 100
// M_PI als Konstante für pi verfügbar

void init_sinus(double x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = sin((2 * i * M_PI) / n);
	}
}

int main()
{
	const int n = N;
	double w[N];

	init_sinus(w, n);

	for (int i = 0; i <= (n - 1); i++)
	{
		printf("%lf\n", w[i]);
	}

	return 0;
}

// Zeiger

#include <stdio.h>
#include <stddef.h>

void ausgabe(double* a)
{
	printf("Adresse: %#x Wert: %lf\n", a, *a);
}

int main()
{
	double wertA = 8.15, wertB = 47.11;
	double *z_wertA, *z_wertB;
	z_wertA = &wertA;
	z_wertB = &wertB;

	/*ausgabe(z_wertA);
	ausgabe(z_wertB);*/

	/*printf("%#x\n", z_wertA);
	printf("%#x\n", z_wertB);*/

	int n = 7;
	double feld[7] = { 6.45, 9.60, 17.94, 32.76, 43.21, 89.15, 96.25 };
	/*printf("%d\n", feld);
	printf("%d\n", &feld[1]);*/

	double *adrA = NULL;
	double *adrB = NULL;
	for (int i = 0; i < n; i++)
	{
		if (feld[i] > wertA)
		{
			adrA = &feld[i];
			break;
		}
	}

	for (int i = (n-1); i >= 0; i--)
	{
		if (feld[i] < wertB)
		{
			adrB = &feld[i];
			break;
		}
	}

	/*ausgabe(adrA);
	ausgabe(adrB);*/

	double* adresse = &feld[2];
	adresse = adresse + 2;

	for (double *i = (adrA+1); i < adrB; i++)
	{
		printf("%lf\n", *i);
		//printf("Toll\n");
	}
	return 0;
}

// Strings

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 80

void entferne_zeilenumbruch(char* s[])
{
	// Abschlie�endes '\n' Zeichen entfernen
	if (strlen(s) > 0 && s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
}

void mani(char *s)
{
	char a = 'F';
	char b = 'L';
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == a)
			s[i] = b;
	}
}

int main()
{
	char eingabe[LEN];

	printf("Eingabe einer Zeichenkette\n>");
	fgets(eingabe, LEN, stdin);

	entferne_zeilenumbruch(eingabe);

	mani(eingabe);

	int length = strlen(eingabe);
	int gross = 0;
	int klein = 0;

	printf("Ihre Eingabe lautet: %s, Länge: %i\n", eingabe, length);

	for (int i = 0; i < length; i++)
	{
		if (eingabe[i] >= 65 && eingabe[i] <= 90)
			gross++;

		if (eingabe[i] >= 97 && eingabe[i] <= 122)
			klein++;

		printf("Zeichen: %c ASCII: %i\n", eingabe[i], eingabe[i]);
	}

	printf("Großbuchstaben: %i, Kleinbuchstaben: %i\n", gross, klein);

	return 0;
}

// Structs

struct RGB { unsigned char Red, Green, Blue; };
typedef struct RGB RGB;

unsigned char getVolume(RGB LED)
{
	return (0.299 * LED.Red + 0.587 * LED.Green + 0.114 * LED.Blue);
}

int main()
{	
	struct RGB Rot = { 255,0,0 };
	struct RGB Gruen = { 0,255,0 };
	struct RGB Blau = { 0,0,255 };
	const struct RGB Weiss = { 255,255,255 };
	const struct RGB Schwarz = { 0,0,0 };

	int length = 5;
	struct RGB feld[5] = {{255,255,255}, {255,0,0}, {0,255,0}, {0,0,255}, {0,0,0}};

	printf("Nummer	Rot	Gruen	Blau	Helligkeit\n");
	for (int i = 0; i < length; i++)
	{
		printf("%i:	%i	%i	%i	%i\n", i+1, feld[i].Red, feld[i].Green, feld[i].Blue, getVolume(feld[i]));
	}
	

	//printf("%d", sizeof(char));

	return 0;
}

// String man
void bearbeite(char* text)
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == 'o')
			text[i] = 'i';
	}
}

int main()
{
	char text[] = "Tom ist Cool";
	bearbeite(text);

	printf("%s", text);
	return 0;
}