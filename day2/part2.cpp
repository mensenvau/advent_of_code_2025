#include <bits/stdc++.h>
using namespace std;

bool isDoubleSequence(long long n) {
    string s = to_string(n);
    int len = s.length();
    for (int k = 1; k <= len / 2; k++) {
        if (len % k != 0) continue;
        string pattern = s.substr(0, k);
        bool ok = true;
        for (int i = 0; i < len; i += k) {
            if (s.substr(i, k) != pattern) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    string line;
    getline(in, line);

    long long total = 0;

    stringstream ss(line);
    string part;

    while (getline(ss, part, ',')) {
        size_t dash = part.find('-');
        if (dash == string::npos) continue;

        long long a = stoll(part.substr(0, dash));
        long long b = stoll(part.substr(dash + 1));

        out << a << " " << b << "\n";

        for (long long i = a; i <= b; i++) {
            if (isDoubleSequence(i)) {
                total += i;
            }
        }
    }

    out << "result:" << total;
}
