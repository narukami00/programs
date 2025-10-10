#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n >> q;
    int arr[n];
    for (int &i: arr) cin >> i;
    long long sum=0;
    int fuck = arr[0], dif = 0;
    int chk = -1;
    for (int i = 1; i < n; i++){
        if (arr[i] > fuck) {
            sum += dif;
            dif = 0;
            fuck = arr[i];
        } else if (arr[i] < fuck && fuck - arr[i] > dif){
            dif = fuck - arr[i];
            chk = fuck;
        }
    }
    sum += (fuck == chk) ? 0 : fuck;
    if (fuck > dif){
        
    }
    cout << sum << endl;
    
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}