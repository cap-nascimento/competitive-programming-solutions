"""
    Anderson Vieira's solution
    Don't copy, try for yourself
"""
import heapq as pq
while True:
    try:
        n = int(input())
        v = []
        for i in range(n):
            d, p = map(int, input().split())
            pq.heappush(v, (d, p))
        
        ans = 1
        while(n > 0):
            p = pq.heappop(v)
            if ans < p[0]:
                ans += (p[0] - ans)
            ans += p[1]
            n-=1
        
        print(ans)

    except EOFError:
        break