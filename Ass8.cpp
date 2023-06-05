#include<bits/stdc++.h>
using namespace std;

// 8

// void printMatrix(vector<vector<int>>& mat){
//     for(auto v : mat) {
//         for(auto i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

int optimalBST(vector<int>& p, vector<int>& q, int n){

    cout << endl;

    vector<vector<int>> W(n+1, vector<int>(n+1, -1));
    vector<vector<int>> C(n+1, vector<int>(n+1, -1));

    // W[i][i] = q[i]
    for(int i=0; i<=n; i++){
        W[i][i] = q[i];
    }

    // C[i][i] = 0;
    for(int i=0; i<=n; i++){
        C[i][i] = 0;
    }

    for(int diagonal=1; diagonal<=n; diagonal++){

        for(int i=0, j=diagonal; i<=n && j<=n; i++, j++){

            W[i][j] = W[i][j - 1] + p[j] + q[j];

            // minCost = min( all C[i][x] + C[x+1][j] ) where x = i to j-1
            int minCost = INT_MAX;
            for(int x=i; x<j; x++){
                minCost = min(minCost, C[i][x] + C[x+1][j]);
            }

            C[i][j] = minCost + W[i][j];
        }
    }

    // printMatrix(C);
    // cout << endl;
    // printMatrix(W);

    return C[0][n];
}


int main(){
    
    int n;
    cout << "Enter No of Nodes in OBST: ";
    cin >> n;

    vector<int> p(n + 1), q(n + 1);

    // p[1] to p[n]
    cout << "Enter P[1...n]: ";
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }

    // q[0] to q[n]
    cout << "Enter Q[0...n]: ";
    for(int i=0; i<=n; i++){
        cin >> q[i];
    }

    cout << "Minimum cost of OBST: " << optimalBST(p, q, n) << endl;

    return 0;
}