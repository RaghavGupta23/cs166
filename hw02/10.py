#!/usr/bin/python3

from collections import Counter
from pprint import pprint

# with open('/usr/share/dict/american-english') as f:
#     eng = f.read().split('\n')

with open('commonletters') as f:
    etaoin = f.read().split('\n')[:-1]

with open('ciphertext') as f:
    ciphertext = f.read()[:-1].upper()

common = Counter(ciphertext).most_common()
print('\nStripping non-alphabet characters')
for chartuple in common:
    char = chartuple[0]
    if char < 'A' or char > 'Z':
        common.remove(chartuple)
        print("removed {}".format(repr(char)))

print('Statistical analysis common characters:')
print(common)
print(etaoin)

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


def lookupreplace(ciphertext, lookup):
    result = ""
    for cipherletter in ciphertext:
        if cipherletter >= 'A' and cipherletter <= 'Z':
            if cipherletter in lookup:
                result += lookup[cipherletter]
            else:
                result += ' '
        else:
            result += cipherletter
    return result


replacetext = lookupreplace(ciphertext, lookup)

while True:
    print("Cipher Text:\n{}\nReplaced Text:\n{}\n".format(ciphertext, replacetext))
    pprint(lookup)
    replace = input('Replace: ')
    if replace in lookup:
        print("Already replaced with {}, overwriting".format(lookup[replace]))
    char = input('With: ')
    lookup[replace] = char
    replacetext = lookupreplace(ciphertext, lookup)

print("""\nResults
ciphertext
{}

replaced text
{}""".format(ciphertext, replacetext))
