public class MatchParen extends Stack {

    static void match() {
        MatchParen stk = new MatchParen();
        System.out.print("수식을 입력하세요 --> ");
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        String[] data = str.split(" ");
        char ch;
        int i;
        boolean notMatch = false;
        for (i=0; i<data.length; i++) {
            for (int j=0; j<data[i].length(); j++){
                ch = data[i].charAt(j);
                switch(ch) {
                    case ' ':
                        
                    case '(': case '{': case '[':
                        stk.push(ch);
                        break;
                    case ')':
                        if(stk.isEmpty() || (char)stk.pop()!='(')
                        notMatch = true;
                    break;
                    case ']':
                        if(stk.isEmpty() || (char)stk.pop()!='[')
                        notMatch = true;
                    break;
                    case '}':
                        if(stk.isEmpty() || (char)stk.pop()!='{')
                        notMatch = true;
                    break;
                }
                if(notMatch) break;
            }
        
            // if(stk.isEmpty() && i == data.length())
            if (stk.isEmpty() && !notMatch)
                System.out.println("괄호가 맞음");
            else 
                System.out.println("괄호가 맞지 않음");
        }
    }
   
   public static void main(String args[]) {
      MatchParen.match();
   }

}