class Node {
    constructor(element, link = null) {
        this.data = element;  // 노드의 데이터
        this.link = link;     // 다음 노드에 대한 링크
    }

    // 연결 리스트의 모든 노드를 출력하는 함수
    display(msg = "LinkedList:") {
        let node = this;
        process.stdout.write(msg + " ");
        while (node !== null) {
            process.stdout.write(node.data + (node.link ? " -> " : ""));
            node = node.link;
        }
        console.log();  // 줄바꿈
    }
}

// 첫 번째 노드
let head = new Node("Kim");

// 두 번째 노드
let temp1 = new Node("Lee");
head.link = temp1;  // 첫 번째 노드가 두 번째 노드를 가리키도록 설정

// 세 번째 노드
let temp2 = new Node("Cho");
temp1.link = temp2;  // 두 번째 노드가 세 번째 노드를 가리키도록 설정

// 연결 리스트 출력
head.display("연결 리스트:");

// 첫 번째 노드의 데이터 출력
console.log("첫 노드의 자료:", head.data);

// 첫 번째 노드를 삭제하는 방식으로 리스트를 갱신
head = head.link;

// 첫 번째 노드를 삭제한 후 연결 리스트 출력
head.display("삭제 후 연결 리스트:");
