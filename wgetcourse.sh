#!/bin/bash
# Download course materials from course site using recursive wget

wget -nv -l 10 -r -P ~/wget --no-check-certificate --reject="index.html?*" --header="User-Agent: Mozilla/5.0 (Windows NT 6.0) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.97 Safari/537.11" https://www.cs.sjsu.edu/~austin/cs166-spring17/
