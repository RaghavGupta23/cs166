Lab 15
==============================

For this lab, we will look at buffer overflows and the tools that we can use to exploit them.

1) Download http://www.cs.sjsu.edu/~austin/cs166-spring17/labs/lab15/heapOverflow.c.
Compile and run the program.  What is the output?

Note that both print statements will display the contents of buff2.
Why are the results different?

2) Download http://www.cs.sjsu.edu/~austin/cs166-spring17/labs/lab15/serial.c.
Compile and run the program.

What does it print if you enter the correct serial number?
What does it do if you enter an incorrect number?
What happens if you enter a very long serial number?

Now pretend that you don't know the serial number.
Delete the source file from your system.
Try to enter in a serial number that will cause a buffer overflow
such that the serial number will be displayed.

The point of the lab is to experiment with the different tools,
so do not worry if you cannot break it in the time given.
Submit the details of your attempts.

However, anyone who succeeds before the due date (and can prove it to me)
will get 5 points extra credit.  You will need to show me step-by-step
what you did, so screenshots may come in handy.

Some tools that may come in handy:

A hexdump utility, such as xxd.  Some text editors can also edit binary files.

A dissassembler.  Some choices:
  -http://www.onlinedisassembler.com/odaweb/
  -http://www.ollydbg.de/
  -otool (OSX)
  -IDA Pro (Commercial product) https://hex-rays.com/products/ida/index.shtml


