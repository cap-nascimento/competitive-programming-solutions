import math as m

def pot(a, b):
	ans = 0;
	for i in range(b):
		ans += m.log2(a)
	return ans

def fat(a):
	ans = 0
	while a > 0:
		ans += m.log2(a)
		a-=1
	return ans

n = int(input())

pl, pp = 0, 0
results = []

for i in range(n):
	l = input()
	p = input()
	la = pot(int(l.split('^')[0]), int(l.split('^')[1]))
	pa = fat(int(p.split('!')[0]))
	if la > pa:
		pl+=1
		results.append('L')
	else:
		pp+=1
		results.append('P')

if pl > pp:
	print("Campeao: Lucas!")
elif pl < pp:
	print("Campeao: Pedro!")
else:
	print("A competicao terminou empatada!")

for i in range(1, n+1):
	if results[i-1] == 'L':
		print("Rodada #{0}: Lucas foi o vencedor".format(i))
	elif results[i-1] == 'P':
		print("Rodada #{0}: Pedro foi o vencedor".format(i))
