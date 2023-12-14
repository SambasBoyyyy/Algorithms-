#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;
const int N= 1e5+10;
vector<int> adjlist[N];

map<int,string> vis;
set<int> uniqueNodes; // Set to store unique nodes
int currentTime=0;    

void dfs(int nodes){
    currentTime++;
    cout<<nodes<<" "<<"Start TIME "<<currentTime<<endl;
    
   
    vis[nodes]="GREY";
   for (int child:adjlist[nodes]) {
   
    if (vis[child]!="GREY" && vis[child]!="BLACK") // or if it is WHITE
    {
    dfs(child);
    }//will not going to DFS more and srearch for new node
        
    
    
}

vis[nodes]="BLACK";
currentTime++;
cout<<nodes<<" "<<"Fianl TIME "<<currentTime<<endl;

    
}

int main() {
    int nodes, edges;
    
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adjlist[n1].push_back(n2);
        adjlist[n2].push_back(n1);
        uniqueNodes.insert(n1); // Insert unique nodes into the set
        uniqueNodes.insert(n2);
    }
    
     for (auto node : uniqueNodes) {//for disconnected graph
        if (vis[node] != "BLACK") {
            dfs(node);//i can not take user starting point
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