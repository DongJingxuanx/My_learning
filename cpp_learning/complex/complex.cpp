#include <iostream>
#include complex.hpp
inline complex& complex::__dual(complex *ptr, const comple& comp1) {
    ptr->real_ = ptr->real_ + comp1.real_;
    ptr->imag_ = ptr->imag_ + comp1.imag_;
    return ptr;

}

inline complex& complex::operator += (const complex& comp1) {
    return __dual(this, comp1);
}

inline complex operator + (const complex& comp1, const complex& comp2) {
    return complex(comp1.real() + comp2.real(), 
    comp1.imag() + comp2.imag());
}

inline complex operator + (const double& comp1, const complex& comp2) {
    return complex(comp1 + real(comp2), imag(comp2));
}

ostreame operator << (ostreame &os, const complex &comp1) {
    return (os << '(' << real(x) << ',' << imag(x) <<')');
}