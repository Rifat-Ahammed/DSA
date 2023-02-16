#include <bits/stdc++.h>

using namespace std;

int adjMat[1000][1000] = {0};
int a, b;

bool isBidirectional()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {

            if (adjMat[i][j] == 1 && adjMat[j][i] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int count = 0;

    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int u, v;
        cin >> u >> v;
        // adjMat[u][v] = 1;
        if (adjMat[v][u] == 0)
        {
            adjMat[u][v] = 1;
            count++;
        }
    }
    cout << "Number of edges have to remove: " << count << endl;
    // bool res = isBidirectional();
    // if (res == false)
    // {
    //     cout << "Bi-directional" << endl;
    // }
    // else
    // {
    //     cout << "Directional" << endl;
    // }
}
