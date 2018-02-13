#!/usr/bin/python3

# by asem. Copyleft 2k18

def zerosCount(n):
    r = 0
    while n:
        n //= 5
        r += n
    return r
if __name__ == "__main__":
    from sys import argv
    try:
        n = int(argv[1])
    except:
        print("[ ERROR ] Expected an integer argument")
        exit(1)
    print(zerosCount(n))
