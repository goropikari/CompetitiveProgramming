#!/usr/bin/env python
# coding: utf-8

import json
import datetime


outdir = 'site/static/js'


def to_jst(unixtime):
    return datetime.datetime.fromtimestamp(
        unixtime,
        datetime.timezone(datetime.timedelta(hours=9))
    ).strftime('%Y%m%d')


def difficulty_color(x):
    if x < 400:
        return 'gray'
    if x < 800:
        return 'brown'
    if x < 1200:
        return 'green'
    if x < 1600:
        return 'cyan'
    if x < 2000:
        return 'blue'
    if x < 2400:
        return 'yellow'
    if x < 2800:
        return 'orange'
    return 'red'


with open(outdir + '/submissions.json', 'r') as f:
    submissions = json.load(f)

with open(outdir + '/problem-models.json', 'r') as f:
    problems = json.load(f)

solved_problem = set()
freq = {}
start_date = to_jst(submissions[0]['epoch_second'])
end_date = to_jst(submissions[-1]['epoch_second'])

ndt = datetime.datetime.strptime(start_date, '%Y%m%d')
edt = datetime.datetime.strptime(end_date, '%Y%m%d')
while ndt <= edt:
    s = ndt.strftime('%Y%m%d')
    freq[s] = {
        'gray': 0,
        'brown': 0,
        'green': 0,
        'cyan': 0,
        'blue': 0,
        'yellow': 0,
        'orange': 0,
        'red': 0,
    }
    ndt += datetime.timedelta(days=1)

for sub in submissions:
    if sub['result'] != 'AC':
        continue
    problem_id = sub['problem_id']
    if problem_id in solved_problem:
        continue
    try:
        solved_problem.add(problem_id)
        diff = problems[problem_id]['difficulty']
        if difficulty_color(diff) == 'red':
            print(problem_id)
            print(problems[problem_id])
        freq[to_jst(sub['epoch_second'])][difficulty_color(diff)] += 1
    except:
        pass

start_date = to_jst(submissions[0]['epoch_second'])
end_date = to_jst(submissions[-1]['epoch_second'])

ndt = datetime.datetime.strptime(start_date, '%Y%m%d')
edt = datetime.datetime.strptime(end_date, '%Y%m%d')
while ndt < edt:
    s = ndt.strftime('%Y%m%d')
    prev = freq[s]
    ndt += datetime.timedelta(days=1)
    ns = ndt.strftime('%Y%m%d')
    for k, v in freq[s].items():
        freq[ns][k] += v

with open(outdir + '/stat.json', 'w') as f:
    json.dump(freq, f, indent=2)
