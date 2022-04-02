#include<bits/stdc++.h>
using namespace std;


struct node{
    int x, y;
};


int dis[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int gridColumns;
int gridRows;

int bfs(node source[], int numOfSource, node dest)
{
    queue<node> q;
    for(int i=0; i<numOfSource; i++)
    {
        q.push(source[i]);
        dis[source[i].x][source[i].y] = 0;
        visited[source[i].x][source[i].y] = true;
    }

    while(!q.empty())
    {
        node v;
        node u = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];

            if(v.x >= 0 && v.x <gridColumns && v.y>=0 && v.y < gridRows && grid[v.x][v.y] == '.' && !visited[v.x][v.y])
            {
                q.push(v);
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                visited[v.x][v.y] = true;
            }
        }
    }

    return dis[dest.x][dest.y];
}
