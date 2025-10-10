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

bool valid(string s){
    return sz(s)<=10 && (s=="0" || s[0]!='0');
}

bool eval(string s,int &res){
    int n=sz(s),i=0;
    if(n==0 || !isdigit(s[0]))return 0;

    vector<string>tok;
    while(i<n){
        if(!isdigit(s[i]))return 0;
        int j=i;
        while(j<n && isdigit(s[j]))j++;
        string num=s.substr(i,j-i);
        if(!valid(num))return 0;
        tok.pb(num);
        if(j==n)break;
        if(s[j]!='+' && s[j]!='-')return false;
        tok.pb(string(1,s[j]));
        j++;
        if(j==n || !isdigit(s[j]))return 0;
        i=j;
    }

    res=stoll(tok[0]);
    for(int i=1;i+1<sz(tok);i+=2){
        int val=stoll(tok[i+1]);
        if(tok[i]=="+")res+=val;
        else res-=val;
    }

    return 1;
}

bool cor(string s){
    int eq=s.find('=');
    string left=s.substr(0,eq),right=s.substr(eq+1);
    int l=0,r=0;
    return eval(left,l) && eval(right,r) && l==r;
}

int32_t main(){
    Flashyy
    //tc
    {
        string s;
        cin>>s;

        if(cor(s)){
            cout<<"Correct\n";
            return 0;
        }

        for(int i=0;i<sz(s);i++){
            if(!isdigit(s[i]))continue;
            char d=s[i];
            string rem = s.substr(0,i)+s.substr(i+1);
            for(int j=0;j<=sz(rem);j++){
                if(j==i)continue;
                string ns=rem.substr(0,j)+d+rem.substr(j);
                if(cor(ns)){
                    cout<<ns<<endl;
                    return 0;
                }
            }
        }

        cout<<"Impossible\n";
    }
return 0;
}