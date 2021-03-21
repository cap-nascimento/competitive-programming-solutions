"""
	Anderson Vieira's solution
	Please don't copy this.
"""
def solve(t, n):
	k = [i for i in range(1, n+1)]
	s = []
	while len(t) > 0 and len(k) > 0:
		s.insert(0, k[0])
		k.remove(k[0])
		while len(s) > 0 and s[0] == t[0]:
			t.remove(s[0])
			s.remove(s[0])

	if len(t) > 0:
		return False
	return True

n = int(input())
while n > 0:
	t = list(map(int, input().split()))
	while t[0] > 0:
		if solve(t, n):
			print("Yes")
		else:
			print("No")
		t = list(map(int, input().split()))
	n = int(input())
	print()