#include<bits/stdc++.h>
using namespace std;


bool visited[100];
int parent[100];
int weight[100];
int graph[100][100] = {0};
vector<int> adj[100];
vector<int> wt[100];

int findMinVertex(int n)
{
    int minVertex = -1;
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && ( minVertex==-1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }

    return minVertex;
}


void init(int n)
{
    for(int i=0; i<n ; i++)
    {
        wt[i].clear();
        adj[i].clear();
        parent[i] = i;
        weight[i] = 999999;
        visited[i] = false;
    }
}

int prims(int n)
{
    parent[0] = -1;
    weight[0] = 0;


    for(int j=0; j<n ;j++)
    {
        int u = findMinVertex(n);
        cout<<u<<endl;
        visited[u] = true;

        for(int v=0; v<n ;v++)
        {
            // cout<<u<< " - "<<v<< " = "<<wt[u][v]<<endl;
            if(graph[u][v] != 0 && !visited[v])
            {
                if(graph[u][v] < weight[v])
                {
                    weight[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    int ans=0;
    for(int i=1; i<n; i++)
    {
        if(parent[i] < i)
        cout<< parent[i] <<" - "<<i<<" = "<<weight[i]<<endl;
        else
        cout<< i <<" - "<<parent[i]<<" = "<<weight[i]<<endl;

        ans += weight[i];
    }

    return ans;
}
// //
// 5 7
// 0 1 4
// 0 2 8
// 1 3 6
// 1 2 2
// 2 3 3
// 2 4 9
// 3 4 5

int main()
{
    int vertices, edges;
    cin>>vertices>>edges;
    init(vertices);

    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        graph[u][v] = w;
        graph[v][u] = w;
        //
        // adj[u].push_back(v);
        // wt[u].push_back(w);
        //
        // adj[v].push_back(u);
        // wt[v].push_back(w);
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<prims(vertices)<<endl;
}
