1) BFS:- same as topological sort the only difference
i) for reachable node we can mark direct neighbor, but for undirected node
ii) if we reach any "node", then we can reach its all neighbor
iii) x->y and y->z then also x->z
iv) if(vis[x][y]==true and y->z) then vis[x][z]=true;
2) DFS