// C++ code for above program. 
#include <bits/stdc++.h> 
using namespace std; 
#define int long long int 

// each node represents a word state 
struct node { 
    int a, b, c; 
    // dist from starting word X 
    int dist; 
}; 

// 3D visited array 
bool visited[26][26][26]; 

// 3D restricted array 
bool restricted[26][26][26]; 

// utility arrays for single step 
// traversal in left and right 
int dx[6] = { 1, -1, 0, 0, 0, 0 }; 
int dy[6] = { 0, 0, 1, -1, 0, 0 }; 
int dz[6] = { 0, 0, 0, 0, 1, -1 }; 

// function to find the 
// minimum clicks. 
void solve(string start, string end, int qx, const vector<vector<string> >& forbidden) 
{ 

    memset(visited, 0, sizeof(visited)); 
    memset(restricted, 0, sizeof(restricted)); 

    for (auto vec : forbidden) { 

        string a = vec[0]; 
        string b = vec[1]; 
        string c = vec[2]; 

        for (auto x : a) 
            for (auto y : b) 
                for (auto z : c) { 

                    // each invalid word is 
                    // decoded and marked as 
                    // restricted = true. 
                    restricted[x - 'a'][y - 'a'][z - 'a']= true;

                    if(restricted[x - 'a'][y - 'a'][z - 'a'])
                        printf("%d %d %d\n",x-'a',y-'a',z-'a'); 
                } 
    } 

    // starting and ending letter a 
    int sa = start[0] - 'a'; 
    int ea = end[0] - 'a'; 

    // starting and ending letter b 
    int sb = start[1] - 'a'; 
    int eb = end[1] - 'a'; 

    // starting and ending letter c 
    int sc = start[2] - 'a'; 
    int ec = end[2] - 'a'; 

    if (restricted[sa][sb][sc] or restricted[ea][eb][ec]) { 

        // check if starting word 
        // or finishing word is 
        // restricted or not 
        cout << -1 << endl; 

        return; 
    } 

    // queue of nodes for BFS 
    queue<node> q; 

    // initial starting word pushed in 
    // queue. dist = 0 for starting word 
    q.push({ sa, sb, sc, 0 }); 

    // mark as visited 
    visited[sa][sb][sc] = true; 

    while (!q.empty()) { 
        
        node x = q.front(); 
        
        q.pop(); 

        // final destination reached condition 
        if (x.a == (end[0] - 'a') and x.b == (end[1] - 'a') and x.c == (end[2] - 'a')) { 

            cout << x.dist << endl; 
            return; 
        } 

        int DIST = x.dist;

        for (int i = 0; i < 6; i++) { 

            // mod 26 for circular letter sequence 

            // next letter for a 
            int A = (x.a + dx[i] + 26) % 26; 

            // next letter for b 
            int B = (x.b + dy[i] + 26) % 26; 

            // next letter for c 
            int C = (x.c + dz[i] + 26) % 26; 

            if (!restricted[A][B][C] 
                and !visited[A][B][C]) { 

                // if a valid word state, 
                // push into queue 
                q.push({ A, B, C, DIST + 1 }); 
                visited[A][B][C] = true; 
            } 
        } 
    } 

    // reach here if not possible 
    // to reach final word Y 
    cout << -1 << endl; 
} 

// Driver Code 
signed main() 
{ 
    // starting string 
    string X = "znw"; 

    // final string 
    string Y = "lof"; 

    // no of restricting word vectors 
    int N = 4; 

    vector<vector<string> > forbidden 
        = { { "qlb", "jcm", "mhoq" }, 
            { "azn", "piy", "vj" }, 
            { "by", "oy", "ubo" }, 
            { "jqm", "f", "ej" } }; 

    solve(X, Y, N, forbidden); 
    
    return 0; 
} 
