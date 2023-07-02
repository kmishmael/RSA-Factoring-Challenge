#!/usr/bin/python3
import sys
import time

if __name__ == '__main__':
    start_time = time.perf_counter()
    p_start_time = time.process_time()

    if len(sys.argv) != 2:
        print("Usage: factors file", file=sys.stderr)
        sys.exit(-1)

    file = sys.argv[1]

    with open(file, 'r') as f:
        inputs = f.readlines()

    for line in inputs:
        num = int(line.strip())

        if num % 2 == 0:
            print("{}={}*{}".format(num, num // 2, 2))
            continue

        for c in range(3, int(num ** 0.5) + 1, 2):
            if num % c == 0:
                print("{}={}*{}".format(num, num // c, c))
                break
        else:
            print("{}={}*{}".format(num, num, 1))

    end_time = time.perf_counter()
    p_end_time = time.process_time()
    print("real: {:.3f}s".format(end_time - start_time))
    print("user: {:.3f}s".format(p_end_time - p_start_time))
    print("sys: {:.3f}s".format(end_time - start_time))
