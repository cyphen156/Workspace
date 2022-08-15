class Chatbot:

    def __init__(self):
        print('call __init__')

    def __del__(self):
        print('call __del__')

    def sayHello(self):
        print("say hello")

    def sayMyName(self):
        print("My name is Kbot :D")

chatbot = Chatbot()
chatbot.sayHello()
chatbot.sayMyName()

try:
    a = 10
    b = 0
    c = a/b
    print(c)
except ZeroDivisionError as e:
    print(e)
except TypeError as e:
    print(e)