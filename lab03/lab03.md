Lab 3
==============================

For the A5/1 cipher, on average, how often:

1. Does the X register step?

    **3/4** of the time, because 1/2 of the time Y would be opposite of X, and 1/2 those cases Z would be same as Y making X in the minority and not stepping. Since the chance of X not stepping is 1/4, the chance X would step is 3/4.

2. Does the Y register step?

    Same as X.

3. Does the Z register step?

    Same as X.

4. Do all 3 registers step?

    **1/4** of the time, as 1/2 of the time X and Y would be the same, and 1/2 of those times Z would be the same bit value.

5. Do exactly 2 registers step?

    **3/4** of the time, since 1/1 of the time X is 1 or 0. There's a 1/2 chance that Y xor Z is the same as X, and 1/4 chance they're the same as each other but different from X. The sum is 3/4.

6. Does exactly 1 register step?

    **Never**, as there can't be only 1 in a majority out of 3.

7. Does no register step?

    **Never**, there will always be a majority out of 3.
