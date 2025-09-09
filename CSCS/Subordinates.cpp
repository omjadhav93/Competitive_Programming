#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grp(n+1);
    for(int i = 2; i < n+1; i++) {
        int num;
        cin >> num;
        grp[num].push_back(i);
    }

    vector<int> sub(n+1, 0);
    function<int(int)> dfs = [&](int node) {
        if(sub[node] != 0) return sub[node];
        int total = 0;
        for(auto &child : grp[node]) {
            total += dfs(child);
        }
        sub[node] = total;
        return total + 1;
    };

    dfs(1);

    for(int i = 1; i < n+1; i++) {
        cout << sub[i] << " ";
    }

    return 0;
}