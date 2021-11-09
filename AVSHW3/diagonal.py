from matrix import Matrix
from rnd import Random


class Diagonal(Matrix):
    def __init__(self):
        self.elements = []

    def readElements(self, str_elements, n):
        if len(str_elements) != n:
            print("Wrong number of elements in diagonal matrix.")
            return False
        for str_element in str_elements:
            try:
                self.elements.append(float(str_element))
            except Exception:
                print("Wrong diagonal matrix element.")
                return False
        return True

    def generateRandom(self, n):
        for i in range(n):
            self.elements.append(Random.getRandomMatrixElement())

    def out(self):
        print("This is a diagonal matrix. Elements: ")
        for element in self.elements:
            print(element, end=" ")
        print()
        print("average: ", self.average())

    def write(self, ostream):
        ostream.write("This is a diagonal matrix. Elements: \n")
        for element in self.elements:
            ostream.write(str(element) + " ")
        ostream.write("\nAverage: " +  str(self.average()))

    def average(self):
        elements_sum = 0
        for element in self.elements:
            elements_sum += element
        return elements_sum / len(self.elements)
