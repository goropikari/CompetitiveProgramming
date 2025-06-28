import sys
from bs4 import BeautifulSoup
from urllib import request

args = sys.argv


def gen():
    if len(args) < 2:
        print("Usage: python gen.py abc/123")
        return
    s = args[1].split('/')
    contest_id = ''.join(s[-2:])
    problems = get_problems(contest_id)
    for problem in problems:
        print(
            '## {}\n\nhttps://atcoder.jp/contests/{}/tasks/{}\n'.format(
                problem['title'],
                contest_id,
                problem['id']
            )
        )


def get_problems(contest_id):
    url = 'https://atcoder.jp/contests/{}/tasks'.format(contest_id)

    response = request.urlopen(url)
    soup = BeautifulSoup(response, 'lxml')
    response.close()
    problems = []
    for tr in soup.find('tbody').find_all('tr'):
        tds = tr.find_all('td')
        ls = []
        for td in tds:
            ls.append(td.text.strip())
        ls.append(tds[0].a['href'])

        problem = {}
        problem['title'] = "{}. {}".format(ls[0], ls[1])
        problem['id'] = ls[-1].split('/')[-1]
        problems.append(problem)

    return problems


if __name__ == '__main__':
    gen()
