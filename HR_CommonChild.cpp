/*
 *       Filename:  HR_CommonChild.cpp
 *    Description:  https://www.hackerrank.com/challenges/common-child
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 5003
int LCS[MAX][MAX];

int commonChild(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    
    int result = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0)
                LCS[i][j] = 0;
            else if(s1[i-1] == s2[j-1]){
                LCS[i][j] = LCS[i-1][j-1]+1;
                result = max(result, LCS[i][j]);
            }
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    return result;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}

