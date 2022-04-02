#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define SIZE 105

ull minDis[SIZE][SIZE];
int path[SIZE][SIZE];

void makeDirectedGraph(int edges)
{
    for(int i=0; i<edges ; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        minDis[u][v] = w;
        path[u][v] = u;
    }
}

void floydWarshall(int nodes)
{
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            for(int k=0; k<nodes; k++)
            {
                if(minDis[i][j] > minDis[i][k] + minDis[k][j])
                {
                    minDis[i][j] = minDis[i][k] + minDis[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                path[i][j] = -8;
                minDis[i][j] = 100000;
            }
            else
            {
                minDis[i][j] = 0;
                path[i][j] = -1;
            }
        }
    }
}

void findAllminDis(int vertices)
{
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            printf("%llu ", minDis[i][j]);
        }
        cout<<endl;
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            printf("%d ", path[i][j]);
        }
        cout<<endl;
    }
}

int main()
{
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    init(vertices); //Resetting all values
    makeDirectedGraph(edges);
    floydWarshall(vertices);
    findAllminDis(vertices);
    return 0;
}
