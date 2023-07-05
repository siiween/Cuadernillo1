#ifndef TCOMPLEJO_H
#define TCOMPLEJO_H

#include <iostream>
using namespace std;

class TComplejo {
private:
    double re; // PARTE REAL
    double im; // PARTE IMAGINARIA

public:
    TComplejo();
    TComplejo(double real);
    TComplejo(double real, double imaginario);
    TComplejo(const TComplejo& otro);
    ~TComplejo();

    TComplejo& operator=(const TComplejo& otro);

    TComplejo operator+(const TComplejo& otro);
    TComplejo operator-(const TComplejo& otro);
    TComplejo operator*(const TComplejo& otro);
    TComplejo operator+(double numero);
    TComplejo operator-(double numero);
    TComplejo operator*(double numero);

    bool operator==(const TComplejo& otro);
    bool operator!=(const TComplejo& otro);

    double Re();
    double Im();
    void Re(double real);
    void Im(double imaginario);

    double Arg();
    double Mod();

    friend ostream& operator<<(ostream& os, const TComplejo& complejo);
    friend TComplejo operator+(double numero, const TComplejo& complejo);
    friend TComplejo operator-(double numero, const TComplejo& complejo);
    friend TComplejo operator*(double numero, const TComplejo& complejo);
};

#endif
