# matplotlib -->> library, 시각화
# 나의 키성장 데이터 그래프 그리기
import matplotlib.pyplot as plt

MyGrowth = [130, 140, 150, 165, 175, 176]
age = [10, 12, 14, 16, 18, 20]
weight = [25, 38, 60, 66, 76, 80]
plt.plot(age, MyGrowth)
plt.title("My grow height")
plt.xlabel("age")
plt.ylabel("height", fontsize=15)
plt.legend()
print(plt.plot(age, MyGrowth))
plt.show()
