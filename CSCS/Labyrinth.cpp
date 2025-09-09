#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grp(n);
    for(int i = 0; i < n; i++) {
        cin >> grp[i];
    }

    string ans = "";
    int l = INT_MAX;
    queue<array<string, 3>> q;
    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < m; j++) {
            if(grp[i][j] == 'A') {
                q.push({to_string(i), to_string(j), ""});
                found = true;
                break;
            }
        }
        if(found) break;
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int x = stoi(node[0]);
        int y = stoi(node[1]);
        string path = node[2];
        if(grp[x][y] == 'B') {
            l = path.length();
            ans = path;
            break;
        }
        grp[x][y] = '#';
        if(x + 1 < n && (grp[x + 1][y] == '.' || grp[x + 1][y] == 'B')) {
            q.push({to_string(x + 1), to_string(y), path + 'D'});
        }
        if(x - 1 >= 0 && (grp[x - 1][y] == '.' || grp[x - 1][y] == 'B')) {
            q.push({to_string(x - 1), to_string(y), path + 'U'});
        }
        if(y + 1 < m && (grp[x][y + 1] == '.' || grp[x][y + 1] == 'B')) {
            q.push({to_string(x), to_string(y + 1), path + 'R'});
        }
        if(y - 1 >= 0 && (grp[x][y - 1] == '.' || grp[x][y - 1] == 'B')) {
            q.push({to_string(x), to_string(y - 1), path + 'L'});
        }
    }
    

    cout  << ( l == INT_MAX ? "NO" : "YES") << endl;
    if(l != INT_MAX) {
        cout << l << endl;
        cout << ans << endl;
    }
}