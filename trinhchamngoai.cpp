// trinh cham ngoai
#include "testlib_themis_cms.h"
#include <bits/stdc++.h>

using namespace std;

// inf, ouf, ans
int main(int argc, char* argv[]) {
#ifdef THEMIS
    registerTestlibThemis(".inp", ".out");
#else
    registerTestlibCmd(argc, argv);
#endif // THEMIS

    // quitf(_wa, "ERROR", ...)
    // quitf(_ok, "SUCCESS", ...)
}
