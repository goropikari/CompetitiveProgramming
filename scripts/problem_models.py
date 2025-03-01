import urllib.request
import json
import gzip

outdir = 'site/static/js'

problem_url = 'https://kenkoooo.com/atcoder/resources/problem-models.json'
req = urllib.request.Request(
    url=problem_url,
    headers={'Accept-Encoding': 'gzip', 'Content-Type': 'application/json'}
)
with urllib.request.urlopen(req) as f:
    data = f.read()

problems = res = json.loads(gzip.decompress(data).decode('utf8'))

with open(outdir + '/problem-models.json', 'w') as f:
    json.dump(problems, f, indent=2)
