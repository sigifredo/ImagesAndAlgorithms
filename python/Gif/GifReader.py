

import os
from .GifHeader import GifHeader

def lsb2msb(lsbNum):
    msbNum = bytearray(lsbNum)
    msbNum.reverse()
    msbNum = bytes(msbNum)

    return msbNum

class GifReader:
    _file = None

    def __init__(self, filePath):
        self.filePath = filePath
        self.header = GifHeader()

        if os.path.isfile(filePath):
            try:
                self._file = open(filePath, "rb")
                self.header.read(self._file)
                self._readImage()

                self._file.close()
            except IOError as ex:
                print("Ha ocurrido un error abriendo el archivo: \"" + filePath + "\": " + ex.errno)
        else:
            print("El archivo \"" + filePath + "\" no existe")

    def _readImage(self):
        pass
        '''
        for i in range(50):
            lwz = self._file.read(1)
            lwz = int.from_bytes(lwz, byteorder='little')
            print(hex(lwz))
        '''
