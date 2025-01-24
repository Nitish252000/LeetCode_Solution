class Solution:
    from collections import deque

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        revg=[[] for _ in range(n)]
        indegree = [0]*n

        for node, neighbors in enumerate(graph):
            for neighbor in neighbors:
                revg[neighbor].append(node)
                indegree[node]+=1
        
        queue=deque()
        for i in range(n):
            if indegree[i]==0:
                queue.append(i)

        safe=[]
        while queue:
            node = queue.popleft()
            safe.append(node)

            for neighbor in revg[node]:
                indegree[neighbor]-=1
                if indegree[neighbor]==0:
                    queue.append(neighbor)
        return sorted(safe)
