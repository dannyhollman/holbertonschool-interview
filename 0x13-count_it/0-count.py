#!/usr/bin/python3
""" find number of times words occur in subreddit titles """
import requests


def make_dictionary(word_list, dic):
    """ make dictionary from word list """
    for word in word_list:
        dic[word] = 0


def count_words(subreddit, word_list, dic={}, count=0):
    """ count words from list in subreddit titles """
    if len(dic) == 0:
        make_dictionary(word_list, dic)
    try:
        u = 'https://api.reddit.com/r/{}/hot'.format(subreddit)
        h = {'User-Agent': 'test'}
        p = {'limit': 100}
        response = requests.get(u, headers=h, params=p, allow_redirects=False)
        posts = response.json()['data']['children']
        if count == len(posts) - 1:
            printed = 0
            for k, v in sorted(dic.items()):
                if v > 0:
                    print('{}: {}'.format(k, v))
                    printed += 1
            if printed == 0:
                print()
            return
        for word in word_list:
            for split in posts[count]['data']['title'].lower().split(' '):
                if word == split:
                    dic[word] += 1
        return count_words(subreddit, word_list, dic, count + 1)

    except:
        print()
        return
