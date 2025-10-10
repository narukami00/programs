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
        cout << it;
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
        vector<char> arr(n);
        map<char,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        // while(mp['N']!=0 && mp['S']!=0){
        //     mp['N']--;
        //     mp['S']--;
        // }
        // while(mp['E']!=0 && mp['W']!=0){
        //     mp['E']--;
        //     mp['W']--;
        // }
        vector<char>ans(n);
        int s1=0,s2=0,s3=0,s4=0;
        int f=0,w_move=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='N' && s1==0){
                ans[i]='R';
                s1=1;
            }
            else if(arr[i]=='N' && s1==1){
                ans[i]='H';
                s1=0;
            }
            else if(arr[i]=='S' && s2==0){
                ans[i]='R';
                s2=1;
            }
            else if(arr[i]=='S' && s2==1){
                ans[i]='H';
                s2=0;
            }
            else if(arr[i]=='E' && s3==0){
                ans[i]='H';
                s3=1;
            }
            else if(arr[i]=='E' && s3==1){
                ans[i]='R';
                s3=0;
            }
            else if(arr[i]=='W' && s4==0){
                ans[i]='H';
                s4=1;
            }
            else if(arr[i]=='W' && s4==1){
                ans[i]='R';
                s4=0;
            }
        }

        while(mp['N']!=0 && mp['S']!=0){
            mp['N']--;
            mp['S']--;
        }
        while(mp['E']!=0 && mp['W']!=0){
            mp['E']--;
            mp['W']--;
        }
        if(mp['N']%2!=0 && mp['N']!=0){f=1;}
        else if(mp['S']%2!=0 && mp['S']!=0){f=1;}
        else if(mp['W']%2!=0 && mp['W']!=0){f=1;}
        else if(mp['E']%2!=0 && mp['E']!=0){f=1;}

        if(f)no;
        else if(ans.size()==2 && ans[0]==ans[1])no;
        else cout<<ans<<endl;
         
    }
return 0;
}