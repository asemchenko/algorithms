#!/usr/bin/python3

# by asem. Copyleft 2k18

def zerosCount(n):
    def exp(n,base):
        r = 0
        while n:
            n//=base
            r += n
        return r
    return min(expK(n,5), expK(n,2))
if __name__ == "__main__":
    from sys import argv
    try:
        n = int(argv[1])
    except:
        print("[ ERROR ] Expected an integer argument")
        exit(1)
    print(zerosCount(n))
