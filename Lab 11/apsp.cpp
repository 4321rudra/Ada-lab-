#include <iostream>
using namespace std;
const int o = 100;
#define INF 9999
void Allpath(int cost[][o], int A[][o], int route[][o][o], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            route[i][j][0] = i;
            route[i][j][1] = j;
            route[i][j][2] = -1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    route[i][j][2] = k;
                }
            }
        }
    }
    cout << "All pair shortest path is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void printPath(int route[][o][o], int i, int j)
{
    if (route[i][j][2] == -1)
    {
        cout << i << "->" << j << " ";
    }
    else
    {
        int k = route[i][j][2];
        printPath(route, i, k);
        printPath(route, k, j);
    }
}
int main()
{
    int A[o][o] = {{0, 3, 8,INF, },
                   {INF, 0, INF},
                   {5, INF, 0, 1},
                   {2, INF, INF, 0}};
    int cost[o][o];
    int route[o][o][o];
    Allpath(cost, A, route, 4);
    cout << "Route between nodes : " << endl;
    printPath(route, 0, 3);
    return 0;
}