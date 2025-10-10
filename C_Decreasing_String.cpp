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
        string s;
        cin>>s;
        int n=sz(s);
        int pos;
        cin>>pos;
        int to_remove=0;
        while(true){
            int t=pos-(n-to_remove);
            if(t<=0)break;
            else pos=t;
            to_remove++;
        }pos--;
        vector<char>st;
        for(char c:s){
            while(!st.empty() && to_remove>0 && st.back()>c){
                st.pop_back();
                to_remove--;
            }
            st.push_back(c);
        }
        while(to_remove-->0 && !st.empty())st.pop_back();
        cout<<st[pos];

    }
return 0;
}