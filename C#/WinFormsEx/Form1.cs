namespace WinFormsEx
{
    public partial class Form1 : Form
    {
        private int findNumber = 0;
        private int chance = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            string UId = textBox1.Text;
            string UPw = textBox2.Text;
            if (UId.Equals("Admin"))
            {
                if (UPw.Equals("12345678"))
                {
                    MessageBox.Show("로그인 성공", "로그인");
                    label1.Visible = false;
                    textBox1.Visible = false;
                    textBox2.Visible = false;
                    button1.Visible = false;
                    label2.Visible = true;
                    textBox3.Visible = true;
                    button2.Visible = true;
                    button3.Visible = true;
                }
                else
                {
                    MessageBox.Show("비밀번호가 다릅니다.", "WrongPassword");
                }
            }
            else
            {
                MessageBox.Show("아이디가 다릅니다.", "invalid ID");
            }
            
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            int inputNumber = Int32.Parse(textBox3.Text);
            if ( inputNumber == findNumber)
            {
                label2.Text = "승리했습니다.!!\n계산기로 이동합니다.";
                // 계산기 폼으로 이동
                Calculator calculatorForm = new Calculator();
                calculatorForm.Show();
            }
            else
            {
                chance--;
                label2.Text = "기회는" + chance + "번 남았습니다.";
            }

            if (chance <= 0)
            {
                label2.Text = "실패하였습니다.";
            }
        }
        private void Button3_Click(object sender, EventArgs e)
        {
            var rand = new Random();
            findNumber = rand.Next(1, 10);
            chance = 10;
            label2.Text = "맞힐 숫자를 입력하세요.";
        }
    }
}