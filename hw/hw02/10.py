#!/usr/bin/python3

from collections import Counter
# import math
from random import shuffle
from itertools import permutations
from copy import deepcopy

# with open('/usr/share/dict/american-english') as f:
#     eng = f.read().split('\n')

with open('commonletters') as f:
    etaoin = f.read().split('\n')[:-1]

with open('ciphertext') as f:
    ciphertext = f.read()[:-1].upper()

vowels = ['A', 'E', 'I', 'O', 'U']

# print("Ciphertext\n{}".format(ciphertext))

common = Counter(ciphertext).most_common()
print('Statistical analysis common characters:')
print(common)
print(etaoin)

print('\nStripping non-alphabet characters')
for chartuple in common:
    char = chartuple[0]
    if char < 'A' or char > 'Z':
        common.remove(chartuple)
        print("removed {}".format(repr(char)))

# Building lookup table
common = [a[0] for a in common]  # strip frequency count
replacetext = ""  # deepcopy(ciphertext)
lookup = {}

# Known
clues = [('M', 'N'), ('X', 'E'), ('D', 'V'), ('X', 'E'), ('B', 'R')]  # MXDXB->NEVER
for char, clu in clues:
    lookup[char] = clu
    if char in common:
        common.remove(char)
    if clu in etaoin:
        etaoin.remove(clu)

# ETAOIN
# for cipherletter, commonletter in zip(common, etaoin):
#     lookup[cipherletter] = commonletter

print('\nReplacing')
for cipherletter in ciphertext:
    print(cipherletter)
    if cipherletter > 'A' and cipherletter < 'Z' and cipherletter in lookup:
        # print('letter')
        replacetext += lookup[cipherletter]
    else:
        # print('nonletter')
        replacetext += cipherletter


print("""\nResults
ciphertext
{}

replaced text
{}""".format(ciphertext, replacetext))

# for perm in permutations(letters):
#     replacetext = ciphertext
#     for v in vowels:
#         replacetext = replacetext.replace(list(perm).pop(), v)
#     for word in eng:
#         if len(word) > 1 and word in replacetext:
#             print("{}\n{}".format(word, replacetext))
#             pass

# letters = [a[0] for a in common[-len(vowels):]]
# for x in range(1, 10):
#     replacetext = ciphertext
#     letters = common[-len(etaoin):]
#     shuffle(letters)
#     print(letters)
#     # Replace with every common letter
#     for c in etaoin:
#         letter = letters.pop()[0]
#         replacetext = replacetext.replace(letter, c)
#     print(replacetext)

print('end')
