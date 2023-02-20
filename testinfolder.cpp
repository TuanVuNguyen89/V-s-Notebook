// testinfolder
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define maxc 1000000003
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(x, i) (((x) >> (i)) & 1)


using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) {
    return l + rng() % (r - l + 1);
}

typedef long long ll;
typedef long double ld;

ofstream inp;
char Name_file[] = "";
char exe_file[100] = "";
char inp_file[100] = "";
char out_file[100] = "";
string folder = "Test00";

void make_test( int test)
{
    int n;
    if(test <= 15){
        n = rd(1, 100);
        int G = rd(1, n);
        int k = 1;
        fi << n << " " << G << " " << k << "\n";
    }
    else if(test <= 30){
        n = rd(500, 1000);
        int G = rd(50, n);
        int k;
        if(test & 1) k = 1;
        else k = 2;
        fi << n << " " << G << " " << k << "\n";
    }
    else{
        n = rd(1500, 1500);
        int G = rd(100, n);
        int k;
        if(test & 1) k = 1;
        else k = 2;
        fi << n << " " << G << " " << k << "\n";
    }
    for(int i = 1; i <= n; i++){
        fi << rd(1, 1000000) << " ";
    }
}

void run_answer()
{
    system(exe_file);
}

void Rename_file(int test)
{
    folder[4] = test/10 + 48;
    folder[5] = test%10 + 48;
    mkdir(&folder[0]);
    string output_path = folder + "\" + inp_file;
    CopyFile(inp_file, &output_path[0], false);
    output_path = folder + "\" + out_file;
    CopyFile(out_file, &output_path[0], false);
}

void Make_file_name()
{
	#define TASK ""
    strcpy(exe_file,Name_file);
    strcpy(inp_file,Name_file);
    strcpy(out_file,Name_file);

    strcat(exe_file,TASK".exe");
    strcat(inp_file,TASK".inp");
    strcat(out_file,TASK".out");

}

int main()
{
    Make_file_name();
    For(test,1,50)
    {
        cout << test << endl;
        inp.open(inp_file);
        make_test(test);
        inp.close();
        run_answer();
        Rename_file(test);
    }
    DeleteFile(inp_file);
    DeleteFile(out_file);
    return 0;
}
