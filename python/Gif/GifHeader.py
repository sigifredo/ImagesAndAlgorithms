

class GifHeader:

    class Options:
        def __init__(self):
            self.useGlobalColorTable = False
            self.colorResolution = 0
            self.colorTableSorted = False
            self.globalColorTableSize = 0

        def read(self, flags):
            self.useGlobalColorTable = (flags & 1) == 1
            self.colorResolution = (flags >> 1) & 7
            self.colorTableSorted = ((flags >> 4) & 1) == 1
            self.globalColorTableSize = (flags >> 5) & 7

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
            flags = int.from_bytes(flags, byteorder='big')
            print("flags: " + str(bin(flags)))

            print("dimensiones: " + str(width) + "x" + str(height))

            self.version = version
            self.height = height
            self.width = width
            self.bgColor = bgColor
            self.aspectRatio = aspectRatio
            self.options.read(flags)
            self._readGlobalColorTable(file)

            return True
        else:
            print("la cabecera no coincide con el formato GIF")
            return False

    def _readGlobalColorTable(self, file):
        if self.options.useGlobalColorTable:
            size = 2**(self.options.globalColorTableSize + 1)

            for i in range(size):
                color = file.read(3)
                color = int.from_bytes(color, byteorder='little')
                self.colorTable.append(color)

            print("colorTable: " + str(size) + " -> " + str(len(self.colorTable)))
        else:
            print("El gif no tiene tabla de colores global")