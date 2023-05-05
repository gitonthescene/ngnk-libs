#!/opt/local/bin/python
import zlib
import sys
import argparse


def decompress():
    data = sys.stdin.buffer.read()
    decom = zlib.decompress(data)
    sys.stdout.buffer.write(decom)


def compress():
    data = sys.stdin.buffer.read()
    decom = zlib.compress(data)
    sys.stdout.buffer.write(decom)


def crc():
    data = sys.stdin.buffer.read()
    ret = zlib.crc32(data)
    sys.stdout.write(f'{ret}')


def main():
    parser = argparse.ArgumentParser(
        prog='png-helper',
        description='Tools for working with png files in ngn/k')
    parser.add_argument('-d', '--decompress', action='store_true')
    parser.add_argument('-c', '--compress', action='store_true')
    parser.add_argument('-r', '--crc', action='store_true')

    args = parser.parse_args()
    if not sum([args.decompress, args.compress, args.crc]) == 1:
        print("Must supply exactly one of --decompress, --compress or --crc")
        parser.print_help()
        return

    if args.decompress:
        decompress()
    elif args.compress:
        compress()
    else:
        crc()


if __name__ == '__main__':
    main()
