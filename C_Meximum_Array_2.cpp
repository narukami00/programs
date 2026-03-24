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
    Flashyy
    tc
    {
        int n,k,c;
        cin>>n>>k>>c;
        vector<array<int,3>>a(c);
        for(int i=0;i<c;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        vector<int>ans(n,0);
        vector<int>aff(n,0);//1->min, 2->mex, 3->both, 0->none
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                if(a[j][1]<=i+1 && a[j][2]>=i+1){
                    if(a[j][0]==1)aff[i]|=1;
                    else aff[i]|=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(aff[i]==0)ans[i]=n;
            else if(aff[i]==1)ans[i]=k;
            else if(aff[i]==2)ans[i]=i%k;
            else if(aff[i]==3)ans[i]=n;
        }

        cout<<ans<<endl;
    }
return 0;
}