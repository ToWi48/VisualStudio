#include <iostream>
#include <iomanip>
using namespace std;

class uhrzeit {
private:
    int h, m; // h: Stunden, m: Minuten
    void normalisiere()
    {
        while (m > 59)
        {
            m = m - 60; h = h + 1;
        }
        while (m < 0)
        {
            m = m + 60; h = h - 1;
        }
        h = h % 24;
    }
public:
    uhrzeit(int hh, int mm) : h(hh), m(mm) { normalisiere(); }
    int geth() const { return h; }
    int getm() const { return m; }

    // an dieser Stelle würde man die Operatoren programmieren
    uhrzeit& operator++()
    {
        //h++;
        m++;
        normalisiere();
        return *this;
    }

    // an dieser Stelle würde man die Operatoren programmieren
    uhrzeit& operator--()
    {
        //h--;
        m--;
        normalisiere();
        return *this;
    }

    bool operator !=(const uhrzeit& a) const
    {
        return (h != a.h || m != a.m);
    }

};
ostream& operator << (ostream& o, const uhrzeit& u)
{
    return o << setw(2) << setfill('0') << u.geth() << ":" << setw(2) << setfill('0') << u.getm();
}

int main()
{
    uhrzeit u1(9, 58), u2(10, 12);
    while (u1 != u2) // != Operator
    {
        cout << u1 << " bis " << u2 << endl;
        ++u1; --u2; // einstellige Prefix-Operatoren
    }
    cout << "res: " << u1 << " zu " << u2 << endl;
    return 0;
}