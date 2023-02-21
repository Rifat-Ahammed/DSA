/*
*** Cycle detection in 
    Directed graph ***

    input:
    4 5
    1 3
    2 1
    2 4
    3 2
    3 4

    Output: 
    4
    2 1 3 2



*/

#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;

vector<int>adj_list[N];
int visited[N];
bool cycle_detection(int node)
{
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        /*
        if(visited[node]==0)-> unexplored node | apply cycle_detection
        if(visited[node]==1)-> pause node | cycle detected
        if(visited[node]==2)-> done node | continue.
        
        */
       if(visited[adj_node]==0)
       {
            bool got_cycle = cycle_detection(adj_node);
            if(got_cycle)
            {
                return true;
            }
       }
       else if(visited[adj_node]==1)
       {
            return true;
       }
    }
    visited[node] = 2;
    
    return false;
}
int main()
{
    int n, m;

    cin >> n >> m;

    for (int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
    }
    bool cycle_exits = false;

    for (int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            bool got_cycled = cycle_detection(i);
            if(got_cycled)
            {
                cycle_exits = true;
                break;
            }
        }
    }
    if(cycle_exits)
    {
        cout<<"Cycle Exists"<<endl;
    }
    else
    {
        cout<<"No cycle exists"<<endl;
    }

    return 0;
}