#!/usr/bin/python3

import os
import sys

if len(sys.argv) > 1:
    filePath = sys.argv[1]

    if os.path.isfile(sys.argv[1]):
        fd = open(filePath, "r")
        fd.close()
    else:
        print("El archivo \"" + filePath + "\" no existe")
else:
    print("No se ha especificado la ruta del archivo \"gif\"")