#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    int mat[node][node];
    memset(mat, 0, sizeof(mat)); // initialise the matrix with 0
    // memset(array/matrix name, the_value_to_initialize_with, sizeof(array/matrix_name)); //initialise the matrix with 0

    while (edge--) // or just use for (int i = 0; i < edge;i++)
    {
        // joto gula edge, toto input
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1; // undirected graph
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int con_a, con_b;
    cin >> con_a >> con_b;
    if(mat[con_a][con_b]==1)
        cout << "connection ache" << endl;
    else
        cout << "connection nai" << endl;
    return 0;
}