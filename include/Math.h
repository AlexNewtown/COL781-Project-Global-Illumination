#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <limits>

using namespace std;

const double epsilon = 1e-4;
const double infinity = std::numeric_limits<double>::max();

// bool solveQuadraticEquation(const double &a, const double &b, const double &c, double &r1, double &r2)
// {
//     double D = b * b - 4 * a * c;
//     if (D < 0)
//         return false;
//     else if (D == 0.0)
//         r1 = r2 = -0.5 * b / a;
//     else
//     {
//         double q = -0.5 * ((b < 0) ? (b - sqrt(D)) : (b + sqrt(D)));
//         r1 = q / a;
//         r2 = c / q;
//     }
//     return true;
// }

inline double clamp(double x)
{
    return (x < 0) ? 0 : (x > 1) ? 1 : x;
}

inline int toInt(double x)
{
    return int(pow(clamp(x), 1 / 2.2) * 255 + .5);
}

inline int log_2(int x)
{
    int n; 
    for (n=0; x>1; x>>=1,++n); 
    return n;
}

inline int median(int n)
{
    int h = log_2(n);
    int s = 1<<h;
    int d = n-s;
    int s2 = s/2;

    if(s2>0 && d>=s2){
        d = s2-1;
    }
    return s2+d;
}

template <typename T>
class vec3
{
public:
    T x, y, z;

public:
    vec3(T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}
    vec3 operator+(const vec3 &v) const
    {
        return vec3(x + v.x, y + v.y, z + v.z);
    }
    vec3 operator-(const vec3 &v) const
    {
        return vec3(x - v.x, y - v.y, z - v.z);
    }
    vec3 operator*(T val) const
    {
        return vec3(x * val, y * val, z * val);
    }

    T norm() const
    {
        return x * x + y * y + z * z;
    }

    vec3 &normalize()
    {
        T n = norm();
        if (n > 0)
        {
            (*this) = (*this) * (1 / sqrt(n));
        }
        return *this;
    }

    T dot(const vec3 &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    vec3 mult(const vec3 &v) const
    {
        return vec3(x * v.x, y * v.y, z * v.z);
    }

    vec3 cross(const vec3 &v) const
    {
        return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
};

typedef vec3<double> vec3d;
typedef vec3<int> vec3i;
#endif