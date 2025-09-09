#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin>>n>>m;
    const int mod = 1e9 + 7;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<int> dp(m+1,0);
    dp[0] = 1;
    for(int x: c){
        for(int i=x;i<=m;i++){
            dp[i] = (dp[i] + dp[i-x])%mod;
        }
    }
    cout << dp[m] << endl;
}