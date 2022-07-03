#ifndef _COMPLEX_
#define _COMPLEX_

class complex {
public:
    complex (double i = 0, r = 0): real_(r), imag_(i) 
    {}
    complex& operator += (const complex& comp1);
    double real() const {return real_;}
    double imag() const {return imag_;}

private:
    double imag_, real_;
    friend complex& _dual(complex *ptr, const comple& comp1);
};
