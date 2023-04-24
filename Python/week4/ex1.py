# file in out
## open-read/write-close//overwrite
file = open(
    "c:/workspace/Python/week4/read.txt", mode="r", encoding="utf-8"
)
# while True:
#     if file is None:
#         file.write("file\n")

print(
    file.read()
)
file.close()