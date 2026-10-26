from math import gcd
from hashlib import sha256
from secrets import randbelow

def H(m):
    return int(sha256(m.encode()).hexdigest(), 16)

def sign(m):
    h = H(m)
    while True:
        k = randbelow(p-2)+2
        if (gcd(k,p-1) != 1):
            continue
        r = pow(g,k,p)
        if (r == 0):
            continue
        s = (pow(k,-1,p-1)*(h-x*r))%(p-1)
        if (s != 0):
            return r, s

def verification(m, r, s):
    if not (1<=r<p and 1<=s<p-1):
        return False
    return (pow(g,H(m),p) == (pow(y,r,p)*pow(r,s,p))%p)


p = int(input("Enter prime p: "))
g = int(input("Enter generator g: "))
x = int(input("Enter private key x: "))
y = pow(g,x,p)
m = input("\nEnter message: ")
r, s = sign(m)
print("Public Key:", y)
print("Signature:", r, s)
print("Verification:", verification(m, r, s))
