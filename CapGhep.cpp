/** 
*    Author :  Nguyen Tuan Vu
*    Created : 20.12.2021
**/

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define fx(i,j,n) for(int i=(j);i<=(n);i++)
#define fn(i,j,n) for(int i=(j);i>=(n);i--)
#define fi first
#define se second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define ALL(v) (v).begin(), (v).end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef pair <ll, ll> li;
typedef tuple <int, int, int> tup;

template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}

void file(){
	#define TASK "TASK"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

const int Mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const ll INFLL = 1e18 + 7;

int matchX[N], matchY[N], id[N], n, m, p, cur, users[N], res;
vector <int> adj[N];
bool DFS(int u){
	if (users[u] == cur) return false;
	users[u] = cur;
	for (auto v:adj[u]) 
		if (matchX[v] == 0 || DFS(matchX[v])){
			matchX[v] = u;
			matchY[u] = v;
			return true;
		}
	return false;
}
void solve()
{
	cin >> m >> n >> p;
	fx (i, 1, p) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	fx (i, 1, m) id[i] = i;
	random_shuffle(id + 1, id + m + 1);
	fx (i, 1, m){
		cur = id[i];
		if (!matchY[cur]) res += DFS(cur);
	}
	cout << res << '\n';
	fx (i, 1, n) cout << matchX[i] << ' ';
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	int T = 1;
	//cin>>T;
	while(T--)
	{
	solve();
	}
	return 0;
}
/*** DEBUG, DON'T LAZY AND DON'T ASK OTHERS MUCH ***/
/*
|----------------|
|   TRY  HARD    |
|----------------|
 (\_/)  ||
(=.-.=) ||
/> o  \>||
\  o  / ||
 \/ \/  ||
*/
