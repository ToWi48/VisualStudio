#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "TomHeader.h"
#include <string.h>

int n = sizeof(double);
double werte_praktisch_gleich[] = { 9.9995, 10.0, 10.0002, 9.99991 };
double werte_sort_0123[] = { 0, 1, 2, 3 };
double werte_unsortiert[] = { 1, 3, 2, 0 };
double werte_maxabw_0komma1[] = { 1.0, 1.05, 0.95, 1.01 };
double werte_gleiche_vz[] = { 0, 1, 2, 3 };
double werte_verschiedene_vz[] = { -1, 0, 1, 2 };

int alle_gleich(double* feld, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (abs(feld[i] - feld[i - 1]) > 0.001)
			return 0;
	}
	return 1;
}

int alle_vz_gleich(double* feld, int n)
{
	if (n < 2)
		return 0;
	int vz0 = 1;
	int vzp = 1;
	int vzn = 1;
	for (int i = 0; i < n; i++)
	{
		if (feld[i] <= 0)
			vzp = 0;
		if (feld[i] >= 0)
			vzn = 0;
		if (feld[i] != 0)
			vz0 = 0;
	}
	if ((vzp == 1 && vzn == 0 && vz0 == 0) || (vzp == 0 && vzn == 1 && vz0 == 0) || (vzp == 0 && vzn == 0 && vz0 == 1))
		return 1;
		
	return 0;
}

double max_delta(double* feld, int n)
{
	double currentMax, currentMin = 0;
	for (int i = 0; i < n; i++)
	{
		if (feld[i] > currentMax)
			currentMax = feld[i];

		if (feld[i] < currentMin)
			currentMin = feld[i];
	}
	return currentMax - currentMin;
}