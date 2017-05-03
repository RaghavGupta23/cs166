#!/usr/bin/python3
# Python solution to Ch. 7 problem 37

"""
Problem 37

Iris scan with 64 bit iris codes

| User    | Iris code        |
| ------- | ---------------- |
| Alice   | BE439AD598EF5147 |
| Bob     | 9C8B7A1425369584 |
| Charlie | 885522336699CCBB |
| U       | C975A2132E89CEAF |
| V       | DB9A8675342FEC15 |
| W       | A6039AD5F8CFD965 |
| X       | 1DCA7A54273497CC |
| Y       | AF8B6C7D5E3F0F9A |

d(x,y) = different bits / total bits

A. Compute the distances d(Alice,Bob), d(Alice,Charlie), d(Bob,Charlie)
B. Which users are most likely Alice, Bob, and Charlie?
"""


def hex2bin(hexstr):
    """ Convert hex to binary string """
    bytestr = bytes.fromhex(hexstr)
    binstr = ''
    for b in bytestr:
        binstr += '{0:08b} '.format(b)
        # binstr += bin(b) + ' '
    return binstr


def bindist(b1, b2):
    """ distance between two binary strings, assumed to be equal len """
    dist = 0
    for x in range(0, len(b1)):
        if b1[x] != b2[x]:
            dist += 1
    return dist


def hexdist(h1, h2):
    """ Distance between two hex strings """
    return bindist(hex2bin(h1), hex2bin(h2))


alice = 'BE43'
bob = '9C8B'
charlie = '8855'
x = 'C975'

enroll = dict(
    alice=alice,
    bob=bob,
    charlie=charlie,
)
recog = dict(x=x)

for user in sorted(enroll.keys()):
    # print(user)
    dist = hexdist(enroll.get(user), recog.get('x'))
    print('d({:8}, x) = {:2} ({:.3})'.format(user, dist, dist / (4 * 4)))
