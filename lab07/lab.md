Lab
==============================

> Part 1 -- Shamir's Secret Sharing
> Alice's share of the secret is (12,7).
> Bob's share of the secret is (18, 9).
> What is the secret number?
> 
> Part 2 -- Steganography
> Download http://www.cs.sjsu.edu/~stamp/CS166/files/stego.zip and unzip it.
> What are the file sizes of `alice.bmp` and `aliceStego.bmp`?
> 
> Compile `stegoRead.c` with gcc.  (Other compilers might work as well,
> though there are some issues with Visual Studio).
> Run the file against `aliceStego.bmp` to produce a pdf.
> Inspect the pdf.  Is it a valid file?
> 
> Compile `stego.c` and use it to hide a file of your choosing in `alice.bmp`.
> Is there any difference in file size for the new image?
> Send the new bitmap to your partner.
> Is he or she able to read the file from the bitmap?

## Part 1

(12, 7)
(18, 9)
secret = (0, S)

slope = (9-7) / (18-12) = 2/6 = 1/3

Y intercept = Y - slope * X
= 7 - 1/3 * 12
= 7 - 4
= **3**

## Part 2

Yes, retrieved pdf appears to be completely valid.

Stegan-ized image has the same size. The retrieved file can be read and has the same SHA256 sum as the original file.
