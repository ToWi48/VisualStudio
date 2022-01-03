// Informatik2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Vehicle.h"

using namespace std;

int main()
{
    cout << "Hallo Tom :)" << endl;
    
    // add new vehicle
    vehicle polo = vehicle("Polo", "der ist toll", 5);
    trailer weidemann = trailer(50, 56);


    vector2 a = vector2(1,1);
    vector2 b = vector2(1,1);

    vector2 res = a + b;

    cout << res.length() << endl;

   /* cout << get<0>(polo.getInfo()) << endl;
    cout << get<1>(polo.getInfo()) << endl;
    cout << get<2>(polo.getInfo()) << endl;*/
    /*weidemann.tip();*/
    //cout << get<0>(weidemann.getInfo()) << endl;
    //cout << get<1>(weidemann.getInfo()) << endl;
    //cout << get<2>(weidemann.getInfo()) << endl;
}