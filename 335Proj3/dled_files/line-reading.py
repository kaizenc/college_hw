train_lines = []
f = open("subway_entrances_cleaned.csv", "r")
for x in f:
	line = x[:-1]
	temp_arr = (line.split(",")[4]).split("-")
	for i in temp_arr:
		if i not in train_lines:
			train_lines.append(i)

f.close()
train_lines.sort()

def encode(radix, string):
	hashval = 0
	for i in string:
		hashval = ord(i) + radix*hashval
	return hashval

encoded = []
for i in train_lines:
	encoded.append(encode(33, i))


final = []
for j in range(62):
	dupes = 0
	rnum = j+1
	new = []
	for i in encoded:
		if i%rnum in new:
			dupes = 1
			break
		new.append(i%rnum)
	if(dupes == 0):
		print(rnum)
		final = new
		break

print(final)
