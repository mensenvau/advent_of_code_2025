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
        // out<<c<<" "<<s<<" "<<N<<" ";
        
        if(c == 'R')  {
            for(int i = 0; i < s; i++){
                N++;
                if(N==100) N = 0;
                if(N==0) count++;
            }
        } else {
            for(int i = 0; i < s; i++){
                N--;
                if(N==-1) N = 99;
                if(N==0) count++;
            }
        }
        
    }
    
    out<<count<<endl;
    
}