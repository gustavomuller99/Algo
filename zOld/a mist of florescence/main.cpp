#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d; a--,b--,c--,d--;
    vector<vector<char>> ag(10, vector<char> (50, 'A')),
                         bg(10, vector<char> (50, 'B')),
                         cg(10, vector<char> (50, 'C')),
                         dg(10, vector<char> (50, 'D'));
    cout << "40 50" << "\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if (i % 2 && j % 2 && c) ag[i][j] = 'C', c--;
            cout << ag[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if(i % 2 && j % 2 && d) bg[i][j] = 'D', d--;
            cout << bg[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if(i % 2 && j % 2 && a) cg[i][j] = 'A', a--;
            cout << cg[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if(i % 2 && j % 2 && b) dg[i][j] = 'B', b--;
            cout << dg[i][j];
        }
        cout << "\n";
    }
}
