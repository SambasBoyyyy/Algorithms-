#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;
const int N= 1e5+10;
vector<int> adjlist[N];

map<int,string> vis;
list<int> uniqueNodes; // Set to store unique nodes
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
        // adjlist[n2].push_back(n1);
        uniqueNodes.push_back(n1); // Insert unique nodes into the set
        uniqueNodes.push_back(n2);
    }
    uniqueNodes.unique();
    cout<<"Give the starting node : ";
    int n;
    cin>>n;
    cout<<endl;
    list<int>::iterator pos;
    pos = find (uniqueNodes.begin(), uniqueNodes.end(),n);
    uniqueNodes.erase(pos);
    uniqueNodes.insert(uniqueNodes.begin(),n);                    
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
// for disconnected directed graph
// input format 0 -> 1
// 6 7
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 3
// 4 5

