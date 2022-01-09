#include<bits/stdc++.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int adj[100][100];
int color[100];

int node;
int edge;


void dfs_visit(int x)
{
    color[x] = GRAY;
    //some work

    for(int i=0; i < node;i++)
    {
        if(adj[x][i] == 1)
        {
            if(color[i] == WHITE)
            {
                dfs_visit(i);
            }
        }
    }


    color[x] = BLACK;
}

void dfs()
{
    for(int i=0;i < node ;i++)
    {
        color[i] = WHITE;
    }

    for(int i = 0; i< node ;i++)
    {
        if(color[i] == WHITE)
        {
            dfs_visit(i);
        }
    }
}


int main()
{
    freopen("input.txt","r",stdin);

    cin>>node>>edge;

    for(int i = 0; i < edge; i++)
    {
        int x1,x2;
        cin>>x1>>x2;

        adj[x1][x2] = 1;
        adj[x2][x1] = 1;
    }

    dfs();
}
