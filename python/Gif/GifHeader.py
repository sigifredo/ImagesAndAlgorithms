

from .GifUtils import readColorTable

class GifHeader:

    class Options:
        def __init__(self):
            self.useGlobalColorTable = False
            self.colorResolution = 0
            self.colorTableSorted = False
            self.globalColorTableSize = 0

        def read(self, flags):
            self.globalColorTableSize = (flags & 7)
            self.colorTableSorted = ((flags >> 3) & 1) == 1
            self.colorResolution = (flags >> 4) & 7
            self.useGlobalColorTable = ((flags >> 7) & 1) == 1

            print(self.useGlobalColorTable)
            print(self.colorResolution)
            print(self.colorTableSorted)
            print(self.globalColorTableSize)

    def __init__(self):
        self.version = ""
        self.width = 0
        self.height = 0

        self.options = GifHeader.Options()

        self.bgColor = 0
        self.aspectRatio = 0
        self.colorTable = []

    def read(self, file):
        version = file.read(6)
        version = version.decode("utf-8")

        if version.lower() == "gif89a" or version.lower() == "gif87a":
            width = file.read(2)
            height = file.read(2)
            flags = file.read(1)
            bgColor = file.read(1)
            aspectRatio = file.read(1)

            width = int.from_bytes(width, byteorder='little')
            height = int.from_bytes(height, byteorder='little')
            flags = int.from_bytes(flags, byteorder='little')
            bgColor = int.from_bytes(bgColor, byteorder='little')
            aspectRatio = int.from_bytes(aspectRatio, byteorder='little')

            print("Versión: " + version)
            print("flags: " + str(bin(flags)))
            print("dimensiones: " + str(width) + "x" + str(height))

            self.version = version
            self.height = height
            self.width = width
            self.bgColor = bgColor
            self.aspectRatio = (aspectRatio + 15) / 64
            self.options.read(flags)

            if (self.options.useGlobalColorTable):
                self.colorTable = readColorTable(file, self.options.globalColorTableSize)
            else:
                print("La imagen no tiene tabla de colores global")

            return True
        else:
            print("la cabecera no coincide con el formato GIF")
            return False