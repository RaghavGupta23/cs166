Lab 08
==============================
Download `Cracker.java` and `passwords.txt` from http://www.cs.sjsu.edu/~austin/cs265-spring15/lab08 (Links to an external site.).  The file `passwords.txt` provides a list of common passwords.  `Cracker.java` uses this file, parses a file of usernames and hashes, and prints out any username/password combinations it identifies.

Note that `passwords.txt` is a large file.  You may need to provide additional memory for java, like so: `java -Xms512m -Xmx512m Cracker passwords.txt input.txt`

## Part 1)

Try out this program on `input.txt` to see how it works.  What username/password combinations does it identify?

## Part 2)

Modify this program to parse `inputSalted.txt`.  This file includes the salt values as well as the usernames and hash values.  The hashes were created by `md5hash(salt+password)`.

What username/password combinations does your modified program identify?  How much slower did it run?

## Part 3)

Modify the program to account for a pepper value.  In this case, the **pepper** value is a number **between 1 and 10**.  The hashes were created by `md5hash(salt+pepper+password)`.

Again, what username/password combinations does your modified program identify?  And how much slower did this version run?  How much slower would it have been if the pepper value had been a random 40 digit hexadecimal number?
