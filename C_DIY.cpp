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
        int n;
        cin>>n;
        vector<int>a(n);
        map<int,int>freq;
        multiset<int>st;

        int mxx=LLONG_MIN,mnn=LLONG_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mxx=max(mxx,a[i]);
            mnn=min(mnn,a[i]);
        }

        for(int i=0;i<n;i++){
            a[i]+=max(abs(mnn),abs(mxx));
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
            if(freq[a[i]]!=0 && freq[a[i]]%2==0){
                cnt++;
                st.insert(a[i]);
            }
        }

        if(cnt<4){
            no;
            continue;
        }

        yes;
        vector<int>ans(8,-1);
        int mn=*st.begin();
        ans[0]=mn,ans[2]=mn;
        st.erase(st.begin());

        mn=*st.begin();
        ans[1]=mn,ans[5]=mn;
        st.erase(st.begin());

        int mx=*st.rbegin();
        ans[3]=mx,ans[7]=mx;
        auto it=prev(st.end());
        st.erase(it);

        mx=*st.rbegin();
        ans[4]=mx,ans[6]=mx;
        it=prev(st.end());
        st.erase(it);

        for(int i=0;i<8;i++)cout<<ans[i]-max(abs(mnn),abs(mxx))<<sp;
        cout<<endl;
    }
return 0;
}