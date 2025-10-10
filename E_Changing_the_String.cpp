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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        int ba=0,ca=0,cba=0,bca=0,bc=0,cb=0;
        
        for(int i=0;i<q;i++){
            char x,y;cin>>x>>y;
            if(x=='b'&&y=='a'){ba++;if(cb) ba--,cb--,cba++;}
            if(x=='c'&&y=='a') {ca++;if(bc) bca++,ca--,bc--;}
            if(x=='b'&&y=='c')bc++;
            if(x=='c'&&y=='b')cb++;
        }

        for(int i=0;i<n;i++){
            if(s[i]=='a')continue;
            if(s[i]=='b'){
                if(ba) ba--,s[i]='a';
			    else if(cba) cba--,cb++,s[i]='a';
			    else if(bca) bca--,s[i]='a';
            }
            if(s[i]=='c'){
                if(ca) ca--,s[i]='a';
			    else if(bca) bca--,s[i]='a';
			    else if(cba) cba--,s[i]='a';
			    else if(cb) cb--,s[i]='b';
            }
        }

        cout<<s<<endl;
    }
return 0;
}