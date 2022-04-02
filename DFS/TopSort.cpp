#include<bits/stdc++.h>
using namespace std;

stack <int> topSorted;
vector <int> adj[100005];
bool visited[100005];

void DFS(int s)
{
    visited[s] = true;
    for(int e : adj[s])
    {
        if(!visited[e])
        DFS(e);
    }
    topSorted.push(s);
}

void makeUndirectedGraph(int edges)
{
    for(int i=0; i<edges ; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
}


void getTopSortedOrder(int vertices)
{
    for(int i=0; i<vertices ; i++)
    {
        if(!visited[i])
        DFS(i);
    }

    while(!topSorted.empty())
    {
        printf("%d\n", topSorted.top());
        topSorted.pop();
    }

}

int main()
{
    int vertices, edges;

    scanf("%d %d", &vertices, &edges);

    init(vertices);

    makeUndirectedGraph(edges);

    getTopSortedOrder(vertices);

    return 0;
}
