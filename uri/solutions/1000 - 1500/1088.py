"""
	Anderson Vieira's solution
	Please don't copy this
"""
def sum(bit, i):
	s = 0
	while i > 0:
		s += bit[i]
		i -= (i & (-i))
	return s

def update(bit, n, i, v):
	while i <= n:
		bit[i] += v
		i += (i & (-i))

def solve(arr, n):
	inv = 0
	m = max(arr)
	bit = [0]*(m+1)
	for i in range(n-1, -1, -1):
		inv += sum(bit, arr[i]-1)
		update(bit, m, arr[i], 1)
	return inv

en = input().split()
while en[0] != "0":
	n = []
	for i in range(len(en)): n.append(int(en[i]))
	inv = solve(n[1:], n[0])
	if inv%2 == 0:
		print("Carlos")
	else:
		print("Marcelo")
	en = input().split()

#print([i for i in range(10, 0, -1)])
