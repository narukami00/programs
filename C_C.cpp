#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MOD=1e9+7;

void solve() {

    int n;
    cin>>n;
    string S;
    cin>>S;

    vector<int>freq(26,0);
    for(char c:S) freq[c - 'a']++;

    vector<vector<int>>dp(27,vector<int>(n+1,0));
    dp[0][0] = 1;

    for(int i=0;i<26;++i) {
        for(int j=0;j<=n;++j) {
            if (dp[i][j] > 0) {
                for(int k=0;k<=freq[i] && j+k<=n;++k) {
                //if(j+k<=n) {
                    dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j])%MOD;
                //}
                }
            }
        }
    }

    int result=0;
    for(int j=1;j<=n;++j) {result=(result+dp[26][j])%MOD;}

    cout<<result<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
