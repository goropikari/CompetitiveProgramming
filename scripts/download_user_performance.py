import json
import requests

base_url = 'https://atcoder.jp'
url = base_url + '/users/goropikari/history/json'

r = requests.get(url)

data = list(filter(lambda x: x['IsRated'], json.loads(r.text)))

with open('site/static/js/goropikari.json', 'w') as f:
    json.dump(data, f, ensure_ascii=False, indent=4)
