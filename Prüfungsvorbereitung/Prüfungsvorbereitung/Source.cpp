#include<iostream>

using namespace std;

int bitlevel_pruefung(uint8_t a, uint8_t b)
{
	uint8_t res = a | b;
	if (res == 0xFF)
		return 1;
	return 0;
}

// 2
class automat
{
private:
	int level = 0;
	int levelmax = 4;
public:
	automat()
	{

	}
	void ausschalten()
	{
		level = 0;
		cout << "Lampe wurde ausgeschaltet!" << endl;
	}
	void einschalten()
	{
		level = levelmax;
		cout << "Lampe wurde eingeschaltet!" << endl;
	}
	const int heller()
	{
		if (level == levelmax)
		{
			cout << "Lampe ist eingeschaltet!" << endl;
			return level;
		}

		level = level + 1;
		cout << "Lampe wurde auf Stufe "<< level << "/" << levelmax << " gesetzt!" << endl;

		return level;
	}
	const int dunkler()
	{
		if (level == 0)
		{
			cout << "Lampe ist ausgeschaltet!" << endl;
			return level;
		}

		level = level - 1;
		cout << "Lampe wurde auf Stufe " << level << "/" << levelmax << " gesetzt!" << endl;

		return level;
	}
};



int main()
{
	//cout << bitlevel_pruefung(0xAF,0x0) << endl;
	return 0;
}