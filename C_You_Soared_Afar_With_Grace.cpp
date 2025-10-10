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
        int n;
        bool f=1;
        cin>>n;
        vector<int> a(n);
        cin>>a;
        vector<int> b(n);
        cin>>b;
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]=b[i];
        }
        int cnt=0,indx=-1;
        for(int i=0;i<n;i++){
            if(mp[mp[a[i]]]!=a[i]){
                f=0;break;
            }
            if(a[i]==b[i]){cnt++;indx=i;}
        }

        if(n%2==0 && cnt>0)f=0;
        else if(n%2!=0 && cnt>1)f=0;
        
        if(!f){
            cout<<-1<<endl;
            continue;
        }

        map<int,int> pos;
        for(int i=0;i<n;i++){
            pos[a[i]]=i;
        }

        int op=0;
        vector<pair<int,int>> ops;

        int mid=n/2;
        if(n%2!=0 && cnt==1 && indx!=mid){
            op++;
            swap(a[indx],a[mid]);
            pos[a[indx]]=indx;
            pos[a[mid]]=mid;
            ops.push_back({indx+1,mid+1});
        }

        for(int i=0;i<n/2;i++){
            int l=i;
            int r=n-1-i;
            int x=a[l];
            int need=mp[x];
            if(a[r]!=need){
                int j=pos[need];
                swap(a[j],a[r]);
                pos[a[j]]=j;
                pos[a[r]]=r;
                ops.push_back({j+1,r+1});
                op++;
            }
        }

        cout<<op<<endl;
        for(auto &it:ops) cout<<it.first<<sp<<it.second<<endl;
    }
return 0;
}