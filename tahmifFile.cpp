#include<bits/stdc++.h>
using namespace std;


int main(){
    ofstream fout("output_t.txt");
    ifstream fin("input_t.txt");
    string s;
    string prev="-";
    while(fin){
        s=fin.get();
        if(s==" "  && prev==" ") continue;
       
        fout<<s;
        if(prev==" ") cout<<" ";

         prev=s;
        }
    //fout<<"\n";
    fout.close();
    fin.close();
    ifstream f("output_t.txt");
    while(f){
        char s1=f.get();
        cout<<s1;} 



    return 0;
}