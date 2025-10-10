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
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a;cin>>b;
        int m;
        cin>>m;
        map<int,int>cnt;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }

        bool f=1;
        for(int i=0;i<n;i++){
            if(b[i]>a[i]){
                f=0;
                break;
            }
        }

        if(!f){
            no;
            continue;
        }

        vector<int>l(n),r(n);
        {
            vector<int>st;
            for(int i=0;i<n;i++){
                while(!st.empty() && b[st.back()]<=b[i])st.pop_back();
                l[i]=st.empty()?-1:st.back();
                st.push_back(i);
            }
        }
        {
            vector<int>st;
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && b[st.back()]<=b[i])st.pop_back();
                r[i]=st.empty()?n:st.back();
                st.push_back(i);
            }
        }

        map<int,vector<pair<int,int>>> intv;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                int x=b[i];
                intv[x].push_back({l[i]+1,r[i]-1});
            }
        }

        for(auto &it:intv){
            int x=it.f;
            auto &vec=it.s;
            sort(all(vec));
            int need=0;
            int curl=-1,curr=-1;
            for(auto &p:vec){
                int nl=p.f,nr=p.s;
                if(need==0 || nl>curr){
                    need++;
                    curl=nl;
                    curr=nr;
                }else{
                    curl=nl;
                    curr=min(curr,nr);
                }
            }
            if(cnt[x]<need){
                f=0;
                break;
            }
        }
        
        if(f)yes;else no;
    }
return 0;
}