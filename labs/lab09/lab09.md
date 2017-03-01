Lab 09
==============================

## Part 1

> Create 2 passwords from the following phrases

I am the one who knocks

`i am the one who kn0ckS`
`iatowknocks`

Winter is coming.

`winter is com1nG`
`wintericoming`

Why so serious?

`why so seri0uS?`
`whysserious`

One ring to rule them all.

`one ring to rule them @11`
`oneringtruleta`

Convention:

1. lower case with space, some symbols/numbers with last word
2. one big concatenated word with conjunctions and other words abbreviated

## Part 2

### 1

> Password dump of 1024 passwords, dictionary of 2^20 common passwords, can hash 2^30 per second. How long to test all passwords?

2^10 * 2^20 / 2^30
= 2^30 / 2^30
= 1

It only takes one second

### 2

> Site has pepper of random key 2^128, how long now? What if pepper is determined?

Pepper expected in first half tries: 2^128 / 2 = 2^127
2^127 pepper values / 2^30 hash per second
= 2^97 seconds
= 5e21 years!

Many, many years to find the pepper, although on the good side, it'll only take ~1 second after finding the pepper!
