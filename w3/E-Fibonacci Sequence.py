# URAL 1133
Unit = [[1, 1], [1, 0]]

def mul(a, b):
	ans = [[0 for i in range(0, len(a))] for j in range(0, len(b))]
	for i in range(0, len(a)):
		for j in range(0, len(b)):
			for k in range(0, len(b)):
				ans[i][j] += a[i][k] * b[k][j]
	return ans

def POW(n):
	a = Unit
	b = [[1, 0], [0, 1]]
	while n > 0:
		if n & 1:
			b = mul(a, b)
		a = mul(a, a)
		n >>= 1
	return b

def cal(i, Fi, j, Fj, n):
	mat = POW(j-1)
	[Left, Right] = [int(-2*1e9), int(2*1e9)]
	while Left <= Right:
		mid = (Left + Right) >> 1
		x = mat[0][0] * mid + mat[0][1] * Fi
		if x > Fj:
			Right = mid - 1
		elif x < Fj:
			Left = mid + 1
		else:
			break
	
	if n > 0:
		mat = POW(n - 1)
		print(mid*mat[0][0] + Fi*mat[0][1])
	else:
		[Fa, Fb] = [mid, Fi]
		for i in range(n, 0):
			[Fa, Fb] = [Fb, Fa - Fb]
		print(Fb)


if __name__ == '__main__':
	[i, Fi, j, Fj, n] = [int(i) for i in input().split(' ')]
	if i > j:
		[i, j] = [j, i]
		[Fi, Fj] = [Fj, Fi]
	j -= i
	n -= i
	i = 0
	cal(i, Fi, j, Fj, n)
