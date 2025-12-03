#include <bits/stdc++.h>
using namespace std;

int solve(string line){
    
    int mx_val = 0, mx_id = 0, max_second = 0; 
    for(int i = 0; i < line.size() - 1; i++){
        if(line[i] - '0' > mx_val) {
            mx_val = line[i] - '0';
            mx_id = i;
        }
    }
    
    for(int i = mx_id + 1; i < line.size(); i++){
        if(line[i] - '0' > max_second) {
            max_second = line[i] - '0';
        }
    }
    
    return mx_val * 10 + max_second;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    string line;
    int sum = 0;
    
    while (in>>line) {
        out<<line<<" "<<solve(line)<<endl;
        sum = sum + solve(line);
    }
    
    out << sum;
}
