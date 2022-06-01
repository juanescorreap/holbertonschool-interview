#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


def print_status(size, status):
    '''
    Print the status
    '''
    print('File size: {}'.format(size))
    for key, value in sorted(status.items()):
        if value:
            print('{}: {}'.format(key, value))


if __name__ == '__main__':
    size, count = 0, 0
    status = {'200': 0, '301': 0, '400': 0, '401': 0,
              '403': 0, '404': 0, '405': 0, '500': 0}
    try:
        for line in sys.stdin:
            args = line.split()
            if len(args) > 2:
                if args[-2] in status:
                    status[args[-2]] += 1
                size += int(args[-1])
            count += 1
            if not count % 10:
                print_status(size, status)
    except KeyboardInterrupt:
        pass
    finally:
        print_status(size, status)
