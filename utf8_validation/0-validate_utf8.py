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

    for byte in data:
        mask = 1 << 7
        if num_of_bytes == 0:
            while mask & byte:
                num_of_bytes += 1
                mask = mask >> 1
            if num_of_bytes == 0:
                continue
            if num_of_bytes == 1 or num_of_bytes > 4:
                return False
        else:
            if not (byte & mask and not (byte & (mask >> 1))):
                return False
        num_of_bytes -= 1
    return num_of_bytes == 0
