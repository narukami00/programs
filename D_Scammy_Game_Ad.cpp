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
        cin >> n;
        int newp = 0, cur1 = 1, cur2 = 1;
        vector<pair<char,int>> opss1, opss2;
        for(int i = 0; i < n; i++){
            char op1, op2;
            int num1, num2;
            cin >> op1 >> num1 >> op2 >> num2;
            opss1.eb(op1, num1);
            opss2.eb(op2, num2);
        }
        for(int i = 0; i < n; i++){
            char op1 = opss1[i].first, op2 = opss2[i].first;
            int num1 = opss1[i].second, num2 = opss2[i].second;
            
            if(op1=='+' && op2=='+'){
                bool ass = false;
                for(int j = i; j < n && !ass; j++){
                    char nop1 = opss1[j].first, nop2 = opss2[j].first;
                    int nval1 = opss1[j].second, nval2 = opss2[j].second;
                    if(nop1=='+' && nop2=='x'){
                        cur2 += newp;
                        ass = true;
                        break;
                    } else if(nop1=='x' && nop2=='+'){
                        cur1 += newp;
                        ass = true;
                        break;
                    } 
                    else if(nop1=='x' && nop2=='x'){
                        if(nval1 > nval2){
                            cur1 += newp;
                            ass = true;
                            break;
                        } else if(nval1 < nval2){
                            cur2 += newp;
                            ass = true;
                            break;
                        } 
                    }
                }
                if(!ass){
                    int total = cur1 + cur2 + newp;
                    int desired = total / 2;
                    int req = desired - cur1;
                    int ta, tb;
                    if(req <= newp){
                        ta = req;
                        tb = newp - ta;
                    } else {
                        ta = newp;
                        tb = 0;
                    }
                    cur1 += ta;
                    cur2 += tb;
                }
            }
            else if(op1=='+' && op2=='x'){
                cur2 += newp;
            }
            else if(op1=='x' && op2=='+'){
                cur1 += newp;
            }
            else if(op1=='x' && op2=='x'){
                if(num1 > num2){
                    cur1 += newp;
                } else if(num1 < num2){
                    cur2 += newp;
                } else {
                    bool ass = false;
                    for(int j = i+1; j < n && !ass; j++){
                        char nop1 = opss1[j].first, nop2 = opss2[j].first;
                        int nval1 = opss1[j].second, nval2 = opss2[j].second;
                        if(nop1=='+' && nop2=='x'){
                            cur2 += newp;
                            ass = true;
                            break;
                        } else if(nop1=='x' && nop2=='+'){
                            cur1 += newp;
                            ass = true;
                            break;
                        } else if(nop1=='x' && nop2=='x'){
                            if(nval1 > nval2){
                                cur1 += newp;
                                ass = true;
                                break;
                            } else if(nval1 < nval2){
                                cur2 += newp;
                                ass = true;
                                break;
                            }
                        }
                    }
                    if(!ass){
                        int total = cur1 + cur2 + newp;
                        int desired = total / 2;
                        int req = desired - cur1;
                        int ta, tb;
                        if(req <= newp){
                            ta = req;
                            tb = newp - ta;
                        } else {
                            ta = newp;
                            tb = 0;
                        }
                        cur1 += ta;
                        cur2 += tb;
                    }
                }
            }
            
            newp = 0;
            if(op1 == '+'){
                newp += num1;
            }
            if(op2 == '+'){
                newp += num2;
            }
            if(op1 == 'x'){
                newp += cur1 * (num1 - 1);
            }
            if(op2 == 'x'){
                newp += cur2 * (num2 - 1);
            }
        }
        cout << cur1 + cur2 + newp << endl;
    }
    return 0;
}
