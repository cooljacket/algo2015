#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<vector<int> > dp, trace;
vector<vector<pair<int, string> > > unit;

int Count(int n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        ++cnt;
    }
    return cnt;
}

void print(string& s, int beg, int tail) {
    if (beg > tail)
        return;

//printf("beg=%d, tail=%d, k=%d\n", beg, tail, trace[beg][tail]);
    if (trace[beg][tail] == INF) {
        cout << s.substr(beg, tail-beg+1);
        //cout << "hhh";
        return;
    }

    if (trace[beg][tail] > 0) {
        print(s, beg, trace[beg][tail]);
        print(s, trace[beg][tail]+1, tail);
        return;
    }

    int k = -trace[beg][tail];
//printf("a=%d, b=%d, %s, %s\n", unit[beg][k].first, unit[k+1][tail].first, unit[beg][k].second.data(), unit[k+1][tail].second.data());
    if (unit[beg][k].second == unit[k+1][tail].second) {
        int tmp = unit[beg][k].first + unit[k+1][tail].first;
        cout << tmp << '(';
        print(s, beg, beg+unit[beg][k].second.size()-1);
        cout << ')';
    } else {
        if (unit[beg][k].first > 1)
            cout << unit[beg][k].first << '(';
        //print(s, beg, beg+unit[beg][k].second.size()-1);
        print(s, beg, k);
        if (unit[beg][k].first > 1)
            cout << ')';

        if (unit[k+1][tail+1].first > 1)
            cout << unit[k+1][tail].first << '(';
        //print(s, k+1+unit[k+1][tail].second.size()-1, tail);
        print(s, k+1, tail);
        if (unit[k+1][tail+1].first > 1)
            cout << ')';
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    dp = trace = vector<vector<int> >(n+1, vector<int>(n+1, INF));
    unit = vector<vector<pair<int, string> > >(n+1, vector<pair<int, string> >(n+1));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        unit[i][i] = make_pair(1, s.substr(i, 1));
    }

    for (int L = 2; L <= n; ++L) {
        for (int beg = 0, tail=beg+L-1; tail < n; ++beg, ++tail) {
            dp[beg][tail] = INF;
            for (int k = beg; k <= tail; ++k) {
                if (unit[beg][k].second == unit[k+1][tail].second) {
                    int tmp = Count(unit[beg][k].first + unit[k+1][tail].first) + min(dp[beg][k], dp[k+1][tail]) + 2;
                    if (tmp < L) {
                        dp[beg][tail] = tmp;
                        //trace[k+1][tail] = INF;
                        trace[beg][tail] = -k;
                    }
                    else
                        dp[beg][tail] = dp[beg][k]+dp[k+1][tail];
                    unit[beg][tail] = make_pair(unit[beg][k].first + unit[k+1][tail].first, unit[beg][k].second);
                } else {
                    if (dp[beg][k] + dp[k+1][tail] < dp[beg][tail]) {
                        dp[beg][tail] = dp[beg][k] + dp[k+1][tail];
                        unit[beg][tail] = make_pair(1, s.substr(beg, L));
                        trace[beg][tail] = k;
                    }
                }
                //if (L == n)
//printf("beg=%d, tail=%d, k=%d, bk=%d, kt=%d, dp=%d\n", beg, tail, k, dp[beg][k], dp[k+1][tail], dp[beg][tail]);
            }
            //printf("beg=%d, tail=%d, dp=%d\n", beg, tail, dp[beg][tail]);
        }
    }
    //cout << dp[0][n-1] << endl;

    print(s, 0, n-1);
    cout << endl;

    return 0;
}