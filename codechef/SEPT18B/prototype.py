import random
import copy
k=8
P = [x for x in range(1,k+1)]
count = {}
def foo(P, j):
    if(j == k):
        try:
            count[str(P)] += 1
            return
        except KeyError:
            count[str(P)] = 1
            return
    for i in range(k):
        P[i], P[j] = P[j], P[i]
        foo(copy.deepcopy(P), j+1)
        P[i], P[j] = P[j], P[i]
    return
foo(P, 0)
min=827240261886336764177
max=0
for key, value in count.items():
    if value > max:
        max = value
    if value < min:
        min = value
print(k)
print("MAX:")
for key, value in count.items():
    if value == max:
        print(key)
print("MIN:")
for key, value in count.items():
    if value == min:
        print(key)