const int Mod = 1e9 + 7;
const int sz = 2;
struct MATRIX {
    int d[sz][sz];

    MATRIX() {
        memset(d, 0, sizeof d);
    }

    friend MATRIX operator * (MATRIX A, MATRIX B) {
        MATRIX C;
        for (int i = 0; i < sz; i++) 
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    C.d[i][j] = (C.d[i][j] + 1ll * A.d[i][k] * B.d[k][j] % Mod) % Mod;
        return C;
    }

    friend MATRIX operator ^ (MATRIX A, long long k) {
        if (k == 0) {
            MATRIX tmp;
            for (int i = 0; i < sz; i++)
                for (int j = 0; j < sz; j++)
                    tmp.d[i][j] = (i == j);
            return tmp;
        }

        MATRIX res;
        res = A ^ (k / 2);
        res = res * res;

        if (k & 1) res = res * A;
        return res;
    }
} fst, mul;
