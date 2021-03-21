"""
	Anderson Vieira's solution
	Please don't copy this.
"""
def solve(t, s):
	ans = ""
	k = []
	while len(t) > 0 and len(s) > 0:
		ans += "I"
		k.insert(0, s[0])
		s.remove(s[0])
		while len(k) > 0 and k[0] == t[0]:
			t.remove(k[0])
			k.remove(k[0])
			ans += "R"

	if len(t) > 0:
		ans += " Impossible"
	return ans

n = int(input())
while n > 0:
	s = list(map(str, input().split()))
	t = list(map(str, input().split()))
	print(solve(t, s))
	n = int(input())