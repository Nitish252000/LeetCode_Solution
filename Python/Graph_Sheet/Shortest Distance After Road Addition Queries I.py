class Solution:
    def bfs(self, src:int, dest:int, n:int, adj:List[List[int]])->int:
        dist = [-1] * n  # Distance array, -1 means not visited
        q = deque([src])
        dist[src] = 0  # Distance to the source is 0

        while q:
            u = q.popleft()  # Dequeue a node

            for v in adj[u]:  # Visit all neighbors
                if dist[v] == -1:  # If not visited
                    dist[v] = dist[u] + 1  # Update distance
                    q.append(v)
                    if v == dest:  # Early exit if destination is reached
                        return dist[v]

        return dist[dest]  # Return the distance to the destination
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        for i in range(n-1):
            adj[i].append(i+1)
        ans=[]
        for u, v in queries:
            adj[u].append(v)
            ans.append(self.bfs(0,n-1,n, adj))
        return ans
