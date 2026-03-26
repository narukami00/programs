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
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        cin>>a>>b;
        int i=0,j=0;

        vector<int>pre(m,-1),suf(m,-1);
        for(i=0;i<n && j<m;i++){
            if(a[i]>=b[j]){
                pre[j]=i;
                j++;
            }
        }
        
        j=m-1;
        for(i=n-1;i>=0 && j>=0;i--){
            if(a[i]>=b[j]){
                suf[j]=i;
                j--;
            }
        }

        if(pre[m-1]!=-1 || suf[0]!=-1){
            cout<<"0"<<endl;
            continue;
        }

        if(m==1){
            cout<<b[0]<<endl;
            continue;
        }

        int mn=LLONG_MAX;bool f=0;

        for(i=0;i<m;i++){
            if(i==0){
                if(suf[1]!=-1){
                    mn=min(mn,b[i]);
                    f=1;
                }
            }else if(i==m-1){
                if(pre[m-2]!=-1){
                    mn=min(mn,b[i]);
                    f=1;
                }
            }else{
                if(pre[i-1]!=-1 && suf[i+1]!=-1 && pre[i-1]<suf[i+1]){
                    mn=min(mn,b[i]);
                    f=1;
                }
            }
        }

        if(!f)cout<<-1<<endl;
        else cout<<mn<<endl;
    }
return 0;
}