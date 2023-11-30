using System;

namespace Class 
{
    class Robot {
        public void move() {
            Console.WriteLine("로봇이 움직입니다.");
        }
    }

    class CleanRobot : Robot { // 상속

        public void move() {
            System.Console.WriteLine("청소로봇이 움직입니다.");
        }
        public void clean() {
            System.Console.WriteLine("로봇이 청소를 시작합니다.");
        }
    }

}
