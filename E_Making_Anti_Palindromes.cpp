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
        cin>>n;
        string s;
        cin>>s;

        if(n%2!=0){
            cout<<-1<<endl;
            continue;
        }

        vector<int>freq(26,0);
        for(char ch:s)freq[ch-'a']++;

        bool pos=1;
        for(int cnt:freq){
            if(cnt>n/2){
                pos=0;
                break;
            }
        }
        if(!pos){
            cout<<-1<<endl;
            continue;
        }
        
        int f=0;
        vector<int> bad(26,0);
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-i-1]){
                f++;
                bad[s[i]-'a']++;
            }
        }

        if(f==0){
            cout<<0<<endl;
            continue;
        }

        int mx=*max_element(all(bad));
        cout<<max(mx,(f+1)/2)<<endl;
    }
return 0;
}