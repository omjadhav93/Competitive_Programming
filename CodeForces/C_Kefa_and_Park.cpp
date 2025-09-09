#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<int>> grp;
vector<int> cat;
void dfs(int i, int par, int m, int cnt = 0){
    if(cnt > m) return;
    for(auto x: grp[i]){
        if(x != par){
            if(cat[x]) dfs(x, i,m, cnt+1);
            else dfs(x, i, m, 0);
        }
    }
    if(grp[i].size() == 1 && i != 0) ans++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cat.resize(n);
    for(int i = 0; i < n; i++) cin >> cat[i];
    grp.resize(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    if(cat[0]) dfs(0, -1, m, 1);
    else dfs(0, -1, m);
    cout << ans << "\n";
}