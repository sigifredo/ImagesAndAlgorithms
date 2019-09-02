

class GifImagePart:

    def __init__(self):
        pass

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
        pass

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
