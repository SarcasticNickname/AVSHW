import random

from diagonal import Diagonal
from triangular import Triangular
from square import Square
from rnd import Random

# Класс представляем собой контейнер матриц.
class Container:
    def __init__(self):
        self.elements = []
    # Фабричный метод получает матрицы из входного файла и заполняем ими контейнер.
    @staticmethod
    def getFromFile(instream):
        # Читаем все строки файла.
        all_lines = instream.readlines()
        # Убираем все символы перевода строки.
        map(lambda line: line.replace("\n", "").encode(), all_lines)
        container = Container()
        i = 0
        while i < len(all_lines):
            # Получаем строку с описанием матрицы.
            info_line = all_lines[i].split(" ")
            i += 1
            # Описание состоит из 2 чисел: типа матрицы и параметр n матрицы.
            # Получаем описание и проверяем на валидность.
            if len(info_line) != 2:
                print("Wrong format of input data. Line with matrix type and length is incorrect.")
            matrix_type, n = info_line[0], info_line[1]
            matrix_type_num = int(matrix_type)
            matrix_elements_num = int(n)
            elements_line = all_lines[i].split(" ")
            i += 1
            # Создаём матрицу нужного типа.
            if matrix_type_num == 1:
                matrix = Diagonal()
            elif matrix_type_num == 2:
                matrix = Square()
                for j in range(matrix_elements_num - 1):
                    elements_line.extend(all_lines[i].split(" "))
                    i += 1
            elif matrix_type_num == 3:
                matrix = Triangular()
            else:
                return False
            if not matrix.readElements(elements_line, matrix_elements_num):
                return False
            container.elements.append(matrix)
        return container

    @staticmethod
    def generateRandom(n):
        container = Container()
        for i in range(n):
            k = random.randint(1, 4)
            length = Random.getRandomMatrixLength()
            if k == 1:
                matrix = Diagonal()
                matrix.generateRandom(length)
            elif k == 2:
                matrix = Square()
                matrix.generateRandom(length)
            else:
                matrix = Triangular()
                matrix.generateRandom(length)
            container.elements.append(matrix)
        return container

    def print(self):
        print("Container is fill. ", len(self.elements), "matrices.")
        for matrix in self.elements:
            matrix.out()
        print("Overall average: ", self.average())

    def write(self, outstream):
        outstream.write("Container has {} elements\n".format(len(self.elements)))
        for matrix in self.elements:
            matrix.write(outstream)
            outstream.write("\n")
        outstream.write("Overall average: " + str(self.average()))

    def rearrange(self):
        container_param = []
        overall_average = self.average()
        for i in range(len(self.elements)):
            if self.elements[i].average() > overall_average:
                container_param.append(self.elements[i])

        for i in range(len(self.elements)):
            if self.elements[i].average() <= overall_average:
                container_param.append(self.elements[i])
        self.elements = container_param

    def average(self):
        elements_sum = 0
        for matrix in self.elements:
            elements_sum += matrix.average()
        return float(elements_sum) / len(self.elements)
