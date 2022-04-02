#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u;
    int v;
    int weight;

    bool operator < (const edge&e)const
    {
        return weight > e.weight;
    }

    void print()
    {
        cout<<"u : "<<u;
        cout<<" v : "<<v<<" w : "<<weight<<endl;
    }

    edge()
    {
        u=-1;
        v=-1;
        weight = -1;
    }
    edge(int _u, int _v, int _weight)
    {
        u = _u;
        v = _v;
        weight = _weight;
    }
};

vector <int> adj[1000001];
vector <int> weight[1000001];
bool visited[1000001];
queue <int> MSTvertices;
priority_queue <edge, vector <edge> > pq;


void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        visited[i] = false;
    }
}


int main()
{
    int vertices, edges;
    cin>>vertices>>edges;

    int low1, low2, minValEdge = INT_MAX;
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        if(w < minValEdge)
        {
            minValEdge = w;
            low1 = u;
            low2 = v;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
        edge e(u, v, w);
        pq.push(e);
    }

    edge e = pq.top();
    e.print();

    // MSTvertices.push(low1);
    // MSTvertices.push(low2);
    // visited[low1] = true;
    // visited[low2] = true;

}
