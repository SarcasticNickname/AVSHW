import random


class Random:
    @staticmethod
    def getRandomMatrixElement():
        return random.randint(-100, 100) + random.random()

    @staticmethod
    def getRandomMatrixLength():
        return random.randint(2, 31)
