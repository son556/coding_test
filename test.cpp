#include<iostream>
#include<string>
#include <vector>
#include "fixedPoint.hpp"
#include <cmath>

using namespace std;

unsigned long long power2(int n)
{
    unsigned long long res = 1;
    for (int i = 0; i < n; i++)
        res *= 2;
    return res;
}

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = * ( long * ) &y;                     // evil floating point bit level hacking
	i = 0x5f3759df - ( i >> 1 );             // what the fuck?
	y = * ( float * ) &i;
	y = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
	y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed
    y  = y * ( threehalfs - ( x2 * y * y ) );
    y  = y * ( threehalfs - ( x2 * y * y ) );

	return y;
}

int main() 
{
    fixedPoint fixFloat;
    fixedPoint fixFloat2;
    fixedPoint fixFloat3;
    fixedPoint res;

    double a = 147280.889;
    double b = 2567;
    double c = 0.654984;
    double d = 0.755644;
    double e = 144;

    // fixFloat.setNumber(c);
    // fixFloat2.setNumber(d);
    // fixFloat3.setNumber(e);

    // res = fixFloat / fixFloat2;
    // cout << "real /: " << c / d << endl;
    // cout << "test: " << (res + fixFloat3).getReal() << endl;
    // cout << "test /: " << res.getReal() << endl << endl;

    // double radi = a * M_PI / 180;
    // fixFloat.setNumber(radi);
    // fixFloat2.setNumber(3.141592);
    // b = 3.141592;
    // res = fixFloat % fixFloat2;
    // cout << "%: " << res.getReal() << endl << endl;

    // res = fixFloat.sin();
    // a = res.getReal();
    // cout << "real sin: " << sin(radi) << endl;
    // cout << "test sin: " << res.getReal() << endl;
    // cout << "real - test: " << sin(radi) - res.getReal() << endl << endl;
    
    // res = fixFloat.cos();
    // b = res.getReal();
    // cout << "real cos: " << cos(radi) << endl;
    // cout << "test cos: " << res.getReal() << endl;
    // cout << "real - test: " << sin(radi) - res.getReal() << endl << endl;

    // res = fixFloat.tan();
    // cout << "real tan: " << tan(radi) << endl;
    // cout << a / b << endl;
    // cout << "test tan: " << res.getReal() << endl;
    // cout << "real - test: " << tan(radi) - res.getReal() << endl << endl;

    // fixFloat2.setNumber(-1.1f);
    // res = fixFloat2.round();
    // cout << "real: " << roundf(-1.1f) << endl;
    // cout << "test: " << res.getReal() << endl;
    fixFloat.setNumber(e);
    cout.precision(10);
    cout << "real sqrt: " << sqrt(25555) << endl;
    cout << "test: " << 1 / Q_rsqrt(25555) << endl;
    cout << "test sqrt: " << fixFloat.sqrt().getReal() << endl;
}
