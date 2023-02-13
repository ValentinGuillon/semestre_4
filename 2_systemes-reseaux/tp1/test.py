


a = "12345678"

b = []

i = len(a)
block = 3


while (i >= block):
	b.insert(0, a[i-3:i])
	i -= block

if (i):
	print("test")
	b.insert(0, a[:i])

print(b)

