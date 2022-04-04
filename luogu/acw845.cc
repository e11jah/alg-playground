#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 八数码 把网格看成一种状态，从给定网格转移到目标网格的最少交换次数，
// 可以视为从图的某个节点移动到指定节点的最短路
void solve() {
    string s;
    char c;
    for (int i = 1;i<=9;i++)
        cin >>c,s+=c;

    queue<string> q;
    unordered_map<string,int> dis;
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

    q.push(s);
    dis[s]=0;
    string t, tar="12345678x";
    int p,x,y,a,b,d;
    while (!q.empty()) {
        t=q.front(),q.pop();
        d=dis[t];
        if (t == tar) {
            cout << d;
            return;
        }
        p=t.find('x');
        x=p/3,y=p%3;
        for (int i = 0; i < 4; i++) {
            a=x+dx[i],b=y+dy[i];
            if (a<0||b<0||a>2||b>2)
                continue;
            swap(t[p],t[a*3+b]); 
            if (!dis.count(t))
                q.push(t),dis[t]=d+1;
            swap(t[p],t[a*3+b]);
        }
    }
    cout << -1;
}

int main() {
    solve();
    return 0;
}