#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");
    
long long solve(string line){
    long long ans = 0;
    int mx_id = 0;
    for(int k = 11; k >= 0; k--){
        // out<<k<<" "<<line.size() - k<<endl;
        int mx_val = 0; 
        for(int i = mx_id; i < line.size() - k; i++){
            if(line[i] - '0' > mx_val) {
                mx_val = line[i] - '0';
                mx_id = i + 1;
            }
        }
        // out<<"val="<<mx_val<<endl;
        ans = ans * 10 + mx_val; 
    }
    
    return ans;
}

int main() {
    string line;
    long long sum = 0;
    
    while (in>>line) {
        out<<line<<" "<<solve(line)<<endl;
        sum = sum + solve(line);
    }
    
    out << sum;
}
