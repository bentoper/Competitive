def dgsum(x):
    vaca = 0
    while x > 0:
        vaca += x%10
        x = x //10
    return vaca

a = int(input())
b = int(input())
x = 0
while a <= b:
    x = x + dgsum(a)
    a = a+1

print(x)