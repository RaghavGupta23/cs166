Ch1 Homework
==============================

> Do problems _1-4, 6, 10-13, and 15_. [1/2 point each]
> 
> Also, find an example of a _security exploit in the news_.  Write a _1-2 paragraph summary_ using terminology from chapter 1 of the textbook (and/or the slides from class). [3 points]
> 
> Download `hw1.c`.  Add the missing `myreverse` function to this file. The function should take in an _input string, an output string, and the length of the strings_ (which may be assumed to be the same size).
> 
> You may **NOT** change the main method in any way.
> 
> Some sample executions of a reference implementation are available. Modify the comment block at the top of the file to include your information. [2 points]


## Textbook Problems

### 1

a. Define CIA
Confidentiality: ensuring information is only accessible to desired parties
Integrity: ensuring information is trustworthy and reliable
Availability: ensuring something remains accessible, not taken down by malicious party

b. Example of confidentiality over integrity
Assuming integrity isn't totally compromised, when sending sensitive images, videos, voip, internet radio, etc. the content is secret, but minor alterations in the data have almost unnoticeable changes experienced by the end user.

c. Example of integrity over confidentiality
Transmission of public keys, since it can be well known, but can't function with any alterations.

d. Example of availability over everything
As an ISP, even milliseconds of availability loss are critical.

### 2

Confidentiality vs integrity for a bank, and for its customers

Integrity is most important for the bank because they want to ensure their funds are properly handled and distributed. Users want confidentiality so others won't know their personal finances.

### 3

Paid service where users play pvp games

a. Where/why is confidentiality important
Everything about financials that are handled need confidentiality. Users' financial information like credit cards might be leaked if improperly stored and transmitted. Also the users' authentication information such as username & password, and session info.

b. Why is integrity necessary
Players' moves should be recognized as what they intended, and shouldn't be altered.

c. Availability?
If the site or it's functionality is down, users will just go elsewhere. Too many times and they switch services. You lose revenue, customer trust, and market share.

### 4 

(Same as #3)

a. Where to crypto
On the site, everywhere. Alternating between HTTP & HTTPS provides room for session cookie leaks. Any part of customer's payment method should also be encrypted. User authentication and info should be encrypted too, other than their password. Potentially the game session, although the players' moves aren't too confidentiality and integrity is more important.

b. Where to access control
Each user should be separated to and can only access their own "domains". Any administrative functionality should be strictly controlled and non-internet facing.

c. Where protocols would be used
TLS would be used to secure the site. Site owners/maintainers would probably use a VPN (IPsec, TLS, or whatever protocol chosen) or SSH to access the server.

d. Is software security a concern
Without a doubt. The web server, DB, and any other software used will be taking in user input, and they all run on some OS that also needs to be secured.

### 6

RFIDs

a. Privacy concerns regarding widespread use of RFIDs
It's very easy to fall for security through obscurity with RFIDs. People can easily capture the radio signals and retrieve the sensitive data the RFID tag originally had.

b. Other security issues
Assuming RFIDs only transmit static data, it would be hard to add any sort of or protect against replay attacks.

### 10

Enigma machine

a. Two approaches Germans could take for a broken Enigma
They could have implemented an entirely new crypto machine, but would have significance cost to implement due to changing the Enigma machine hardware. Alternatively, a slightly different algorithm could be implemented that uses existing machines, but works differently and can't be broken using Allies' existing knowledge.

b. Why was it still used after knowing it was broken
A variety of possible reasons: German high command's ineptitude, belief that it was a last stand at that point, belief that intel doesn't matter, or lack of resources to distribute a replacement.

### 11

Authenticating to your computer: username is public and password is something you know

a. Example of something you are, i.e. biometric
Fingerprint scanner

b. Example of something you have
YubiKey/FIDO U2F devices

c. Example of 2FA from everyday life
Customer service over the phone: you tell them who you are, and also provide something you know like SSN, account number, date of birth, etc.

### 12

CAPTCHAs

a. Real world example of CAPTCHAs
Various login/registration forms have CAPTCHAs. Google's newest one has you check a box, and in certain cases, choose all pictures that meet some criteria.

b. Technical methods to break it
It's a fairly new one and probably not many methods exist. It might be possible to reverse google search each image they give you and see how close it matches the criteria you're prompted with.

c. Non-technical attacks
One method I've seen is to still have the entire task scripted, but take the snippet of code for the CAPTCHA and prompt the user with it on your own side of things, and not the target website.

d. Effectiveness of CAPTCHA
In this case, it's very effective, and fast when all you need to do is check the box and no pictures are involved.

e. Hating CAPTCHAs
Some are embedded in ads, some are unreadable, and some are there just to be there and the web admin/dev is lazy to improve their site.

### 13

When security protocols fail: discuss security, convenience, user friendliness

a. Brief warning to Alice/Bob, transaction continues
Bad for security, but good for user experience. It can be used in general low risk cases such as loading static web pages, but not for secure messengers or authenticated requests for example.

b. Warning to Alice and she has to take action and confirm whether to continue the action
This is good for sensitive matters because the user has to take initiative to confirm that things can go on despite potential security issues. It's bad if the user is prompted several dozen times when loading a poorly built web page though, because they might be flooded by dozens of "the world is ending" notifications.

d. Terminate and no explanation to Alice/Bob
This is very bad for pretty much all reasons. Even though it doesn't proceed anyways and cause security issues, neither party has any idea what or even if something went wrong.

### 15

Large and complex software

a. Security issue
Complexity also provides area for misconfiguration leaving holes open to exploit.

b. Trudy and buggy software
There's a lot things that Trudy can try exploiting, and it's easier for the end uesr to believe the exploited software is just being buggy and not actually compromised.

c. How might bugs break system security
Improperly handled conditions, improperly handling input, poor uses of privilege, and providing access to system level things.


## Exploit in the News

[Cisco: Magic WebEx URL Allows Arbitrary Remote Command Execution](https://bugs.chromium.org/p/project-zero/issues/detail?id=1096)

Cisco WebEx is vulnerable to remote code execution. The meeting initialization sends commands on what to run. It uses Microsoft C Runtime and it's possible to specify system functions for it to execute. This results in a compromise of a systems integrity, and can be combined with other methods to plant malware such as a keylogger or proxy that compromises confidentiality. Alternatively, the system could be brought down entirely.
