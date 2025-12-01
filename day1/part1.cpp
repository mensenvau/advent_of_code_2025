#include<bits/stdc++.h>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

int main(){ 
    
    int N = 50;
    int s, count = 0; 
    char c;
   
    while(!in.eof()) {
        in>>c>>s;
        out<<c<<" "<<s<<" ";
        if(c == 'R') N = N + s; else N = N - s;
 
        if(N < 0) N = N + 100; 
        N = N % 100;
        if(N==0) {
            count++;
        }
        out<<N<<endl;
    }
    
    out<<count;
}