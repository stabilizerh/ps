PRIME = int(1e9+7)
def matrixmul(a,b):
    n,m,k = len(a),len(a[0]),len(b[0])
    rtn = [[0 for _ in range(k)] for _ in range(n)]
    for i in range(n):
        for j in range(k):
            for l in range(m):
                rtn[i][j]+= a[i][l]*b[l][j]
            rtn[i][j]%=PRIME
    return rtn

def matrixmod(a,n):
    for i in range(len(a)):
        for j in range(len(a[0])):
            a[i][j]%=n
    return a

def power(a,n):
    if n==1:
        return a
    rtn = power(a,n//2)
    rtn = matrixmul(rtn,rtn)
    if n%2==1:
        rtn = matrixmul(rtn,a)
    return matrixmod(rtn,PRIME)

