/**
*    Author :  Nguyen Tuan Vu
*    Created : 
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define MASK(x) ((1ll)<<(x))
#define BIT(x, i) (((x)>>(i))&(1))
#define ALL(v)  (v).begin(), (v).end()
#define REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define FORD(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i)
#define db(val) "["#val" = "<<(val)<<"] "
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {return l + rng() % (r - l + 1);}

void sinh(int test) {
    ofstream os;
    ofstream inp((to_string(test) + ".inp").c_str());
    // viết code sinh test ở đây
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));

    int NTEST = 100;
    FOR(i, 1, NTEST) {
        sinh(i);
    }

    return 0;
}
