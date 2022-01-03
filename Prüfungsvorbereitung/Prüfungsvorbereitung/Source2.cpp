
#define _USE_MATH_DEFINES
#include <math.h>

class Widerstand {
private:
    double R; // Widerstandswert in Ohm
public:
    Widerstand(double wert) : R(wert) {  }
    double LeseWert() const { return R; }
};


class Kondensator {
private:
    double C; // Kapazität in Farad
public:
    Kondensator(double wert) : C{ wert } { }
    double LeseWert() const { return C; }
};

class RCGlied : Widerstand, Kondensator
{
protected:
    double R = R;
    double C = R;
public:
    RCGlied(double gr, double gc) 
    {
        R = gr;
        C = gc;
    }

    RCGlied(Widerstand gr, Kondensator gc)
    {
        R = gr.LeseWert();
        C = gc.LeseWert();
    }

    double product()
    {
        return R * C;
    }


};

class Tiefpas : RCGlied
{
public:
    double Graenzfrequenz()
    {
        return 1 / (1 * M_PI * R * C);
    }
};