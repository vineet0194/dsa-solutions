/*
Problem: Dijkstra Algorithm
Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Difficulty: Medium
Approach: Greedy BFS (Dijkstra)
Time Complexity: O((V+E)logV)       =>      O(ElogV) after simplification
                        as, (V+E)logV = VlogV + ElogV => at max number of edges for undircted = v(v-1)/2, directed = v(v-1)
                        so we put E = v(v-1)/2  => ElogV becomes ~ V^2logV, now compared to VlogV this is greater so we can
                        ignore the lower term => O(ElogV)
Note:
    ! Greedy BFS !
    --> single source shortest path algo
    --> always used for positive weighted graphs only
    --> at every node, we ask
            if dist(src->u->v) is < dist(src->v)    // src->v might have come from some other path not invl u
                yes => set new dist(src->v) = dist(src->u) + dist(u->v)
                    this means: we have discovered a new shortest path for src->v and it goes through u
                                we need to consider this path and push dist[v],v to the queue
                no => dont consider path and dont push

    Why only push nodes into the queue when we get value less than dist[v]?
        so basically, this algorithm is checking if src->u->v is less than src->v, if not then we dont consider u!
        and hence take whatever distance we had already dist[v] and whatever path it came from will be managed
        by that distance itself

    --------------------------------------------------------------------------------------------------------------
    
    priority_queue<int> pq;     always sorts the pq at each insertion/deletion on the basis of elem passed
                                by default, we make a max-heap pq => always keeps max elem at front
    
    priority_queue<int, vector<int>, greater<int>> pq;  is used to create a min heap of type 'int'
        replace 'int' in all 3 parameters with whatever type of data you want
        just remember if you use pair/vector etc. (multiple elems) => pq sorting is always done by the first elem

    pq => insertion/deletion = O(logn) , top/size = O(1)
    
    here we do:
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        we are storing a pair<int, int> where first integer gives us dist[v] and second gives v
        we cannot do the vice-versa as then sorting will not be done using dist[v] which is what we want.

    ! why dijkstra doesnt support negative weight edges or cycles !
    because once a node is popped from the pq with the smallest distance, that distance is final.
        This assumption is only true when all edge weights are non-negative.

        Dijkstra's algorithm assumes that when a node is extracted from the priority queue with the currently
        smallest distance, that distance is the shortest possible distance from the source. This assumption holds
        only when all edge weights are non-negative. If a negative weight edge exists, a shorter path to a node
        may be discovered later through another route, invalidating the distance that was previously considered ptimal.
        As a result, the algorithm may process nodes in the wrong order and produce incorrect shortest path distances.
*/

class Solution {
  public:
    void implementDijkstra(int src, vector<int>& dist, vector<vector<pair<int, int>>>& neighbours){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({dist[src], src});
        
        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for (auto& neigh : neighbours[u]){      // for all children
                int v = neigh.first;
                int wt = neigh.second;          // u to v
                if (dist[v] > dist[u] + wt){        // if (src->v is > src->u->v) 
                    dist[v] = dist[u] + wt;        // => set dist[v] to src->u->v
                    pq.push({dist[v], v});
                }
            }
        }
    }
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        vector<vector<pair<int, int>>> neighbours(V, vector<pair<int, int>>{});
        
        for (auto& edge: edges){
            neighbours[edge[0]].push_back({edge[1],edge[2]});
            neighbours[edge[1]].push_back({edge[0],edge[2]});
        }
        
        implementDijkstra(src, dist, neighbours);
        
        return dist;
    }
};