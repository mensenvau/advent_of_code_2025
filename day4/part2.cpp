#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

int main() {
    string line;
    int sum = 0;
    vector<vector<int>> arr {
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1},
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    
    vector<string> tmp;
    while (in >> line) {
        tmp.push_back(line);
    }

    while(true){
        vector<vector<int>> ans;
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < tmp[i].size(); j++) {
                int count = 0;
    
                for (int k = 0; k < arr.size(); k++) {
                    int ni = i + arr[k][0];
                    int nj = j + arr[k][1];
    
                    if (ni >= 0 && ni < tmp.size() && nj >= 0 && nj < tmp[i].size()) {
                        if (tmp[ni][nj] == '@') count++;
                    }
                }
    
                if (tmp[i][j] == '@' && count <= 3) {
                    ans.push_back({ i, j });
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            tmp[ans[i][0]][ans[i][1]] = 'X'; 
        }
        
        if(ans.size() == 0) break;
        sum = sum + ans.size();
    }
    

    out << sum;
}
