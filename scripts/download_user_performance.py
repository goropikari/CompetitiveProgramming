import json
import lxml.html
import requests

base_url = 'https://atcoder.jp'
url = base_url + '/users/goropikari/history?contestType=algo&lang=ja'

r = requests.get(url)
html = lxml.html.fromstring(r.text)

data = []
l = html.body.xpath('//table[@id="history"]//tr')
for tr in l:
    try:
        children = tr.getchildren()
        contest = children[1].getchildren()[0].text
        href = children[1].getchildren()[0].get("href")
        performance = int(children[3].getchildren()[0].text)
        rating = int(children[4].getchildren()[1].text)
        data.append({'contest': contest, 'performance': performance,
                    'rating': rating, 'url': base_url + href})
    except:
        continue

with open('site/static/js/goropikari.json', 'w') as f:
    json.dump(data, f, ensure_ascii=False, indent=4)
