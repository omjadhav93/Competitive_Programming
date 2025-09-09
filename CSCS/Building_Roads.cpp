#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> find = [&](int node) {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    };
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);
        if(pa != pb) {
            parent[pa] = pb;
        }
    }
    vector<pair<int,int>> ans;
    for(int i = 2; i <= n; i++) {
        int pa = find(i-1);
        int pb = find(i);
        if(pa != pb) {
            ans.push_back({pa, pb});
            parent[pa] = pb;
        }
    }
    cout << ans.size() << endl;
    for(auto &p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}