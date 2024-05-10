#include <bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adjList;
    public:
    Graph(int num){
        vertices = num;
        adjList.resize(num);
    }
    
    void create(int v1, int v2){
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    void bfs(vector<bool> &visited, queue<int> &q){
        if(q.empty())
            return;
        int m = q.front();
        q.pop();
        cout << m << " ";
        for(int n : adjList[m]){
            if(!visited[n]){
                visited[n] = true;
                q.push(n);
            }
        }
        bfs(visited, q);
    }

    void dfs(vector<bool> &visited, int u){
        visited[u] = true;
        cout << u << " ";
        for(int n : adjList[u]){
            if(!visited[n]){
                dfs(visited, n);
            }
        }
    }

};

int main(){
    int vertices, edges, u, v;

    cout << "Enter the number of vertices in  graph: ";
    cin >> vertices;
    Graph g(vertices);
    cout << endl;

    cout << "Enter the number of edges in  graph: ";
    cin >> edges;
    for(int i=0; i<edges; i++){
        cout << "Enter (u v): ";
        cin >> u >> v;
        g.create(u, v);
    }
    cout << endl;

    while(true){
        int n;
        cout << "Choose the operation: \n1. BFS \n2. DFS \n3. Exit \n";
        cout << "Enter your choice: ";
        cin >> n;

        vector<bool> visited(vertices, false);
        queue<int> q;

        if(n==1){
            for(int i=0; i<vertices; i++){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                    g.bfs(visited, q);
                }
            }
        }
        else if(n==2){
            for(int i=0; i<vertices; i++){
                if(!visited[i]){
                    g.dfs(visited, i);
                }
            }
        }
        else if(n==3){
            break;
        }
        else{
            cout << "Enter valid number!" << endl;
        }
    }

    return 0;
}


















// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// class Graph{
//     int vertices;
//     vector<vector<int>> adjlist;
//     public:
//     Graph(int num){
//         vertices=num;
//         adjlist.resize(num);
//     }

//     void create(int v1, int v2){
//         adjlist[v1].push_back(v2);
//         adjlist[v2].push_back(v1);   
//     }

//     // void print(){ cout<<adjlist;}

//     void bfs(vector<bool> &visited,queue<int>&q){
//         if(q.empty())
//             return;
//         int m=q.front();
//         q.pop();
//         cout<<m<<"  ";
//         for(int n:adjlist[m]){
//             if(!visited[n]){
//                 visited[n]=true;
//                 q.push(n);
//             }
//         }
//         bfs(visited,q); 
//     }

//     void dfs(vector<bool>&visited,int u){
//         visited[u]=true;
//         cout<<u<<"  ";
//         for(int v:adjlist[u]){
//             if(!visited[v]){
//                 dfs(visited,v);
//             }
//         }
//     }
// };

// int main(){
//     int vertices,edges,u,v;
//     int ans=1;
//     int ch;
    
//     cout<<"Enter number of vertices: ";
//     cin>>vertices;
//     Graph g(vertices);

//     cout<<"Enter number of edges: ";
//     cin>>edges;
//     for(int i=0;i<edges;i++){
//         cout<<"Enter the edge pairs (u v) starting from 0: ";
//         cin>>u>>v;
//         g.create(u,v);

//     }
//     while(ans==1){
//         cout<<"1.BFS\n2.DFS";
//         cout<<"\nEnter your choice: ";
//         cin>>ch;
//         vector<bool>visited(vertices,false);
//         queue<int>q;
//         switch(ch){
//             case 1:
//                 for(int i=0;i<vertices;i++){
//                     if(!visited[i]){
//                         visited[i]=true;
//                         q.push(i);
//                         g.bfs(visited,q);
//                     }
//                 }
//                 break;
//             case 2:
//                 for(int i=0;i<vertices;i++){
//                     if(!visited[i]){
//                         g.dfs(visited,i);
//                     }
//                 }
//                 break;
//             default:
//                 cout<<"Invalid choice";
//                 break;
//         }
//         cout<<"Do you want to continue?(0/1) ";
//         cin>>ans;

//     }
    
// }