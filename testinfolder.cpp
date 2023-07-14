/** Author : Nguyen Tuan Vu **/
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#define MASK(x) ((1ll)<<(x))
#define BIT(x, i) (((x)>>(i))&(1))
#define ALL(v)  (v).begin(), (v).end()
#define REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define FORand(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i)
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

ofstream inp;
char Name_file[] = "";
char exe_file[100] = "";
char inp_file[100] = "";
char out_file[100] = "";
string folder = "Test00";

///FILE NAME
void Make_file_name() {
    // Đặt tên file ở đây
    #define TASK ""
    strcpy(exe_file, Name_file);
    strcpy(inp_file, Name_file);
    strcpy(out_file, Name_file);

    strcat(exe_file, TASK".exe");
    strcat(inp_file, TASK".inp");
    strcat(out_file, TASK".out");

}

/// Viết phần sinh test ở đây
void make_test(int test) {
    // inp : xuất dữ liệu
    // Rand: random số trong khoảng
}

void run_answer() {
    system(exe_file);
}

void Rename_file(int test)
{
    folder[4] = test / 10 + 48;
    folder[5] = test % 10 + 48;

    mkdir(&folder[0]);
    string output_path = folder + "\\" + inp_file;
    CopyFile(inp_file, &output_path[0], false);
    
    output_path = folder + "\\" + out_file;
    CopyFile(out_file, &output_path[0], false);
}

int main()
{
    Make_file_name();
    const int NTEST = 50;
    FOR(test, 1, NTEST) {
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
