Lab 11
==============================

> Today we will explore the Schonlau data set. Download the masquerade data from http://www.schonlau.net/intrusion.html (Links to an external site.).
> 
> Explore the data set and note the difference between the normal user's commands and the masquerade attempts.  User 7 is one example that contains a masquerade attempt.
> 
> 1) How might you use signature detection to identify some of these attacks?  How long would the sequences need to be to avoid false positives?
> 
> 2) Consider the anomaly detection approach from the slides.  Using the first 15,000 lines of a file as "training data", how would you would use this approach to identify masquerade attempts?

## 1

Identify sequences of commands to be used as signatures. Commands such as `netscape` that might be dozens of times would need to be shortened. While sequences could be about 10 lines long, it might need to be even longer to avoid false positives.

## 2

Create a lookup table with each command and the probability of the command that follows. Anomalies would be detected by comparing with its historic probability.
