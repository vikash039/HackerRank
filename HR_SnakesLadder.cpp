/*
 *       Filename:  HR_SnakesLadder.cpp
 *    Description:  https://www.hackerrank.com/challenges/the-quickest-way-up
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
    int cell;
    int steps;
}qe;

int bfs(vector<int> &cell) {
    int ans = 0;
    vector<int> visited(101, 0);
    queue<qe> q;
    qe start = {1,0};
    q.push(start);
    visited[1] = 1;
    while(!q.empty()){
        qe temp = q.front();
        q.pop();
        int c = temp.cell;
        if(c == 100){
            ans = temp.steps;
            break;
        }

        for(int i=1;i<=6;i++){
            int next = c+i;
            if(next > 100) continue;
            next = cell[next] ? cell[next] : next;
            if(!visited[next]){
                visited[next] = 1;
                qe ne;
                ne.cell = next;
                ne.steps = temp.steps + 1;
                q.push(ne);
            }
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, M;
        vector<int> cell(101, 0);
        cin >> N;
        while(N--){
            int s, d;
            cin >> s >> d;
            cell[s] = d;
        }
        cin >> M;
        while(M--){
            int s, d;
            cin >> s >> d;
            cell[s] = d;
        }
        int ans = bfs(cell);
        cout << (ans ? ans : -1) << "\n";
    }
    return 0;
}

