#include <bits/stdc++.h>
using namespace std;
// class Pair
// {
// public:
//     int first;
//     int second;
//     void make_pair(int a, int b)
//     {
//         first = a;
//         second = b;
//     }
// };
int main()
{
    // Pair Lia;
    // // Lia.first = 10;
    // // Lia.second = 20;
    // Lia.make_pair(10, 20);
    pair<string, int> Lia;
    pair<string, int> Lia{"Wasi", 20};
    Lia = make_pair("Wasi", 20); // this make pair isn't Lia's function, it's STL function


    cout << Lia.first << " " << Lia.second << endl;
    return 0;
}