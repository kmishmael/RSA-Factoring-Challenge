#!/usr/bin/python3
import sys
import time
import ctypes

if __name__ == '__main__':
    start_time = time.perf_counter()
    p_start_time = time.process_time()
    lib = ctypes.CDLL("./libfactors.so")
    factors = lib.factors
    factors.argtypes = [ctypes.c_uint64]

    if len(sys.argv) != 2:
        print("Usage: factors file", file=sys.stderr)
        sys.exit(-1)
    file = sys.argv[1]
    f = open(file, 'r')
    inputs = f.readlines()
    
    for line in inputs:
        num = int(line.strip())
        factors(num)
    end_time = time.perf_counter()
    p_end_time = time.process_time()
    #print("real: {:.3f}s".format(end_time - start_time))
    #print("user: {:.3f}s".format(p_end_time - p_start_time))
    #print("sys: {:.3f}s".format(end_time - start_time))