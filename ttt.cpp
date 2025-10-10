#include<bits/stdc++.h>
using namespace std;
using L=int64_t;
main(){
    L t;
    cin>>t;
    while(t--)
        {L n;
        cin>>n;
        map<tuple<L,L,L>,L>C;
        L a,b,c,A{};
        cin>>b>>c;
        while(n---2)
            {a=b;b=c;
            cin>>c;
            A+=++C[{0,b,c}]+ ++C[{a,0,c}]+ ++C[{a,b,0}]-++C[{a,b,c}]*3;}
            cout<<A<<' ';}}
