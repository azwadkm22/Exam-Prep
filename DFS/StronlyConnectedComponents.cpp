 #include<bits/stdc++.h>
using namespace std;

vector <int> adj[10000];
vector <int> transposed[10000];
vector <int> scc[10000];
stack <int> finished;
bool isVisited[10000];
bool tranVisited[10000];
int sccGraph[10000];
int sccCount=0;
int compTaken[10000][10000] = {false};
int toEdge[10000][10000] = {0};

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        adj[i].clear();
        transposed[i].clear();
        scc[i].clear();
        isVisited[i] = false;
        tranVisited[i] = false;
        sccGraph[i] = 0;
    }
}
void dfs(int source)
{
    isVisited[source] = true;
    for(int child: adj[source])
    {
        if(!isVisited[child])
        dfs(child);
    }
    finished.push(source);
}

void revDFS(int source)
{
    tranVisited[source] = true;
    scc[sccCount].push_back(source);
    sccGraph[source] = sccCount;
    for(int child: transposed[source])
    {
        if(!tranVisited[child])
        {
            revDFS(child);
        }
    }
}

void makeSCC()
{
    while(!finished.empty())
    {
        int top = finished.top();
        finished.pop();

        if(!tranVisited[top])
        {
            sccCount++;
            revDFS(top);
        }
    }
}

void printSCC()
{
    for(int i=1; i<=sccCount; i++)
    {
        cout<<"C"<<i<<": ";
        int len = scc[i].size();
        for(int j=0 ; j< len ; j++)
        {
            cout<<scc[i][j];
            if( j != len-1) cout<<", ";
            else printf("\n");
        }
    }
}
int main()
{
    int nodes, edges, edgeCount=0;
    cin>>nodes>>edges;

    init(nodes);

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        transposed[v].push_back(u);
    }

    dfs(1);
    makeSCC();
    printSCC();


    //Cutting redundant edges
    for(int i=0; i<nodes; i++)
    {
        int len = adj[i].size();
        for(int j=0; j<len; j++)
        {
            int x = sccGraph[i];
            int y = sccGraph[adj[i][j]];
            if(x != y)
            {
                toEdge[x][y]++;
                if(compTaken[x][y] != true)
                {
                    compTaken[x][y] = true;
                    edgeCount++;
                }
            }
        }
    }

    printf("Node = %d, Edge = %d\n", sccCount, edgeCount);

    for(int i=0; i<nodes; i++)
    {
        int len = adj[i].size();
        for(int j=0; j<len; j++)
        {
            int x = sccGraph[i];
            int y = sccGraph[adj[i][j]];
            if(x != y)
            {
                if(toEdge[x][y] > 1) toEdge[x][y] = 1;
                else if(toEdge[x][y] == 1)
                {
                    printf("C%d C%d\n", x, y);
                }
            }
        }
    }

    return 0;
}
