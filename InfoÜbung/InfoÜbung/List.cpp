#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> zahlen;
    list<int>::iterator lIter; // Iterator definieren

    srand(0);
    for (int i = 0; i < 10; i++)
    {
        zahlen.push_back(rand() % 9 + 1);
    }
    // Durchlaufen und anzeigen
    for (lIter = zahlen.begin(); lIter != zahlen.end(); ++lIter)
    {
        cout << *lIter << endl;
    }
    // vor jeder 8 eine -1 einfügen und jede 2 löschen
    for (lIter = zahlen.begin(); lIter != zahlen.end(); ++lIter)
    {
        if (8 == *lIter)
        {
            zahlen.insert(lIter, -1);
        }
        else if (2 == *lIter)
        {
            lIter = zahlen.erase(lIter);
        }
    }
    // Durchlaufen und anzeigen
    for (lIter = zahlen.begin(); lIter != zahlen.end(); ++lIter)
    {
        cout << *lIter << endl;
    }
}