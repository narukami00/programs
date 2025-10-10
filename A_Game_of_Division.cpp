#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define eb emplace_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        int cnt=0, indx=-1;
        vector<int>arr(n+1);
        // for(int i=1;i<=n;i++){
        //     cin>>arr[i];
        //     if(arr[i]%k==0){
        //         cnt++;
        //         indx=i;
        //     }
        // }
        // if(cnt>1)no;
        // else{
        //     yes;
        //     cout<<indx<<endl;
        // }

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            cnt=0;
            int val1=arr[i];
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                int val2=arr[j];
                if(abs(val1-val2)%k==0){
                    cnt=1;
                }
            }
            if(!cnt){
                indx=i;
                break;
            }
        }

        if(indx==-1)no;
        else{
            yes;
            cout<<indx<<endl;
        }

    }
return 0;
}