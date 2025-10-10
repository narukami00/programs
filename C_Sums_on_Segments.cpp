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

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;
        int l1=0,r1=0;
        int l2=2*1e9,r2=-2*1e9;
        int pr=0;
        int minL=0,maxL=0;
        int minR=2*1e9,maxR=-2*1e9;

        for(int i=0;i<n;i++){
            pr+=arr[i];
            if(arr[i]!=-1 && arr[i]!=1){
                minR=minL;
                maxR=maxL;
                minL=pr;
                maxL=pr;
            }
            l1=min(l1,pr-maxL);
            r1=max(r1,pr-minL);
            l2=min(l2,pr-maxR);
            r2=max(r2,pr-minR);
            minL=min(minL,pr);
            maxL=max(maxL,pr);
        }
        vector<int> ans;
        if(l2>r1){
            for(int i=l1;i<=r1;i++)ans.push_back(i);
            for(int i=l2;i<=r2;i++)ans.push_back(i);
        }else if(l1>r2){
            for(int i=l2;i<=r2;i++)ans.push_back(i);
            for(int i=l1;i<=r1;i++)ans.push_back(i);
        }else{
            for(int i=min(l1,l2);i<=max(r1,r2);i++) ans.push_back(i);
        }

        cout<<ans.size()<<endl;
        cout<<ans<<endl;

    }
return 0;
}