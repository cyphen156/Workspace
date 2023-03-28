# file in out
## open-read/write-close//overwrite
file = open(
    "c:/workspace/Python/week4/read.txt", "r", "utf-8"
)
while True:
    if file != "null":
        file.writelines(file + "\n")
print(
    file
)
file.close();