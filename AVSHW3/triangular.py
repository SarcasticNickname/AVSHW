import random

from matrix import Matrix
from rnd import Random


class Triangular(Matrix):
    def __init__(self):
       self.elements = []

    def readElements(self, str_elements, n):
        for str_element in str_elements:
            try:
                self.elements.append(float(str_element))
            except Exception:
                print("Wrong triangular matrix element.")
                return False
        return True

    def generateRandom(self, n):
        for i in range((int)(n * (n - 1) / 2)):
            self.elements.append(Random.getRandomMatrixElement())

    def out(self):
        print("This is a triangular matrix. Elements: ")
        j = 1
        i = 0
        while i < len(self.elements):
            for k in range(j):
                print(self.elements[i], end=" ")
                i += 1
            j += 1
            print()
        print("Average: ", self.average())

    def write(self, outstream):
        outstream.write("This is a triangular matrix. Elements: \n")
        j = 1
        i = 0
        while i < len(self.elements):
            for k in range(j):
                outstream.write(str(self.elements[i]) + " ")
                i += 1
            outstream.write("\n")
            j += 1
        outstream.write("Average: " + str(self.average()))

    def average(self):
        elements_sum = 0
        for element in self.elements:
            elements_sum += element
        return elements_sum/len(self.elements)
