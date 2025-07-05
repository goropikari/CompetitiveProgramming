import urllib.request
import gzip
import json
import time


outdir = 'site/static/js'
path = outdir + '/submissions.json'

raw_submissions = []
start = 1514540441

try:
    with open(path, 'r') as f:
        raw_submissions = json.load(f)
    start = raw_submissions[-1]['epoch_second'] + 1
except:
    pass

while True:
    url = 'https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=goropikari&from_second=' + \
        str(start)
    req = urllib.request.Request(
        url=url,
        headers={'Accept-Encoding': 'gzip', 'Content-Type': 'application/json'}
    )
    with urllib.request.urlopen(req) as f:
        data = f.read()

    res = json.loads(gzip.decompress(data).decode('utf8'))
    if len(res) == 0:
        break
    raw_submissions.extend(res)

    start = raw_submissions[-1]['epoch_second']+1
    print(start)
    time.sleep(1)

submissions = []
ac_problems = set()

for sub in raw_submissions:
    problem_id = sub['problem_id']
    if problem_id in ac_problems:
        continue
    if sub['result'] == 'AC':
        ac_problems.add(problem_id)
        submissions.append(sub)


with open(path, 'w') as f:
    json.dump(submissions, f, indent=2)
