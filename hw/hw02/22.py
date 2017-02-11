#!/usr/bin/python3

ciphertext = [242, 554, 650, 464, 532, 749, 567]
additive = [119, 222, 199, 231, 333, 547, 346]
codebook = {'123': 'once', '199': 'or', '202': 'maybe', '221': 'twice', '233': 'time', '332': 'upon', '451': 'a'}
plaintext = []

plaintext = [code - add for code, add in zip(ciphertext, additive)]
print([codebook[str(code)] for code in plaintext])
# once up a time or maybe twice
