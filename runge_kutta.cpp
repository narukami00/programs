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


struct Term{
    double coeff;
    int pow_t;
    int pow_y;
    Term():coeff(1.0),pow_t(0),pow_y(0){}
    Term(double c,int t,int y):coeff(c),pow_t(t),pow_y(y){}
};

vector<Term> parse(string &expr){
    vector<Term> terms;
    string s=expr;

    for(int i=1;i<s.size();i++){
        if(s[i]=='-' && s[i-1]!='+' && s[i-1]!='-'){
            s.insert(i,"+");
        }
    }

    stringstream ss(s);
    string tok;
    while(getline(ss,tok,'+')){
        if(tok.empty())continue;
        Term term;
        tok.erase(remove(tok.begin(),tok.end(),' '),tok.end());
        if(tok=="-")continue;
        bool neg=0;
        if(tok[0]=='-'){
            neg=1;
            tok=tok.substr(1);
        }
        stringstream ss2(tok);
        string tok2;
        while(getline(ss2,tok2,'*')){
            if(tok2.find('t')!=string::npos){
                if(tok2=="t")term.pow_t+=1;
                else{
                    int pos=tok2.find("^");
                    int power=stoi(tok2.substr(pos+1));
                    term.pow_t+=power;
                }
            }else if(tok2.find('y')!=string::npos){
                if(tok2=="y")term.pow_y+=1;
                else{
                    int pos=tok2.find("^");
                    int power=stoi(tok2.substr(pos+1));
                    term.pow_y+=power;
                }
            }else{
                term.coeff*=stod(tok2);
            }
        }
        if(neg)term.coeff*=-1;
        //cout<<term.coeff<<" "<<term.pow_t<<" "<<term.pow_y<<endl;
        terms.pb(term);
    }
    return terms;
}

double eval(vector<Term>&terms,double t,double y){
    double result=0.0;
    for(auto &term:terms){
        result+=term.coeff*powl(t,term.pow_t)*powl(y,term.pow_y);
    }
    //cout<<"Eval: "<<result<<endl;
    return result;
}

double f(double t, double y){
    //cout<<(t*y)+(y*y)<<endl;
    return (t*y)+(y*y);
}

double runge_kutta(double t, double y, double h){
    double k1=h*f(t,y);
    double k2=h*f(t+h/2.0,y+k1/2.0);
    double k3=h*f(t+h/2.0,y+k2/2.0);
    double k4=h*f(t+h,y+k3);
    return y+(1/6.0)*(k1+2.0*k2+2.0*k3+k4);
}

double runge_kutta_poly(vector<Term>&terms, double t, double y, double h){
    double k1=h*eval(terms,t,y);
    double k2=h*eval(terms,t+h/2.0,y+k1/2.0);
    double k3=h*eval(terms,t+h/2.0,y+k2/2.0);
    double k4=h*eval(terms,t+h,y+k3);
    return y+(1/6.0)*(k1+2.0*k2+2.0*k3+k4);
}

int32_t main(){
    Flashyy
    //tc
    {
        double t0=0;
        double y0=1;
        double h=0.1;
        double t_end=0.5;

        int steps=(t_end-t0)/h;
        double t=t0;
        double y=y0;

        while(t < t_end){
            y=runge_kutta(t,y,h);
            if(t + h > t_end){
                h = t_end - t;
            }
            t+=h;
        }
        cout<<y<<endl;
        // cout << "Enter the ODE in polynomial form (in t and y):\n";
        // cout << "Example: t*y + t^3 - 2*y\n";
        // cout << "y' = ";

        // string func;
        // cin>>func;
        // vector<Term>terms=parse(func);
        // double t0,y0,h,t_end;
        // //cout << "Enter initial conditions t0, y0:\n";
        // cin >> t0 >> y0;
        // //cout << "Enter step size h:\n";
        // cin >> h;
        // //cout << "Enter the value of t at which y is to be computed:\n";
        // cin >> t_end;
        // t0*=1.0;
        // y0*=1.0;
        // h*=1.0;
        // t_end*=1.0;
        // // int steps=1;
        // // cout<<t_end<<" "<<t0<<" "<<h<<" "<<steps<<endl;
        // double t=t0;
        // double y=y0;
        // while(t < t_end){
        //     y=runge_kutta_poly(terms,t,y,h);
        //     if(t + h > t_end){
        //         h = t_end - t;
        //     }
        //     t+=h;
        // }
        // cout<<"The value of y at t = "<<t_end<<" is "<<y<<endl;
    }
return 0;
}