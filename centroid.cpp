// centroid
/**
*    Author :  Nguyen Tuan Vu
*    Created : 30.06.2022
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

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
int Rand(int l, int r) {return l + rng() % (r - l + 1);}

void file(){
	#define TASK ""
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

const int N = 1e5 + 5;
int n, sz[N], root;
vector <int> cadj[N], adj[N];
bool vis[N];

void dfs(int u, int par) {
    sz[u] = 1;

    for (auto v : adj[u]) if (par != v && !vis[v]) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int par, int n) {
    for (auto v : adj[u]) if (par != v && sz[v] > n / 2 && !vis[v]) {
        return centroid(v, u, n);
    }

    return u;
}

void build(int u, int par) {
    dfs(u, par);
    int c = centroid(u, par, sz[u]);
    if (par == -1) root = c;
    else {
        cadj[par].push_back(c);
        cadj[c].push_back(par);
    }

    vis[c] = 1;
    for (auto v : adj[c]) if (!vis[v] && par != v) {
        build(v, c);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(1, -1);
//    cout << '\n';
//    cout << root << '\n';
//    for (int i = 1; i <= n; i++) {
//        cout << i << '\n';
//        for (auto v : cadj[i]) cout << v << ' ';
//        cout << '\n';
//    }
	return 0;
}
//15
//15 14
//14 11
//11 13
//11 9
//9 6
//6 3
//3 2
//2 1
//3 4
//3 5
//5 8
//5 7
//7 10
//12 10
