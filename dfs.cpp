#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> adjlist[N];
bool vis[N];

void dfs(int nodes){
    cout << nodes << " ";
    vis[nodes] = true;
    
    for (int child : adjlist[nodes]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adjlist[n1].push_back(n2);
        adjlist[n2].push_back(n1);
    }
    
    for (int i = 0; i < nodes; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    return 0;
}
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6
