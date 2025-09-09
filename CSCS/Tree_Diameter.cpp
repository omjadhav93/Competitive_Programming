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

    int ans = 0;
    function<int(int,int)> dfs = [&](int node, int par) {
        int max_path = 1;
        int path = 1;
        for(auto &child : grp[node]) {
            if(child != par){
                int ch = dfs(child, node);
                path = max(path, max_path + ch);
                max_path = max(max_path, 1 + ch);
            }
        }
        ans = max(ans, path);
        return max_path;
    };

    dfs(1,0);
    cout << ans - 1 << endl;
    return 0;   
}