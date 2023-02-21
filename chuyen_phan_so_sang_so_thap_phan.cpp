#include <iostream>
#include <cstdio>
using namespace std;
using lli = long long;

lli gcd(lli a, lli b)
{
    while (b != 0)
    {
        lli r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    lli x, y;
    cin >> x >> y;
    cout << x / y << '.'; //Phần nguyên
    //In phần hữu hạn
    x %= y;
    while (x != 0 && gcd(y, 10) != 1)
    {
        x *= 10;
        lli d = gcd(x, y);
        x /= d;
        y /= d;
        cout << x / y;
        x %= y;
    }
    //In phần tuần hoàn
    cout << '(';
    lli z = x;
    do
    {
        x *= 10;
        cout << x / y;
        x %= y;
    }
    while (x != z);
    cout << ')';
}
