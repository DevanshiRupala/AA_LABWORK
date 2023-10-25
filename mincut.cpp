#include <bits/stdc++.h>
using namespace std;

int find(int node, vector<int> &parent) {
        // If the node is the parent of 
        // itself then it is the leader 
        // of the tree. 
        if(node == parent[node]) return node;
        
        //Else, finding parents and also 
        // compressing the paths.
        return parent[node] = find(parent[node],parent);
}

 // Union function 
void Union(int u, int v, vector<int> &parent) {
        u = find(u, parent);
        v = find(v, parent);
        parent[v] = u;
}

int count_edges(vector<vector<int>> &g) {
    //Basically checking the upper Triangle part of the adj. matrix to find edges n/2. 
    int counter = 0;
    int i, j;
    int n = g.size();
    for(i=0; i<n ;i++) {
        for(j = i+1; j<n; j++) {
            if(g[i][j] == 1) counter++;
        }
    }
    return counter;
}

void create_edge_matrix(vector<vector<int>> &g, int e[][2]) {
    int i, j; 
    int n = g.size();
    int x = 0;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(g[i][j] == 1) {
               e[x][0]=i;
               e[x][1]=j;
               x++;
            }
        }
    }
}

int main() {
   int n = 4;
   
   srand(time(NULL));
   vector<vector<int>> graph = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};   //Adj. matrix
   
    int mincut = INT_MAX;
    
   for(int k = 0; k<100*n*n; k++) {
       vector<int> parent(n);
       for(int i=0; i<n; i++) {
           parent[i] = i;
       }
       
       int m = count_edges(graph);
       
       //Creating edge matrix 
       int edges[m][2];
       create_edge_matrix(graph, edges);
       
       //Iterating till we dont have V and V-S, (at that we'll have n = 2)
       while(n > 2) {
           int u, v;
           int e = rand() % m;  //Selecting random edge from Edge- matrix
           u = edges[e][0];
           v = edges[e][1];
           
           int set1 = find(u, parent);
           int set2 = find(v, parent);
           
           //Checking if both vertices are in same grp or not, if set1 == set2 then they are in same gropu bcuz they'll have same leader.
           
           if(set1 != set2) {
                Union(u,v,parent); // Reducing count of vertices by 1.
                n--;
            }
       }
       
        // cout << "Edges needs to be removed : " << endl;
        int ans = 0;
     
        cout << endl;
        for(int i=0; i<m; i++) {
            int set1 = find(edges[i][0],parent);
            int set2 = find(edges[i][1],parent);
            if(set1 != set2) {
                ans++;
            }
        }
        if(ans < mincut) mincut = ans;
        // cout << ans << endl;
   }
    cout << "Min. cut size is : " << mincut << endl;
    return 0;
}
