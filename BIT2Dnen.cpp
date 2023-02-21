struct BIT{

    int n;

    vector<vector<int>> node, bit;

    void RESIZE(int x){
        n = x;
        node.resize(n + 1);
        bit.resize(n + 1);
    }

    void fakeUpdate(int x, int y){
        while(x <= n){
            node[x].PB(y);
            x += (x & -x);
        }
    }

    void fakeGet(int x, int y){
        while(x){
            node[x].PB(y);
            x -= (x & -x);
        }
    }

    void REMAKE(){
        for(int i = 0; i <= n; i++){
            sort(ALL(node[i]));
            node[i].resize(unique(ALL(node[i])) - node[i].begin());
            bit[i].resize((int) node[i].size() + 1, 0);
        }
    }

    void Update(int x, int y, int w){
        for(int i = x; i <= n; i += (i & -i)){
            for(int j = lower_bound(ALL(node[i]), y) - node[i].begin() + 1; j <= (int) node[i].size(); j += (j & -j)){
                maximize(bit[i][j], w);
            }
        }
    }

    int Get(int x, int y){
        int ans = 0;
        for(int i = x; i; i -= (i & -i)){
            for(int j = lower_bound(ALL(node[i]), y) - node[i].begin() + 1; j ; j -= (j & -j)){
                maximize(ans, bit[i][j]);
            }
        }
        return ans;
    }
} BIT;
