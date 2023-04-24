package week7.ex1;

    public class Main {
        private static final int User_NUM = 5;
        public static void main(String[] args) {
            User[] user = new User[User_NUM];
            for (int i = 0; i < User_NUM; i++) {
                user[i] = new User((i + 1) + "-user");
                user[i].print();
            }
        }
    }

