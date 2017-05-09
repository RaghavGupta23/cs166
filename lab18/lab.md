Lab 18
==============================

> Today's lab involves inspecting the assembly code for MetaPHOR, a metamorphic computer virus.
> 
> **DO NOT COMPILE THIS VIRUS ON YOUR MACHINE**
> **DO NOT COMPILE THIS VIRUS ON YOUR MACHINE**
> **DO NOT COMPILE THIS VIRUS ON YOUR MACHINE**
> 
> If you are really tempted to try it out, come and talk to me first.  There are many pitfalls to avoid, and you might destroy your machine if you are not careful.
> 
> Download the MetaPHOR virus from http://www.cs.sjsu.edu/~austin/cs166-spring17/labs/lab18/METAPHOR.ASM. Inspect the code and try to answer the following questions.

## How does it find files to infect?

Fetches drives and recursively finds files in them using `InfectFiles` and `InfectFiles2`.

## What is the payload of the virus?

Initially deletes files by clearing them and leaving the file. It has a second payload of a provocative message towards specific audiences, or just the author's name.

## What are its metamorphic techniques?

The order of the program is scrambled to random addresses, and the function offsets are assigned at runtime. An "accordion model" is also used where the code is disassembled, shrunk, expanded, and reassembled. Shrinking reduces redundancy, and expanding replaces instructions with similar ones that produce the same result.

## How does it keep from growing too large?

It limits itself as to how far into the directory structure it can traverse before stopping.

## Does it rely on encryption at any point?

Yes, although it only encrypts the payload 1/16th of the time.
