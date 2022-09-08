#!/usr/bin/python3
""" Count it! """
from requests import get


def count_words(subreddit, word_list, after="", word_dic={}):
    """ recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords """
    if not word_dic:
        for word in word_list:
            word_dic[word] = 0
    if after is None:
        word_list = [[key, value] for key, value in word_dic.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for word in word_list:
            if word[1]:
                print("{}: {}".format(word[0].lower(), word[1]))
        return None
    endpoint = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    headers = {'user-agent': 'my-app/0.0.1'}
    params = {'limit': 100, 'after': after}
    resp = get(endpoint, headers=headers, params=params, allow_redirects=False)
    if resp.status_code != 200:
        return None
    try:
        json = resp.json()
    except ValueError:
        return None
    try:
        data = json.get("data")
        after = data.get("after")
        children = data.get("children")
        for child in children:
            post = child.get("data")
            title = post.get("title")
            lower = [t.lower() for t in title.split(' ')]
            for word in word_list:
                word_dic[word] += lower.count(word.lower())
    except Exception:
        return None
    count_words(subreddit, word_list, after, word_dic)
