#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"debugging - "<<x<<endl;

vector<int> adj[10000];
int inDegree[100000]={0};
int initalInDegree[100000] = {0};
queue <int> zeroInDegree;
queue <int> topSortedGraph;
stack <int> pathway;
vector <int> graph;
int path[10000];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        path[i] =0;
        inDegree[i] = 0;
    }
}


void topsort(int s, int t){

    while(!zeroInDegree.empty())
    {
        int pop = zeroInDegree.front();
        zeroInDegree.pop();
        topSortedGraph.push(pop);
        pathway.push(pop);
        graph.push_back(pop);

        int len = adj[pop].size();

        for(int i=0 ; i<len; i++)
        {
                inDegree[adj[pop][i]]--;
                zeroInDegree.push(adj[pop][i]);
        }
    }
}

void pathCount(int s, int t)
{
	if(s == t)
    {
		path[s] = 1;
	}
	else
    {
        int len = adj[s].size();
		for(int i=0; i <len ;i++)
        {
			if(!path[adj[s][i]])
            {
                pathCount(adj[s][i], t);
            }
            path[s] += path[adj[s][i]];
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
        initalInDegree[v]++;
        adj[u].push_back(v);
    }

    int s, t;
    cin>>s>>t;

    for(int i=1; i<=nodes; i++)
    {
        if(inDegree[i] == 0)
        {
            zeroInDegree.push(i);
        }
    }
    topsort(s, t);
    pathCount(s, t);

    cout<<"Number of paths from "<<s<<" to "<<t<<" = "<<path[s]<<endl;


    return 0;
}
