#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    while (n > 0){
        int torm = 0;
        int temp = n;
        while (temp > 0){ 
            int d = temp % 10;
            torm = max(torm, d);
            temp /= 10;
        }
        n -= torm;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}