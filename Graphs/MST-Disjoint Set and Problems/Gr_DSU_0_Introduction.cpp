/*
Problem: Disjoint Set Union Introduction
Link: -
Difficulty: Easy
Approach: DSU
Time Complexity:
            With both optimizations (path compression + union by rank)
                findLeader() => amortized O(α(n))
                doUnion() => amortized O(α(n))
            where α is the inverse Ackermann function, which is effectively constant for any practical input size.

            Practically => O(1)
Note:
    Disjoint Set Union (also known as Union-Find) is a data structure used to efficiently manage and merge disjoint sets

        find(x) => find which set an element belongs to.
        union(a,b) => merge the sets containing a and b.
    
    ! refer to "Disjoint Set (Union-Find) Implementation" in the same folder to get a much more understandable code
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSetUnion{
public:
    int n;
    vector<int> par, rank;              // par gives immediate parent of a node (without optimization)
                                        // rank gives the height/priority of the set (higher rank = higher priority)

    DisjointSetUnion(int n){
        this->n = n;
        for (int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b){     // cant name union as union => keyword
        int parA = find(a);     // set leader of A
        int parB = find(b);     // set leader of B

        if (parA == parB)
            return;
        else if (rank[parA] == rank[parB]){      // rank of both sets are equal
            par[parB] = parA;       // set parent of set leader of B = set leader A, eff.ly connecting set B to set A
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]){  // rank of set A > set B
            par[parB] = parA;       // set parent of set leader of B = set leader A, eff.ly connecting set B to set A
        }
        else{                               // rank of set A < set B
            par[parA] = parB;       // set parent of set leader of A = set leader B, eff.ly connecting set A to set B
        }
    }

    // int find(int x){                     // without parent compression optimization
    //     if (par[x] == x)                 // deep tree 0--->1--->2--->3
    //         return x;
    //     return find(par[x]);
    // }

    int find(int x){                        // with parent compression optimization
        if (par[x] == x)                    // shallow tree 0--->1
            return x;                       //             /|
        int parent = find(par[x]);          //            / |
        par[x] = parent;                    //           /  V
        return parent;                      //          2   3

        // intuition: anytime you get the set leader (when par[x] == x), as that value is returned up the callstack,
        //            instead of directly returning it, you first set it as direct parent of current node and then return
        // now, vector<int> par still stores all direct parents of a node (set leaders) but we have made a shallow tree instead of deep
        // so par[i] will always give us the set leader and in turn reduce our Time Complexity for union and find operations
        // practically, O(1)
    }

    /*
        Union by Rank                                   Path Compression
            ↓                                                ↓
        Prevents deep trees                           Flattens trees during finds
            |                                                |
            -------------------> Together <-------------------
                                    ↓
                            Nearly O(1) operations

    */

    void getInfo(){
        for (int i=0; i<n; i++){
            cout << par[i] << " ";
        }
        cout << endl;
        for (int i=0; i<n; i++){
            cout << rank[i] << " ";
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DisjointSetUnion dsu(6);
    dsu.unionByRank(0,2);
    cout << dsu.find(2) << endl;    // 0
    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);
    cout << dsu.find(2) << endl;    // 0
    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}