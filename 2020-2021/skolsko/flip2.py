import random

duljina = int(input())
niz = input()

count = niz.count('1')

if count != duljina-1:
	print(random.randint(1,min([count, duljina-count])))
else:
	print(1)