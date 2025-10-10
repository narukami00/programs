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

vector<char> a={'L','I','T'};

char func(int i,string& s){
    for(auto it:a){
        if(s[i]!=it && s[i+1]!=it) return it;
    }return 'F';
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> ans;
        map<char,int> mp;
        for(auto i:s)mp[i]++;

        if(!((mp['L'] && mp['I']) || (mp['T'] && mp['I']) || (mp['L'] && mp['T']))){
            cout<<-1<<endl;
            continue;
        }

        while(max({mp['L'],mp['I'],mp['T']}) != min({mp['L'],mp['I'],mp['T']})){
            int mn=min({mp['L'],mp['I'],mp['T']});
            int mx=max({mp['L'],mp['I'],mp['T']});
            int f=0;

            for(int i=0;i<sz(s)-1;i++){
                char x=func(i,s);
                if(s[i]!=s[i+1] && mp[x]==mn){
                    mp[x]++;
                    f=1;
                    s.insert(s.begin()+i+1,x);
                    ans.pb(i);
                    break;
                }
            }

            if(!f){
                for(int i=0;i<sz(s)-1;i++){
                    char x=func(i,s);
                    if(s[i]!=s[i+1] && mp[x]==mx){
                        mp[x]++;
                        s.insert(s.begin()+i+1,x);
                        ans.pb(i);
                        f=1;
                        break;
                    }
                }
            }
        }

        cout<<sz(ans)<<endl;
        for(auto it :ans) cout<<it+1<<endl;
    }
return 0;
}