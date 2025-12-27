#include<bits/stdc++.h>
using namespace std;

void detect_cycle(int node, int par, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, bool &found, vector<int> &cycle){
    if(found) return;
    vis[node] = 1;
    path.push_back(node);
    for(auto &nbr : adj[node]){
        if(vis[nbr] == 0){
            detect_cycle(nbr, node, adj, vis, path, found, cycle);
        } else if(nbr != par && vis[nbr] == 1){
            found = true;
            auto it = find(path.begin(), path.end(), nbr);
            for(; it != path.end(); it++){
                cycle.push_back(*it);
            }
            return;
        }
        if(found) return;
    }
    vis[node] = 2;
    path.pop_back();
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n+1, 0);
    vector<int> path; 
    vector<int> cycle;
    bool found = false;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0 && !found){
            detect_cycle(i, -1, adj, vis, path, found, cycle);
        }
    }

    if(!found){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << cycle.size() + 1 << endl;
    for(auto &node : cycle){
        cout << node << " ";
    }

    cout << cycle[0] << endl;
    return 0;

}