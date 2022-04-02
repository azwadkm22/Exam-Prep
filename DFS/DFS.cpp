#include<bits/stdc++.h>

using namespace std;

int state[100];
int discovery[100];
int finished[100];
int t = 0;
vector<int> adj[100];

void makeDirectedGraph(int edges)
{
    for(int i=0; i<edges ; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        discovery[i] = 0;
        finished[i] = 0;
        state[i] = 0;
    }
}

void DFS(int source)
{
    state[source] = 1;
    t++;
    discovery[source] = t;

    for(int v: adj[source])
    {
        if(state[v] == 0)
        {
            DFS(v);
        }
    }
    state[source] = 2;
    t++;
    finished[source] = t;
}

int main()
{
    int vertices, edges;

    scanf("%d %d", &vertices, &edges);

    init(vertices);

    makeDirectedGraph(edges);

    for(int i=0; i<vertices; i++)
    {
        if(state[i] == 0)
        {
            DFS(i);
        }
    }

    for(int i=0; i<vertices; i++)
    {
        cout<<discovery[i]<<" "<<finished[i]<<endl;
    }

}

// 6
// 7
// 0 1
// 0 2
// 2 1
// 1 3
// 3 2
// 4 3
// 4 5
