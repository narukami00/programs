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
        int n;string s;
        cin>>n>>s;

        vector<int>freq(26,0);
        for(char c:s)freq[c-'a']++;

        vector<pair<int,char>>flist;
        for(int i=0;i<26;i++){
            if(freq[i]){
                flist.push_back({freq[i],i+'a'});
            }
        }
        sort(rall(flist));
        vector<int>divs;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divs.push_back(i);
                if(i!=n/i)divs.push_back(n/i);
            }
        }sort(all(divs));

        int best=1;
        int best_uncng=0;

        for(int k:divs){
            if(k>26)continue;
            int t=n/k,uncng=0;
            for(int i=0;i<k;i++){
                int f=(i<sz(flist)?flist[i].f:0);
                uncng+=min(f,t);
            }
            if(uncng>best_uncng){
                best_uncng=uncng;
                best=k;
            }
        }

        int t=n/best;
        set<char>st;
        for(int i=0;i<best;i++){
            if(i<sz(flist)){
                st.insert(flist[i].s);
            }
        }
        for(int i=0;sz(st)<best && i<26;i++){
            st.insert(i+'a');
        }
        
        vector<int>cnt(26,0);
        string res=s;
        vector<int>indx;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(st.count(c) && cnt[c-'a']<t){
                cnt[c-'a']++;
            }else indx.push_back(i);
        }
        for(char c:st){
            while(cnt[c-'a']<t && !indx.empty()){
                res[indx.back()]=c;
                cnt[c-'a']++;
                indx.pop_back();
            }
        }
        cout<<sz(res)-best_uncng<<endl;
        cout<<res<<endl;
    }
return 0;
}