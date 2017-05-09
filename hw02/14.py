#!/usr/bin/python3
# Encrypt following text with double transposition cipher, 4x4 matrix, row 1234->2413, column 1234->3124
# we are all together

plaintext = "we are all together"
plaintext = plaintext.replace(' ', '')
row = "2413"
column = "3124"

# print(list(zip(*(iter(plaintext),) * 4)))

# Rows
transpose = plaintext
print(transpose)
newtext = ""
for tpose in row:
    tpose = int(tpose) - 1
    for x in range(0, 4):
        newtext += transpose[x + tpose * 4]

# Columns
transpose = newtext
print(transpose)
newtext = ""
for tpose in column:
    tpose = int(tpose) - 1
    for x in range(0, 4):
        newtext += transpose[tpose + x * 4]

transpose = newtext
print(transpose)
# leagetwtaheolrre
