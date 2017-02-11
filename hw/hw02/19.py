lookup = {'e': '000', 'h': '001', 'i': '010', 'k': '011', 'l': '100', 'r': '101', 's': '110', 't': '111'}

ciphertext = 'kitlke'
plaintext_a = 'thrill'
plaintext_b = 'tiller'

print("Plaintext is {}".format(plaintext_a))
for c, p in zip(ciphertext, plaintext_a):
    print(bin(int(lookup[c], 2) ^ int(lookup[p], 2)))
# Key: lkistl

print("\nPlaintext is {}".format(plaintext_b))
for c, p in zip(ciphertext, plaintext_b):
    print(bin(int(lookup[c], 2) ^ int(lookup[p], 2)))
# Key: lekekr
