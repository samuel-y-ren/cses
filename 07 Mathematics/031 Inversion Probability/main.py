# File: main.py
# Author: Samuel Ren
# Created: 2025-06-05 13:38:01 PST
from fractions import Fraction as F

n=int(input())
r=list(map(int,input().split()))
t=F()
for i in range(0,n-1):
	for j in range(i+1,n):
		t+= (1-F(r[j]+1,r[i]*2)) if r[i]>=r[j] else F(r[i]-1,2*r[j])
print("{:.6f}".format(float(round(t,6))))