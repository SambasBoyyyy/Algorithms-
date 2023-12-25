#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;
const int N= 1e5+10;
 vector<int> adjlist[N];
    vector<int> transpos[N];

map<int,string> vis;
map<int,string> vis_trans;
list<int> uniqueNodes; // Set to store unique nodes
int currentTime=0;  
stack<int>s;  
int numComponents;


void dfs(int nodes,vector<int> adjlist[]){
    currentTime++;
    cout<<nodes<<" "<<"Start TIME "<<currentTime<<endl;
    
   
    vis[nodes]="GREY";
   for (int child:adjlist[nodes]) {
   
    if (vis[child]!="GREY" && vis[child]!="BLACK") // or if it is WHITE
    {
    dfs(child,adjlist);
    }//will not going to DFS more and srearch for new node
        
    
    
}

vis[nodes]="BLACK";
s.push(nodes);
currentTime++;
cout<<nodes<<" "<<"Fianl TIME "<<currentTime<<endl;

    
}


void dfs_transpos(int nodes,vector<int> adjlist[]){

printf("%d ", nodes);
    
   
    vis_trans[nodes]="GREY";
   for (int child:adjlist[nodes]) {
   
    if (vis_trans[child]!="GREY" && vis_trans[child]!="BLACK") // or if it is WHITE
    {
    dfs_transpos(child,adjlist);
    }//will not going to DFS more and srearch for new node
        
    
    
}

vis_trans[nodes]="BLACK";


    
}


int main() {
    int nodes, edges;
   
    cin >> nodes >> edges;
     
    for (int i = 0; i < edges; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        adjlist[n1].push_back(n2);
        transpos[n2].push_back(n1);
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
            dfs(node,adjlist);
        }
    }

    while (!s.empty())
    {
       int v=s.top();
       s.pop();
       if (vis_trans[v]!= "BLACK") {
      printf("Component %d: ", numComponents);
      dfs_transpos(v,transpos);
      numComponents++;
      printf("\n");
    }
    }
    
   printf("Total number of components: %d\n", numComponents);

    return 0;
}

//SCC exapmle
// 8 10
// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 4 7
// 6 4
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

