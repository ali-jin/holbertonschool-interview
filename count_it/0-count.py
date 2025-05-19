#!/usr/bin/python3
"""Count word algorithm"""

import requests


def sort_key(x):
    """ for sort """
    return (-x[0], x[1])


def recursion(subreddit, dic, after=""):
    """returns the title counts"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    p = {"after": after}
    res = requests.get(url, headers={'User-agent': 'your bot 0.1'}, params=p,
                       allow_redirects=False)
    if res.status_code != 200:
        return None
    after = res.json().get("data").get("after")
    for re in res.json().get("data").get("children"):
        title = re.get("data").get("title").split(' ')
        title_lowercase = list(map(lambda x: x.lower(), title))
        for ch in title_lowercase:
            if ch in dic.keys():
                dic[ch] += 1
    if after is not None:
        recursion(subreddit, dic, after)
        return


def count_words(subreddit, word_list):
    """prints the title counts"""
    lower = list(map(lambda x: x.lower(), word_list))
    li = sorted(list(set(lower)))
    dup_d = dict(map(lambda x: [x, 0], li))
    for i in lower:
        dup_d[i] += 1
    d = dict(map(lambda x: [x, 0], li))
    c = recursion(subreddit, d)
    dict_p = sorted(map(lambda x, y: [x, y], d.values(), d.keys()))
    sorted_arr = sorted(dict_p, key=sort_key)
    for k, v in sorted_arr:
        if k != 0:
            print('{}: {}'.format(v, k * dup_d[v]))
