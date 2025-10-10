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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s=" "+s;

        vector<int>l(k+1),r(k+1);
        for(int i=1;i<=k;i++)cin>>l[i];
        for(int i=1;i<=k;i++)cin>>r[i];
        
        vector<int>segs(n+1);
        for(int i=1;i<=k;i++){
            for(int j=l[i];j<=r[i];j++){
                segs[j]=i;
            }
        }

        vector<vector<int>>dif(k+1);
        for(int i=1;i<=k;i++){
            dif[i].assign(r[i]-l[i]+3,0);
        }

        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            int seg=segs[x];
            int L=l[seg],R=r[seg];
            int a=min(x,R+L-x);
            int b=max(x,R+L-x);
            dif[seg][a-L+1]++;
            dif[seg][b-L+2]--;
        }

        for(int i=1;i<=k;i++){
            int L=l[i],R=r[i];
            for(int j=1;j<=R-L+1;j++){
                dif[i][j]+=dif[i][j-1];
            }
            for(int j=1;j<=(R-L+1)/2;j++){
                if(dif[i][j]%2!=0){
                    swap(s[L+j-1],s[R-j+1]);
                }
            }
        }

        cout<<s.substr(1)<<endl;
    }
return 0;
}