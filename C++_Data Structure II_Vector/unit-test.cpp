#include "vector.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

using std::cout;
using std::endl;
using std::stringstream;

// A Function to test if two doubles are "equal"
bool DoubleEquals(double a, double b, double epsilon = 1e-6);

int main(int argc, char* argv[]) {
    // Testing empty vector (Comment to test card vec_6
    Vector a(0);
    assert(!a.IsValid());
    cout << "Is Valid passed" << endl;

    // Testing a vector in 2D (Comment to test card vec_6
    Vector b(2);
    assert(b.Dimensions() == 2);

    // ---------------------------------------
    // Why do we need to use this function????
    // DoubleEquals(a,b)
    // Testing default setting of components of 2D Vector
    // Testing operator[] overload
    assert(DoubleEquals(b[0], 0.0));
    assert(DoubleEquals(b[1], 0.0));
//    assert(b[0] == 0.0);
//    assert(b[1] == 0.0);
    // Testing write-to operator[] overload
    b[0] = 1.5;
    b[1] = -1.5;
    assert(DoubleEquals(b[0], 1.5));
    assert(DoubleEquals(b[1], -1.5));
//    assert(b[0] == 1.5);
//    assert(b[1] == -1.5);
    // Testing IO with streams
    // It would be nice to overload << and >>
    stringstream stream;
    b.Write(stream);
    assert(stream.str() == "2 1.5 -1.5");
    stream.clear();
    stream.str("2 4.0 0.0");
    b.Read(stream);
    assert(b.Dimensions() == 2);
    assert(DoubleEquals(b[0], 4.0));
    assert(DoubleEquals(b[1], 0.0));
//    assert(b[0] == 4.0);
//    assert(b[1] == 0.0);
    stream.clear();

    // Testing constructors that take in an array
    double data1[] = {1, 2, 3};
    double data2[] = {-1, 2, 1};
    Vector c(3, data1);
    assert(c.Dimensions() == 3);
    assert(DoubleEquals(c[0], 1.0));
    assert(DoubleEquals(c[1], 2.0));
    assert(DoubleEquals(c[2], 3.0));
//    assert(c[0] == 1.0);
//    assert(c[1] == 2.0);
//    assert(c[2] == 3.0);

    Vector d(3, data2);
    assert(d.Dimensions() == 3);
    assert(DoubleEquals(d[0], -1.0));
    assert(DoubleEquals(d[1], 2.0));
    assert(DoubleEquals(d[2], 1.0));
//    assert(d[0] == -1.0);
//    assert(d[1] == 2.0);
//    assert(d[2] == 1.0);

    Vector e(d);
    assert(e.Dimensions() == 3);
    assert(DoubleEquals(e[0], -1.0));
    assert(DoubleEquals(e[1], 2.0));
    assert(DoubleEquals(e[2], 1.0));
//    assert(e[0] == -1.0);
//    assert(e[1] == 2.0);
//    assert(e[2] == 1.0);

    assert(e == d);
    assert(e != c);

    Vector f(0);
    f = c;
    assert(f.Dimensions() == 3);
    assert(DoubleEquals(f[0], 1.0));
    assert(DoubleEquals(f[1], 2.0));
    assert(DoubleEquals(f[2], 3.0));
//    assert(f[0] == 1.0);
//    assert(f[1] == 2.0);
//    assert(f[2] == 3.0);

    Vector g(3);
    Vector h(3);
    Vector i(3);
    g[0] = 2.5;
    g[1] = 1.2;
    g[2] = 0.0;
    h[0] = -0.5;
    h[1] = 0.3;
    h[2] = 4.0;
    i = g + h;
    assert(i.IsValid());
    assert(DoubleEquals(i[0], 2.0));
    assert(DoubleEquals(i[1], 1.5));
    assert(DoubleEquals(i[2], 4.0));
//    assert(i[0] == 2.0);
//    assert(i[1] == 1.5);
//    assert(i[2] == 4.0);

    i = g - h;
    assert(i.IsValid());
    assert(DoubleEquals(i[0], 3.0));
    assert(DoubleEquals(i[1], 0.9));
    assert(DoubleEquals(i[2], -4.0));
//    assert(i[0] == 3.0);
//    assert(i[1] == 0.9);
//    assert(i[2] == -4.0);

    Vector j(3);
    Vector k(3);
    j[0] = 1.0;
    j[1] = -1.2;
    j[2] = 0.0;
    k=j*-1;
    assert(k.IsValid());
    assert(DoubleEquals(k[0], -1.0));
    assert(DoubleEquals(k[1], 1.2));
    assert(DoubleEquals(k[2], 0.0));
//    assert(k[0] == -1.0);
//    assert(k[1] == 1.2);
//    assert(k[2] == 0.0);
    cout<<j.ToString()<<endl;

    Vector l(3);
    Vector m(3);
    l[0]=1.0;
    l[1]=-1.2;
    l[2]=0.0;
    m=l.operator-();
    assert(m.IsValid());
    assert(DoubleEquals(m[0], -1.0));
    assert(DoubleEquals(m[1], 1.2));
    assert(DoubleEquals(m[2], 0.0));
//    assert(k[0] == -1.0);
//    assert(k[1] == 1.2);
//    assert(k[2] == 0.0);
    cout<<m.ToString()<<endl;

    Vector w(3);
    Vector z(3);
    int _dataVal=3;
    w[0] = 1.0;
    w[1] = -1.2;
    w[2] = 0.0;
    z=w*_dataVal;
    assert(k.IsValid());
    assert(DoubleEquals(z[0], 3.0));
    assert(DoubleEquals(z[1], -3.6));
    assert(DoubleEquals(z[2], 0.0));
//    assert(k[0] == -3.0);
//    assert(k[1] == 3.6);
//    assert(k[2] == 0.0);
    cout<<z.ToString()<<endl;

    Vector n(3);
    Vector o(3);
    n[0] = 1.0;
    n[1] = -1.2;
    n[2] = 0.0;
    o=n.operator*(2.0);
    assert(o.IsValid());
    assert(DoubleEquals(o[0], 2.0));
    assert(DoubleEquals(o[1], -2.4));
    assert(DoubleEquals(o[2], 0.0));
    cout<<o.ToString()<<endl;

    DoubleEquals(g.EuclidianDistance(h), sqrt(25.81));
    DoubleEquals(g.EuclidianDistance(g), 0);
//    assert(g.EuclidianDistance(h) == sqrt(25.81));
//    assert(g.EuclidianDistance(g) == 0);

    cout << "All unit tests passed" << endl;

    return 0;
}
bool DoubleEquals(double a, double b, double epsilon){
    return abs(a - b) < epsilon;
}
