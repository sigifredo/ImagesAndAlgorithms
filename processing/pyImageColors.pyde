import random
cellsize = 5 # Dimensions of each cell in the grid
stch = False 

class OrderType:
    '''Enumeración que se usará para representar los diferentes tipos de ordenamiento'''
    GreaterThan = 0
    GreaterThanRed = 1
    Zigzagging = 2
    CustomOrder = 3

class Color:
    '''Clase que representa un color en una posición X,Y determinada al interior de una matriz.'''

    def __int__(self):
        '''Constructor por defecto de la clase'''
        self.x = 0
        self.y = 0
        self.col = 0

    def __init__(self, x, y, col):
        '''Constructor con la posición del color en la matriz, y el color.'''
        self.x = x
        self.y = y
        self.col = col

    def __str__(self):
        '''Método encargado del casting de un objeto de tipo Color a String'''
        return str(self.x) + ", " + str(self.y) + " -> " + str(self.col)

def setup():
    global img, cols, rows, cellsize
    size(1000, 1000)
    img  = loadImage("/home/sigifredo/imagenes/mateostoys.png")  # Load the source image
    # img  = loadImage("/home/sigifredo/imagenes/MonaLisaSmall.jpg")  # Load the source image
    cols = width/cellsize              # Calculate number of columns
    rows = height/cellsize             # Calculate number of rows

def randomOrderCriterion(colors):
    '''Crea el criterio de orden.
       :param colors: Lista de colores, con base en la cual crearemos el criterio de orden.'''
    i = 0
    colorsOrder = {}
    while len(colors) > 0:
        col = random.choice(colors)
        colors.remove(col)
        colorsOrder[col] = i
        i = i + 1

    return colorsOrder

def greaterThan(col1, col2 , colorsOrder, orderType):
    '''
       :param col1: Color 1 a comparar.
       :param col2: Color 2 a comparar.
       :param colorsOrder: criterio de orden en los colores
       :param orderType: Tipo de orden a usar.'''

    if orderType == OrderType.GreaterThan:
        return col1.col > col2.col
    if orderType == OrderType.GreaterThanRed:
        return red(col1.col) > red(col2.col)
    elif orderType == OrderType.Zigzagging:
        global stch
        if stch:
            stch = False
            return col1.col > col2.col
        else:
            stch = True
            return col1.col < col2.col
    elif orderType == OrderType.CustomOrder:
        if col1.col in colorsOrder and col2.col in colorsOrder:
            return colorsOrder[col1.col] > colorsOrder[col2.col]
        else:
            return False
    else:
        return False

def weightsBubble(wMatrix):
    '''Ordenamiento burbuja. Toma como referente para comparar el peso de las filas
       Este peso está dado por la suma de los pesos de cada columna de ésta.
       :param wMatrix: Lista de los pesos y filas de la matriz de la imagen.'''
    cpMatrix = wMatrix
    retMatrix = []

    '''Ordenamiento burbuja'''
    for num in range(len(cpMatrix)-1, 0, -1):
        for i in range(num):
            if cpMatrix[i][0] > cpMatrix[i+1][0]:
                temp = cpMatrix[i][1][0].y
                for cel in cpMatrix[i][1]:
                    cel.y = cpMatrix[i+1][1][0].y
                for cel in cpMatrix[i+1][1]:
                    cel.y = temp

    '''Creamos la matriz ordenada, tomando el segundo elemento de wMatriz'''
    for row in cpMatrix:
        # print row[0]
        retMatrix.append(row[1])

    return retMatrix

def rowsBubble(colArr, colorsOrder, orderType):
    '''Ordenamiento burbuja de cada fila de la matriz.
       :param colArr: Fila de la matriz.
       :param colorsOrder: criterio de orden.'''
    colArrSorted = colArr
    '''Burbuja'''
    for num in range(len(colArrSorted)-1, 0, -1):
        for i in range(num):
            if greaterThan(colArrSorted[i], colArrSorted[i+1], colorsOrder, orderType):
                temp = colArrSorted[i].col
                colArrSorted[i].col = colArrSorted[i+1].col
                colArrSorted[i+1].col = temp
    return colArrSorted

def calculeWeight(row, colors):
    '''Calcula el peso de cada fila. Este peso se usa para ordenar la matriz
       por filas, dependiendo del peso de éstas.'''
    w = 0
    for col in row:
        # w = w + col.col
        w = w + colors[col.col]
    return w

def orderMatrix(matrix, colorsOrder, orderType = OrderType.GreaterThan):
    '''Función encargada de ordenar la matriz.
       :param matrix: Matriz a ordenar.
       :param colorsOrder: Criterio de orden.
       :param orderType: Tipo de orden a usar. Por defecto se usa la función "Mayor qué"'''
    weightMatrix = []

    for row in matrix:
        rowSorted = rowsBubble(row, colorsOrder, orderType)
        weight = calculeWeight(rowSorted, colorsOrder)
        weightMatrix.append([weight, rowSorted])

    return weightsBubble(weightMatrix)

def draw():
    global img, cols, rows, cellsize
    colors = {}
    imgMatrix = []

    background(0)
    loadPixels()
    # Begin loop for columns
    for i in range(rows):
        imgRow = []
        # Begin loop for rows
        for j in range(cols):
            y = i*cellsize + cellsize/2  # x position
            x = j*cellsize + cellsize/2  # y position
            loc = x + y*width            # Pixel array location
            c = img.pixels[loc]          # Grab the color
            imgRow.append(Color(x, y, c))
            colors[c] = 0
        imgMatrix.append(imgRow)

    colors = colors.keys()
    bgColor = 0
    for c in colors:
        bgColor = bgColor + c
    bgColor = bgColor / len(colors)

    colorsOrder = randomOrderCriterion(colors)
    imgMatrix = orderMatrix(imgMatrix, colorsOrder, OrderType.Zigzagging)

    for row in imgMatrix:
        for col in row:
            pushMatrix()
            translate(col.x, col.y)
            fill(col.col)
            noStroke()
            rectMode(CENTER)
            rect(0, 0, cellsize + 1, cellsize + 1)
            # ellipse(0, 0, cellsize, cellsize)
            popMatrix()
