#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc int TC; cin >> TC; for (int tt = 1; tt <= TC; tt++)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define eb emplace_back

int32_t main(){
    Flashyy
    tc {
        int n;
        cin>>n;
        int arr[2][n];
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        int indx=0;
        int sum=LLONG_MIN;
        for(int i=0;i<n;i++){
            int temp=arr[0][i]+arr[1][i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    temp+=max(arr[0][j],arr[1][j]);
                }
            }
            sum=max(sum,temp);
        }
        
        cout<<sum<<endl;
    }
    return 0;
}
