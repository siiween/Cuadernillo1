#include "tcomplejo.h"
#include <cmath>

TComplejo::TComplejo() : re(0), im(0) {}

TComplejo::TComplejo(double real) : re(real), im(0) {}

TComplejo::TComplejo(double real, double imaginario) : re(real), im(imaginario) {}

TComplejo::TComplejo(const TComplejo& otro) : re(otro.re), im(otro.im) {}

TComplejo::~TComplejo() {}

TComplejo& TComplejo::operator=(const TComplejo& otro) {
    if (this != &otro) {
        re = otro.re;
        im = otro.im;
    }
    return *this;
}

TComplejo TComplejo::operator+(const TComplejo& otro) {
    TComplejo resultado(re + otro.re, im + otro.im);
    return resultado;
}

TComplejo TComplejo::operator-(const TComplejo& otro) {
    TComplejo resultado(re - otro.re, im - otro.im);
    return resultado;
}

TComplejo TComplejo::operator*(const TComplejo& otro) {
    TComplejo resultado(re * otro.re - im * otro.im, re * otro.im + im * otro.re);
    return resultado;
}

TComplejo TComplejo::operator+(double numero) {
    TComplejo resultado(re + numero, im);
    return resultado;
}

TComplejo TComplejo::operator-(double numero) {
    TComplejo resultado(re - numero, im);
    return resultado;
}

TComplejo TComplejo::operator*(double numero) {
    TComplejo resultado(re * numero, im * numero);
    return resultado;
}

bool TComplejo::operator==(const TComplejo& otro) {
    return (re == otro.re) && (im == otro.im);
}

bool TComplejo::operator!=(const TComplejo& otro) {
    return !(*this == otro);
}

double TComplejo::Re() {
    return re;
}

double TComplejo::Im() {
    return im;
}

void TComplejo::Re(double real) {
    re = real;
}

void TComplejo::Im(double imaginario) {
    im = imaginario;
}

double TComplejo::Arg() {
    return atan2(im, re);
}

double TComplejo::Mod() {
    return sqrt(re * re + im * im);
}

std::ostream& operator<<(std::ostream& os, const TComplejo& complejo) {
    os << "(" << complejo.re << " " << complejo.im << ")";
    return os;
}

TComplejo operator+(double numero, const TComplejo& complejo) {
    TComplejo resultado(complejo.re + numero, complejo.im);
    return resultado;
}

TComplejo operator-(double numero, const TComplejo& complejo) {
    TComplejo resultado(numero - complejo.re, -complejo.im);
    return resultado;
}

TComplejo operator*(double numero, const TComplejo& complejo) {
    TComplejo resultado(numero * complejo.re, numero * complejo.im);
    return resultado;
}
