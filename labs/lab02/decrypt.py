#!/usr/bin/python3
# Variation of Caesar cipher used, find the plaintext
# 2: SPARTAN PRIDE

import collections


def freqtest(string):
    """ Frequency analysis. Most common char needs to be in ETAOINSHRDLU. If most common char is a tie, at least one has to intersect. """
    commonletters = ['E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'U']
    commonbytes = []
    for c in commonletters:
        commonbytes.append(str.encode(c))

    common = collections.Counter(string.replace(' ', '')).most_common()
    freq = common[0][1]
    letters = [c[0] for c in common if c[1] == freq]
    if set(letters) & set(commonletters):
        return True
    else:
        return False


# Read ciphertext

with open('ciphertext') as f:
    ciphertext = f.read()[:-1]

print(ciphertext)

# Do the thing!!!!!11

for shift in range(1, 26):
    text = ""
    for letter in ciphertext:
        # Only letters
        if letter > 'A' and letter < 'Z':
            char = ord(letter) + shift
            if char > ord('Z'):
                char -= 26
            text += chr(char)
        else:
            text += letter
    if freqtest(text) is True:
        print("{}: {}".format(shift, text))
