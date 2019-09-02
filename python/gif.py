

import os

def lsb2msb(lsbNum):
    msbNum = bytearray(lsbNum)
    msbNum.reverse()
    msbNum = bytes(msbNum)

    return msbNum

class Gif:
    _file = None

    def __init__(self, filePath):
        self.filePath = filePath

        if os.path.isfile(filePath):
            try:
                self._file = open(filePath, "rb")
                self.globalColorTable = []

                self._readHeader()
                self._readGlobalColorTable()
                self._readImage()

                self._file.close()
            except IOError as ex:
                print("Ha ocurrido un error abriendo el archivo: \"" + filePath + "\": " + ex.errno)
        else:
            print("El archivo \"" + filePath + "\" no existe")

    def _readHeader(self):
        version = self._file.read(6)
        version = version.decode("utf-8")

        if version.lower() == "gif89a" or version.lower() == "gif87a":
            width = self._file.read(2)
            height = self._file.read(2)
            flags = self._file.read(1)
            bgColor = self._file.read(1)
            aspectRatio = self._file.read(1)

            width = int.from_bytes(width, byteorder='little')
            height = int.from_bytes(height, byteorder='little')
            self.flags = int.from_bytes(flags, byteorder='little')

            print("dimensiones: " + str(width) + "x" + str(height))

            self.height = height
            self.width = width
        else:
            print("la cabecera no coincide con el formato GIF")

    def _readGlobalColorTable(self):
        if (self.flags & 1) == 1:
            size = self.flags & 224
            size = 2**((size >> 5) + 1)

            for i in range(size):
                color = self._file.read(3)
                color = int.from_bytes(color, byteorder='little')
                self.globalColorTable.append(color)

            print("globalColorTableSize: " + str(size) + " -> " + str(len(self.globalColorTable)))

    def _readImage(self):
        pass