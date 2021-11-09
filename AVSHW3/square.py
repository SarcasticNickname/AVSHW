from matrix import Matrix
from rnd import Random
import math


class Square(Matrix):
    def __init__(self):
        self.elements = []

    def readElements(self, str_elements, n):
        if len(str_elements) != n**2:
            print("Wrong number of elements in diagonal matrix.")
            return False
        for i in range(n):
            line = []
            for j in range(n):
                str_element = str_elements[i * n + j]
                try:
                    line.append(float(str_element))
                except Exception:
                    print("Wrong square matrix element.")
                    return False
            self.elements.append(line)
        return True

    def generateRandom(self, n):
        for i in range(n):
            line = []
            for j in range(n):
                line.append(Random.getRandomMatrixElement())
            self.elements.append(line)

    def out(self):
        n = int(len(self.elements) ** 0.5)
        print("This is a square matrix. Elements: ")
        for i in range(n):
            for j in range(n):
                print(self.elements[i][j], end=" ")
            print()
        print("Average: ", self.average())

    def write(self, ostream):
        n = (int)(len(self.elements) ** 0.5)
        ostream.write("This is a square matrix. Elements: \n")
        for i in range(n):
            for j in range(n):
                ostream.write(str(self.elements[i][j]) + " ")
            ostream.write("\n")
        ostream.write("Average: " + str(self.average()))

    def average(self):
        elements_sum = 0
        for element_line in self.elements:
            for element in element_line:
                elements_sum += element
        return elements_sum / len(self.elements)
