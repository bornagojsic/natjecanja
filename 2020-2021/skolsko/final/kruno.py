#!/usr/bin/python3
[r, s] = list(map(int,input().split()))

dvorana = [['' for i in range(s + 2)]] + [[''] +[c for c in input()] + [''] for i in range(0, r + 1) if 0 < i < r+1] + [['' for i in range(s + 2)]] 

dx = [(0,1), (0,-1), (1,0), (-1,0)]
dd = [(1,1), (1,-1), (-1,1), (-1,-1)]

def sjedala(r, s, broj, bili):
	if (dvorana[r][s] == '#' and not (r,s) in bili):
		bili.append((r,s))
		for d in dd:
			(x,y) = d
			#print(x,y,r,s)
			if dvorana[r+x][s+y] == '#':
				broj = 500
		for d in dx:
			(x,y) = d
			if (not (r+x,s+y) in bili):
				broj += sjedala(r+x,s+y, broj, bili)
	return broj + 1

N = 0

for i in range(1,r+1):
	for j in range(1,s+1):
		if 10 < sjedala(i,j,0,[]) < 100:
			N += 1

print(int(N/2))