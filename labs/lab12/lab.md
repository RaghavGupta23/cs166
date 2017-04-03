CSRF Lab
==============================

This lab will take you through the process of executing a cross-site request forgery (CSRF).  This attack highlights both authentication and authorization issues.  It shows how cookies are a poor mechanism for authentication, and it illustrates a practical **confused deputy** example.  (In CSRF attacks, the browser is acting as a deputy for the website by loading resources requested by the hosting page.  However, it fetches those resources with its own authority.)

All urls begin with http://cs31.cs.sjsu.edu/<groupname>/, where <groupname> will be a name that I give you.

## Part 1

Before you conduct a CSRF attack, you need to understand how a few vulnerabilities can fit together.

Go to `thanks.php`.  This page has a code injection vulnerability.  First, try out the normal functionality of the site.  In the "Hero's name" field (outlined in red), enter "Batman" and click submit.  What are the results?

Now enter:
  <span style="color:#0000FF">Batman</span>
in the Hero's name field again and hit "Submit".  What happens?

Inject another formatting tag into the same field.  Describe what you entered and the result.

Using this technique, embed the image
  http://cs31.cs.sjsu.edu/images/35274977.jpg
into the page.  Describe how you did it.

## Part 2

A banking site is available at http://cs31.cs.sjsu.edu/bank/index.php.  The login and password for your account is the same as your group name.  Partner up with another group to practice CSRF attacks.  Transfer money back and forth between your accounts and observe the GET parameters in the URL.

When you understand the mechanics of the bank, include an image in thanks.php that will cause a transfer of $987,000 from brucewayne to your account when that user visits thanks.php.  Describe how you were able to embed this image.

Once you have the image embedded and believe it will work, email me
(thomas.austin@sjsu.edu) with the link.  Let me know once you have done so.  I will play the role of brucewayne and click on your link (after logging in to the bank).

Was brucewayne's money transferred to your account?
