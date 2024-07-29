#!/usr/bin/python3
"""
UTF-8 module
"""


def validUTF8(data):
    """ Check if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): List of integers that are the bytes.

    Returns:
        Bool: If the data set is a valid UTF-8 encoding, return true.
                Otherwise False.
    """
    num_of_bytes = 0

    for value in data:
        if num_of_bytes > 0:
            if value >> 6 != 0b10:
                return False
            num_of_bytes -= 1
        else:
            if value >> 7 == 0:
                num_of_bytes = 0
            elif value >> 5 == 0b110:
                num_of_bytes = 1
            elif value >> 4 == 0b1110:
                num_of_bytes = 2
            elif value >> 3 == 0b11110:
                num_of_bytes = 3
            else:
                return False

    return num_of_bytes == 0
