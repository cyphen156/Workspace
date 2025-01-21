class Node:
    def __init__(self, element, link=None):
        self.data = element  # 노드의 데이터
        self.link = link     # 다음 노드에 대한 링크

    # 연결 리스트의 모든 노드를 출력하는 함수
    def display(self, msg="LinkedList:"):
        node = self
        print(msg, end=" ")
        while node is not None:
            print(node.data, end=" -> " if node.link else "")
            node = node.link
        print()  # 줄바꿈

# 첫 번째 노드
head = Node("Kim")
print("리스트 출력 : ", head.data, head.link)
print("****************줄바꿈*********************")
# 두 번째 노드
temp1 = Node("Lee")
head.link = temp1  # 첫 번째 노드가 두 번째 노드를 가리키도록 설정

# 세 번째 노드
temp2 = Node("Cho")
temp1.link = temp2  # 두 번째 노드가 세 번째 노드를 가리키도록 설정


head.display()

print("##########줄바꿈#########")
# 연결 리스트 출력
head.display("연결 리스트:")

# 첫 번째 노드의 데이터 출력
print("첫 노드의 자료:", head.data)

# 첫 번째 노드를 삭제하는 방식으로 리스트를 갱신
head = head.link

# 첫 번째 노드를 삭제한 후 연결 리스트 출력
head.display("삭제 후 연결 리스트:")
