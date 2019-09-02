

from .GifUtils import readColorTable

class GifImagePart:

    class ImageOptions:
        def __init__(self):
            self.useLocalColorTable = False
            self.interlanced = False
            self.tableSorted = False
            self.reserved = 0
            self.localColorTableSize = 0

        def read(self, flags):
            self.localColorTableSize = flags & 7
            self.reserved = (flags >> 3) & 3
            self.tableSorted = ((flags >> 5) & 1) == 1
            self.interlanced = ((flags >> 6) & 1) == 1
            self.useLocalColorTable = ((flags >> 7) & 1) == 1

    class ImageData:
        def __init__(self):
            self.left = 0
            self.top = 0
            self.width = 0
            self.height = 0
            self.options = GifImagePart.ImageOptions()
            self.localColorTable = []
            self.minCodeSize = 0
            self.colorTable = []
            self.data = []

        def read(self, file):
            left = file.read(2)
            top = file.read(2)
            width = file.read(2)
            height = file.read(2)
            flags = file.read(1)

            self.left = int.from_bytes(left, byteorder='little')
            self.top = int.from_bytes(top, byteorder='little')
            self.width = int.from_bytes(width, byteorder='little')
            self.height = int.from_bytes(height, byteorder='little')
            flags = int.from_bytes(flags, byteorder='little')
            self.options.read(flags)

            if self.options.useLocalColorTable:
                self.colorTable = readColorTable(file, self.options.localColorTableSize)
            else:
                print("La imagen no tiene tabla de colores local")

    def __init__(self):
        self.imageData = []

    def read(self, file):
        while True:
            imgType = file.read(1)

            if imgType[0] == 0x3b:
                break
            else:
                if imgType[0] == 0x2c:
                    self._readLWZ(file)
                elif imgType[0] == 0x21:
                    self._readMeta(file)

    def _readLWZ(self, file):
        print("Img type LWZ")
        imageData = GifImagePart.ImageData()
        imageData.read(file)
        self.imageData.append(imageData)

    def _readMeta(self, file):
        print("Img type meta")
        subType = file.read(1)

        print("subtype: " + hex(subType[0]))

        if subType[0] == 0x01: # Plain text
            print(file.read(12))

            while True:
                block = file.read(1)

                if (block[0] == 0x0):
                    break

        elif subType[0] == 0xf9: # Graphics control
            print(file.read(5))
        elif subType[0] == 0xfe: # Comment
            while True:
                block = file.read(1)

                if (block[0] == 0x0):
                    break
        elif subType[0] == 0xff: # Application
            print(file.read(11))

            while True:
                block = file.read(1)
                print(block)

                if (block[0] == 0x0):
                    break
        # subType = int.from_bytes(subType, byteorder='little')
