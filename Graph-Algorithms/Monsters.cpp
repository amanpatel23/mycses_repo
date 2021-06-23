/*
    Author: Aman Patel
    Date: 23-06-2021
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
#define mod 1000000007
#define i_max INT_MAX
#define i_min INT_MIN
#define s_i set<int>
#define v_i vector<int>
#define v_s vector<string>
#define v_c vector<char>
#define stk_i stack<int>
#define q_i queue<int>
#define qp_ii queue<pair<int, int>>
#define pqp_ii priority_queue<pair<int, int>>
#define vp_ii vector<pair<int, int>>
#define um_ii unordered_map<int, int>
#define m_ii map<int, int>
#define p_ii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define lbnd lower_bond
#define ubnd upper_bond
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define nline "\n"
#define yes (cout << "YES" << "\n")
#define no (cout << "NO" << "\n")
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

const int N = (1e3 + 5), M = (1e3 + 5);
char labyrinth[N][M];
int monsters[N][M];
bool visited[N][M];
p_ii path[N][M];
queue<pair<pair<int, int>, int>> qq;

const int dr[] = {-1, +1, 0, 0};
const int dc[] = {0, 0, +1, -1};

int n, m, sr, sc;

int _count = 0;

void exploreNeighbours(int r, int c, int time, bool isPerson) {

    rep(i, 0, 4) {
        int rr = r + dr[i];
        int cc = c + dc[i];

        if (rr < 0 || cc < 0 || rr >= n || cc >= m)
            continue;

        if (visited[rr][cc] || labyrinth[rr][cc] == '#')
            continue;

        qq.push(mp(mp(rr, cc), time + 1));
        visited[rr][cc] = true;
        if (isPerson)
            path[rr][cc] = mp(r, c);

    }
}

void preprocessMonsters() {

    while (!qq.empty()) {
        _count++;
        int r = qq.front().ff.ff, c = qq.front().ff.ss;
        int time = qq.front().ss;

        monsters[r][c] = time;

        exploreNeighbours(r, c, time, false);
        qq.pop();
    }
}

void solve() {

    mem1(monsters);
    mem0(visited);

    cin >> n >> m;
    char temp;
    rep(i, 0, n) {
        rep(j, 0, m) {

            cin >> temp;
            if (temp == 'M') {
                qq.push(mp(mp(i, j), 0));
                visited[i][j] = true;
            } else if (temp == 'A') {
                sr = i, sc = j;
            }

            labyrinth[i][j] = temp;
        }
    }

    preprocessMonsters();

    mem0(visited);
    qq.push(mp(mp(sr, sc), 0));
    visited[sr][sc] = true;
    path[sr][sc] = mp(-1, -1);
    bool flag = false;
    int moves = -1;
    p_ii tempBox = mp(-1, -1);
    while (!qq.empty()) {
        int r = qq.front().ff.ff, c = qq.front().ff.ss;
        int time = qq.front().ss;

        if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && (monsters[r][c] == -1 || time < monsters[r][c])) {
            flag = true;
            moves = time;
            tempBox = mp(r, c);
            break;
        }

        exploreNeighbours(r, c, time, true);
        qq.pop();

    }

    if (flag) {
        yes;
        cout << moves << nline;
        string pathLine = "";
        p_ii fromBox;
        while (true) {
            p_ii tempCell = path[tempBox.ff][tempBox.ss];
            fromBox = mp(tempCell.ff, tempCell.ss);
            if (fromBox.ff == -1 && fromBox.ss == -1)
                break;

            if (tempBox.ff == fromBox.ff) {
                if (tempBox.ss < fromBox.ss) {
                    pathLine += "L";
                } else {
                    pathLine += "R";
                }
            } else {
                if (tempBox.ff < fromBox.ff) {
                    pathLine += "U";
                } else {
                    pathLine += "D";
                }
            }

            tempBox = fromBox;
        }

        reverse(pathLine.begin(), pathLine.end());
        cout << pathLine << nline;
    } else
        no;

}

int32_t main() {

    fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}