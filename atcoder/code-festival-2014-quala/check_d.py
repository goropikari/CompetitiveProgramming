import os

files = os.listdir('test_d')
sets = {}

for f in files:
    if f.endswith('.in') or f.endswith('.out'):
        basename, ext = os.path.splitext(f)
        sets.setdefault(basename, {})[ext[1:]] = f

for basename, pair in sets.items():
    in_file = 'test_d/' + pair.get('in')
    out_file = 'test_d/' + pair.get('out')
    if in_file and out_file:
        with open(in_file, 'r') as f_in:
            line = f_in.read().strip()
            A_str, K_str = line.split()
            A = int(A_str)
            K = int(K_str)
        with open(out_file, 'r') as f_out:
            X = int(f_out.read().strip())
        l = set(list(str(abs(A+X))))
        r = set(list(str(abs(A-X))))
        if not (len(l) <= K or len(r) <= K):
            print(f"Set: {basename}  A={A}  K={K}  X={X}")
