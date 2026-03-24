#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
//#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
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
    //Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n);
        int mx=-1,mx_indx=-1;
        for(int i=0;i<n;i++){
            cout<<"? "<<i+1<<" "<<n<<" ";
            for(int j=1;j<=n;j++)cout<<j<<" ";
            cout<<endl;

            cin>>a[i];
            if(a[i]>mx){
                mx=a[i];
                mx_indx=i+1;
            }
        }
        vector<int>ans;
        ans.pb(mx_indx);
        while(a[mx_indx-1]>1){
            for(int i=0;i<n;i++){
                if(a[i]==a[mx_indx-1]-1){
                    cout<<"? "<<mx_indx<<" 2 "<<mx_indx<<" "<<i+1<<endl;
                    int x;
                    cin>>x;
                    if(x==2){
                        ans.pb(i+1);
                        mx_indx=i+1;
                        break;
                    }
                }

            }
        }
        cout<<"! "<<ans.size()<<" ";
        cout<<ans<<endl;
    }
return 0;
}