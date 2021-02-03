#!/usr/bin/python3
import math

[R, S] = list(map(int,input().split()))

ploca = [[int(b) for b in input().split()] for i in range(R)]

moves = [
	(2,1),
	(-2,1),
	(2,-1),
	(-2,-1),
	(1,2),
	(1,-2),
	(-1,2),
	(-1,-2)
]

suma = sum([sum(red) for red in ploca])

if R==S:
	if R==2:
		mred = []
		for red in ploca:
			mred.append(max(red))
		print(max(mred))
	elif R==3:
		sredina = ploca[1][1]
		print(max([sredina, suma]))
	else:
		print(suma)
	quit()

def skok(r,s,broj,ploca_):
	if ploca_[r][s] == -1:
		return 0
	for move in moves:
		vrijednosti = [0]
		(x,y) = move
		#print(r,s,x,y)
		#print(r+x,s+y)
		if 0<=r+x<R and 0<=s+y<S:
			#print(r,s,x,y)
			if ploca_[r+x][s+y]:
				print(r,s,x,y, "to")
				(n, ploca_[r][s]) = (ploca_[r][s], -1)
				if n == -1:
					n = 0
				vrijednosti.append(n + skok(r+x,s+y,broj,ploca_))
		broj += max(vrijednosti)
		print(r,s,broj)
		for red in ploca_:
			print(red)
	#broj = max(vrijednosti)
	return broj

b = 0

for i in range(R):
	for j in range(S):
		b = max([b,skok(i,j,0,ploca)])

if b > suma:
	b = suma

print(b)

#for red in ploca:
#	print(red)

print(ploca)