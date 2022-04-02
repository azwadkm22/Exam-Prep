#include<bits/stdc++.h>
using namespace std;


struct node{
    int x, y, dir;
};


int dis[100][100][4];
bool visited[100][100][4];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int gridColumns;
int gridRows;

int bfs(node source, node dest)
{
    queue<node> q;

    for(int i=0; i<4; i++)
    {
        source.dir = i;
        q.push(source);
        dis[source.x][source.y][source.dir] = 0;
        visited[source.x][source.y][source.dir] = true;
    }
    while(!q.empty())
    {
        node v;
        node u = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            if(i == u.dir)
            {
                v.x = u.x + dx[i];
                v.y = u.y + dy[i];

                if(v.x >= 0 && v.x <gridColumns && v.y>=0 && v.y < gridRows && grid[v.x][v.y] == '.' && !visited[v.x][v.y])
                {
                    q.push(v);
                    dis[v.x][v.y] = dis[u.x][u.y][u.dir] + 1;
                    visited[v.x][v.y][v.dir] = true;
                }
            }
            else
            {
                v.x = u.x;
                v.y = u.y;
                v.dir = u.dir;
                if(!visited[v.x][v.y][v.dir])
                {
                    q.push(v);
                    dis[v.x][v.y] = dis[u.x][u.y][u.dir] + 1;
                    visited[v.x][v.y][v.dir] = true;
                }
            }
        }
    }

    return min(dis[dest.x][dest.y][0], dis[dest.x][dest.y][1], dis[dest.x][dest.y][2], dis[dest.x][dest.y][3]);
}
