#!/usr/bin/python3

import os
import sys
import gif

if __name__ == "__main__":

    if len(sys.argv) > 1:
        gifObj = gif.Gif(sys.argv[1])
    else:
        print("No se ha especificado la ruta del archivo \"gif\"")
