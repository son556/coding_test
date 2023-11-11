#include<iostream>
#include<string>
#include <vector>
#include "fixedPoint.hpp"
#include <cmath>

using namespace std;

double find_sqrt(double x){ 
	double eps=1e-6; 
	double l=0,r=x,mid; 
	while(true){ 
		mid=(l+r)/2; 
		if(abs(mid*mid-x)<eps){ 
			break; 
		} 
		else if(mid*mid>x){ 
			r=mid; 
		} 
		else{ 
			l=mid; 
		} 
	} 
	return mid; 
}

int sqrt_int(int v)
{
	int res;
	
	res = 0;
	for (int i = 15; i >= 0; i--) {
		if ((res + (1 << i)) * (res + (1 << i)) <= v)
		  res += (1 << i);
	}
	return (res);
}

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

void showTest(fixedPoint p1, fixedPoint p2, string str, double a, double b)
{
    fixedPoint res;
    double ress;
    if (str == "+") {
        res = p1 + p2;
        ress = a + b;
    }
    else if (str == "-") {
        res = p1 - p2;
        ress = a - b;
    }
    else if (str == "*") {
        res = p1 * p2;
        ress = a * b;
    }
    else if (str == "/") {
        res = p1 / p2;
        ress = a / b;
    }
    else if (str == "sin") {
        res = p1.sin();
        ress = sin(a);
    }
    else if (str == "cos") {
        res = p1.cos();
        ress = cos(a);
    }
    else if (str == "tan") {
        res = p1.tan();
        ress = tan(a);
    }
    else if (str == "sqrt") {
        res = p1.sqrt();
        ress = sqrt(a);
    }
    else if (str == "no") {
        res = p1;
        ress = a;
    }
    cout.precision(10);
    cout << "real: " << ress << endl;
    cout << "test: " << res.getReal() << endl;
    cout << "real - test: " << ress - res.getReal() << endl;
}

int main() 
{
    fixedPoint fixFloat;
    fixedPoint fixFloat2;
    fixedPoint fixFloat3;
    fixedPoint res;

    double a = 115.8121007524642;
    double b = 120.4949011927283;
    double c = 14.1490756454914;
    double d = 0.755644;
    double e = 144;

    showTest(a, b, "*", a, b);
    fixFloat2 = 2;
    cout << fixFloat2.getReal() << endl;
    float t1 = 2;
    float t2 = 2;
    float t3 = t1 / (t1 - t2);
    float t4 = INFINITY;
    cout << t3 << endl;
    cout << t3 - t2 << endl;
    cout << t4 << endl; 

}
