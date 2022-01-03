#include<iostream>
#include<ostream>

using namespace std;

class ganzzahl
{
protected:
    unsigned int z;

public:
    ganzzahl() : z(0) {}
    ganzzahl(int startwert) : z(startwert) {}
    int lese() const { return z; }
    void next() { z = z + 1; }

    // Methoden unten werden als ausserhalb definiert angenommen

    bool prim() const; // Entscheidung, ob z Primzahl ist.
    bool gerade() const; // Entscheidung, ob z eine gerade Zahl ist.
    bool ungerade() const; // Entscheidung, ob z eine ungerade Zahl ist.                       
};

class geradezahl : ganzzahl
{
private:
    int z = 0;
public:
    geradezahl(int startvalue)
    {
        z = startvalue;
    }

    int next()
    {
        while (!gerade())
        {
            z++;
        }
        return z;
    }
};

ostream& operator << (ostream& s, ganzzahl& gz) { return s << gz.lese(); }

int main()
{
    geradezahl gz = geradezahl(2);
    while (gz.next() <= 101)
    {
        cout << gz.next() << endl;
    }
    return 0;
}