"""
	Anderson Vieira's solution
	Please don't copy this
"""
class el:
	def __init__(self, v, m):
		self.v = v
		self.m = m

	def __lt__(self, other):
		ms, mo = 0, 0
		if self.v < 0: ms = -((-self.v)%self.m)
		else: ms = self.v%self.m

		if other.v < 0: mo = -((-other.v)%self.m)
		else: mo = other.v%self.m

		if ms == mo:
			if self.v%2 != 0 and other.v%2 == 0:
				return True
			if self.v%2 == 0 and other.v%2 != 0:
				return False
			if self.v%2 == 0 and other.v%2 == 0:
				return self.v < other.v
			if self.v%2 != 0 and other.v%2 != 0:
				return self.v > other.v
		return ms < mo

n, m = map(int, input().split())
while n != 0 and m != 0:
	arr = []
	for i in range(n):
		x = int(input())
		arr.append(el(x, m))

	arr.sort()
	print(n, m)
	for i in range(n): print(arr[i].v)
	n, m = map(int, input().split())
print(n, m)