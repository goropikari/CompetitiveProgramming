import json
import sys
import urllib.request
import gzip

args = sys.argv


def gen():
    if len(args) < 2:
        print("Usage: python gen.py abc/123")
        return
    s = args[1].split('/')
    contest_id = ''.join(s[-2:])
    problems = get_problems()
    for problem in problems:
        if problem['contest_id'] == contest_id:
            print(
                '## {}\n\nhttps://atcoder.jp/contests/{}/tasks/{}\n'.format(
                    problem['title'],
                    contest_id,
                    problem['id']
                )
            )


def get_problems():
    url = 'https://kenkoooo.com/atcoder/resources/problems.json'
    req = urllib.request.Request(url, headers={'Accept-Encoding': 'gzip'})
    with urllib.request.urlopen(req) as res:
        dec = gzip.GzipFile(fileobj=res)
        body = dec.read().decode('utf-8')

    return json.loads(body)


if __name__ == '__main__':
    gen()
