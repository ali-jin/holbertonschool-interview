#!/usr/bin/python3
"""Log Parsing"""

import sys


counters = {"size": 0, "lines": 1}

statusCode = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}


def printCodes():
    """
    Function to print the codes and the number of ocurrence
    """
    print("File size: {}".format(counters["size"]))
    for key in sorted(statusCode.keys()):
        # if a val is not 0
        if statusCode[key] != 0:
            print("{}: {}".format(key, statusCode[key]))


def countFileSize(listData):
    """
    Count the codes and file size
    """
    # count file size
    counters["size"] += int(listData[-1])
    if listData[-2] in statusCode:
        # count status code
        statusCode[listData[-2]] += 1


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                countFileSize(line.split(" "))
            except NameError:
                pass
            if counters["lines"] % 10 == 0:
                printCodes()
            counters["lines"] += 1
    except KeyboardInterrupt:
        printCodes()
        raise
    printCodes()
