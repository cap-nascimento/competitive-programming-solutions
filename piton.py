# Anderson's solution
t = int(input())
while t > 0:
    s = input()
    print(s[0], end='')
    for i in range(1, len(s)-1, 2):
        print(s[i], end='')
    print(s[len(s)-1])
    t-=1
