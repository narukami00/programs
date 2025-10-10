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
        string s[2];
        cin>>s[0]>>s[1];
        int n=sz(s[0]);
        int bad=0;
        for(int i=0;i<n;i++){
            if(s[0][i]!=s[1][i])bad++;
        }
        int t,q;
        cin>>t>>q;
        queue<pair<int,int>>block;
        for(int i=0;i<q;i++){
            while(!block.empty() && block.front().f==i){
                if(s[0][block.front().s]!=s[1][block.front().s])bad++;
                block.pop();
            }
            int type;
            cin>>type;
            if(type==1){
                int pos;cin>>pos;pos--;
                if(s[0][pos]!=s[1][pos])bad--;
                block.push({i+t,pos});
            }else if(type==2){
                int op1,pos1,op2,pos2;
                cin>>op1>>pos1>>op2>>pos2;
                pos1--,pos2--,op1--,op2--;
                if(s[op1][pos1]!=s[1^op1][pos1])bad--;
                if(s[op2][pos2]!=s[1^op2][pos2])bad--;
                swap(s[op1][pos1],s[op2][pos2]);
                if(s[op1][pos1]!=s[1^op1][pos1])bad++;
                if(s[op2][pos2]!=s[1^op2][pos2])bad++; 
            }else{
                if(bad==0)yes;
                else no;
            }
        }
    }
return 0;
}