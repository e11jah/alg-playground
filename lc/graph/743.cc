#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 110, M=6e3, INF=0x3f3f3f3f;
class Solution {
    int n, h[N], to[M], nex[M], w[M], idx=0, dist[N], st[N];
public:
    void add(int a, int b, int c) {
        to[idx]=b, w[idx]=c;
        nex[idx]=h[a], h[a]=idx++;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {        
        //spfa 搜索最短路

        memset(h, -1, sizeof h);
        for (vector<int> v: times) {
            add(v[0], v[1], v[2]);
        }
        memset(dist, 0x3f, sizeof dist);
        dist[k]=0, st[k]=1;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            st[x]=0;
            for (int j = h[x]; j != -1; j=nex[j]) {
                int k = to[j], p=w[j];
                if (dist[k]>dist[x]+p) { 
                    dist[k]=dist[x]+p;
                    if (!st[k])
                        q.push(k), st[k]=1;
                }
            }
        }
        // 最长的链条即为传播用时
        int ans=0;
        for (int i = 1; i <= n; i++)
            if (dist[i]==INF)
                return -1;
            else ans=max(ans, dist[i]);
        return ans;
    }
};