import os.path
import sys

from container import Container

def errMessage1():
    print("The input file doesn't exist.")

def errMessage2():
    print("The output file doesn't exist or can't be created.")

def errMessage3():
    print("Couldn't fill the container. Wront data in the file.")

def errMessage4():
    print("Wrong command format. Right command format")
    print("python main -f <input_file_path> [<output_file_path>]. Or")
    print("python main -n <number_of_generated_matrices> [<output_file_path>]")


 # Проверяем валидность команды, введённой из командной строки.
if len(sys.argv) == 4:
    input_mode = sys.argv[1]
    input_info = sys.argv[2]
    output_info = sys.argv[3]
elif len(sys.argv) == 3:
    input_mode = sys.argv[1]
    input_info = sys.argv[2]
    output_info = "output.txt"
else:
    errMessage4()
    exit(0)
# Если выбран режим генерации случайных матриц, то генерируем.
if input_mode == "-n":
    # Проверяем, верно ли введено число генерируемых матриц.
    if not str.isdigit(input_info):
        print("Number of generating matrices is not valid.")
        exit(0)
    number_of_matrices = int(input_info)
    # Допустимые границы - от 1 до 10000 матриц.
    if number_of_matrices < 1 or number_of_matrices > 10000:
        print("Incorrect number of generated elements. Must be 1 <= n <= 10000")
        exit(0)
    container = Container.generateRandom(number_of_matrices)
# Если выбран режим чтения данных из файла, то читаем.
elif input_mode == "-f":
    # Проверяем, существует ли файл.
    if not os.path.isfile(input_info):
        errMessage1()
        exit(0)
    # Проверяем, не пустой ли файл.
    if os.path.getsize(input_info) == 0:
        print("Input file is empty.")
        exit(0)
    input_file = open(input_info, "r")
    container = Container.getFromFile(input_file)
    # Если не смог открыть файл, то выводим сообщение об ошибке.
    if not container:
        errMessage3()
        exit(0)
    # Проверяем, существует ли введённая директория для выходного файла.
else:
    errMessage4()
    exit(0)

output_file = open(output_info, "w")
if not output_file:
    errMessage2()
    exit(0)
# Выводим исходный контейнер в консоль.
container.print()
# Записываем исходный контейнер в файл.
container.write(output_file)
# 2 задание.
container.rearrange()

print("Rearranged container")
output_file.write("\nRearranged container\n")
# Выводим изменённый контейнер в консоль.
container.print()
# Записываем изменённый контейнер в файл.
container.write(output_file)