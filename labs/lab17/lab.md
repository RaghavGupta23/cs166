Lab 17
==============================

This lab focuses on cross-site scripting (XSS) and SQL injection attacks. Form a group of 2-3 people and get a group name from me. The url for this exercise is http://cs31.cs.sjsu.edu/[groupname]/thanks.php, where [groupname] is the name of your group.

1. First we will look at reflected XSS attacks. Go to `/thanks.php`. In the "Hero's name" field (outlined in red), enter:

```html
<script>alert("I am Gotham's reckoning")</script>
```

Try this with Firefox, Chrome, and either Internet Explorer or Safari. What is the difference in behavior between the different browsers?

While most browsers include XSS filters (or have addons like NoScript), they are not foolproof.  Experiment with the "show search params" button on `/thanks.php`.  Using this feature, bypass Chrome's XSS filter to change the first `h1` element on the page to be green. Describe how you did this.

Using a **stored** XSS attack, inject code into thanks.php that changes the first HTML element on the page to read "Kneel Before Zod!". JavaScript's `document.getElementById` and `innerHTML` features may be useful.


2. Using SQL injection, get the full password list, stored in the user1 table. Note that the page `/thanks.php` does not properly sanitize its input. Describe what you did and list all username/password combinations in the table.
