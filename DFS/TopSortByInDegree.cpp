#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"debugging - "<<x<<endl;

std::vector<int> adj[10000];
int inDegree[100000]={0};
queue <int> zeroInDegree;
queue <int> topSortedGraph;


void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        inDegree[i] = 0;
    }
}


void topsort(){

    while(!zeroInDegree.empty())
    {
        int pop = zeroInDegree.front();
        zeroInDegree.pop();
        topSortedGraph.push(pop);

        int len = adj[pop].size();

        for(int i=0 ; i<len; i++)
        {
            inDegree[adj[pop][i]]--;
            if(inDegree[adj[pop][i]] == 0)
            zeroInDegree.push(adj[pop][i]);
        }
    }
}

int main() {
    int nodes, edges;
    cin>>nodes>>edges;


    init(nodes);

    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cin>>u>>v;
        inDegree[v]++;
        adj[u].push_back(v);
    }

    for(int i=1; i<=nodes; i++)
    {
        if(inDegree[i] == 0)
        {
            zeroInDegree.push(i);
        }
    }


    topsort();

    while(!topSortedGraph.empty())
    {
        cout<<topSortedGraph.front();
        topSortedGraph.pop();
        if(!topSortedGraph.empty()) cout<<" ";
    }
    cout<<endl;

    return 0;
}
