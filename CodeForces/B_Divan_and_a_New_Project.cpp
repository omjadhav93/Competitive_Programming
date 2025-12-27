#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        priority_queue<pair<int, int>> pq;
        for(int i = 1; i <= n; i++) pq.push({a[i-1], i});
        
        deque<int> dq;
        dq.push_back(0);
        while(!pq.empty()){
            int idx1 = pq.top().second; pq.pop();
            dq.push_back(idx1);
            if(pq.empty()) break;
            int idx2 = pq.top().second; pq.pop();
            dq.push_front(idx2);
        }

        vector<int> res(n+1, 0);
        for(int i = 0; i <= n; i++) res[dq[i]] = i;
        long long walk = 0;
        for(int i = 1; i <= n; i++) walk += 1ll * abs(res[i] - res[0]) * a[i-1];
        cout << walk * 2 << endl;
        for(auto x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}