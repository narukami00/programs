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

vector<int> fun(const string &s) {
    int n = s.size();
    vector<int> pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + (s[i]=='1');
    }
    return pref;
}

int32_t main(){
    Flashyy

    string A, B;
    cin >> A >> B;
    int n = A.size();
    
    int cntA = 0, cntB = 0;
    for(char c : A) if(c=='1') cntA++;
    for(char c : B) if(c=='1') cntB++;
    if(cntA != cntB){
        cout << "NO\n";
        return 0;
    }

    if(A == B){
        cout << "YES\n0\n";
        return 0;
    }
    
    vector<pair<int,int>> moves;
    vector<int> pref = fun(A);
    auto upPre = [&](){
        pref = fun(A);
    };
    const int MAX_MOVES = 16 * n;

    bool poss = true;
    for (int i = 0; i < n && A != B; i++){
        if(A[i] == B[i])
            continue;
        bool fixed = false;
        for (int j = i+1; j < n; j++){
            if(A[j] == B[i]){
                int onesCount = pref[j+1] - pref[i];
                if(onesCount % 2 == 0){
                    reverse(A.begin() + i, A.begin() + j + 1);
                    moves.push_back({i+1, j+1}); 
                    upPre();
                    fixed = true;
                    break;
                }
            }
        }
        if(!fixed){
            poss = false;
            break;
        }
        if((int)moves.size() > MAX_MOVES){
            poss = false;
            break;
        }
    }
    
    if(!poss || A != B){
        cout << "NO\n";
    } else {
        cout << "YES\n" << moves.size() << "\n";
        for(auto &mv : moves){
            cout << mv.first << " " << mv.second << "\n";
        }
    }
    return 0;
}
