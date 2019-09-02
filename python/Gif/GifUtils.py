

def readColorTable(file, colorTableSize):
    print("colorTableSize: " + str(colorTableSize))
    size = 1 << (colorTableSize + 1)
    colorTable = []

    for i in range(size):
        color = file.read(3)
        # print(str(i) + ": " + str(color))
        color = int.from_bytes(color, byteorder='little')
        print(str(i) + ": " + hex(color))
        colorTable.append(color)

    print("colorTable: " + str(size) + " -> " + str(len(colorTable)))

    return colorTable