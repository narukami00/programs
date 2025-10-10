#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

void solve(int n, string s){
    bool ans=true;
    int np=-1,ns=-2;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){

        }
        else if(s[i]=='p'){
            np=i+1;
            arr1.push_back(np);
        }
        else if(s[i]=='s'){
            ns=n-i;
            arr2.push_back(ns);
        }
    }

    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<arr1.size();j++){
            if((arr1[j]==arr2[i] && arr1[j]!=n) || (arr1[j]<arr2[i] && arr2[i]!=n) || (arr1[j]>arr2[i] && arr1[j]!=n)){
                ans=false;
                break;
            }
        }
    }
    //cout<<np<<" "<<ns;
    if(ans)yes;
    else no;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
    }
return 0;
}