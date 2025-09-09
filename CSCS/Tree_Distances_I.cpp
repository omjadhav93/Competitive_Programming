#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grp(n+1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    function<int(int,int)> dfs = [&](int node, int par) {
        if(dp[node][par]) return dp[node][par];
        dp[node][par] = 1;
        for(auto &child : grp[node]) {
            if(child != par){
                int ch = dfs(child, node);
                dp[node][par] = max(dp[node][par], 1 + ch);
            }
        }
        return dp[node][par];
    };
    for(int i = 1; i <= n; i++) {
        cout << dfs(i,0) - 1 << " ";
    }
    cout << endl;
    return 0;   
}