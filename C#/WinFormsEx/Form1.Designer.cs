

namespace WinFormsEx
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            button1 = new Button();
            label2 = new Label();
            textBox3 = new TextBox();
            button2 = new Button();
            button3 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(240, 158);
            label1.Name = "label1";
            label1.Size = new Size(59, 15);
            label1.TabIndex = 0;
            label1.Text = "로그인 창";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            label1.Click += Label1_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(222, 176);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(100, 23);
            textBox1.TabIndex = 1;
            textBox1.Text = "ID";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(222, 205);
            textBox2.Name = "textBox2";
            textBox2.PasswordChar = '*';
            textBox2.Size = new Size(100, 23);
            textBox2.TabIndex = 2;
            textBox2.Text = "Password";
            textBox2.TextChanged += TextBox2_TextChanged;
            // 
            // button1
            // 
            button1.Location = new Point(222, 234);
            button1.Name = "button1";
            button1.Size = new Size(100, 30);
            button1.TabIndex = 3;
            button1.Text = "로그인 하기";
            button1.UseVisualStyleBackColor = true;
            button1.Click += Button1_Click;
            // 
            // label2
            // 
            label2.Location = new Point(220, 202);
            label2.Name = "label2";
            label2.Size = new Size(150, 30);
            label2.TabIndex = 4;
            label2.Text = "게임을 시작합니다.";
            label2.Visible = false;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(156, 224);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(100, 23);
            textBox3.TabIndex = 5;
            textBox3.Visible = false;
            // 
            // button2
            // 
            button2.Location = new Point(287, 223);
            button2.Name = "button2";
            button2.Size = new Size(75, 23);
            button2.TabIndex = 6;
            button2.Text = "입력";
            button2.UseVisualStyleBackColor = true;
            button2.Visible = false;
            button2.Click += Button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(240, 253);
            button3.Name = "button3";
            button3.Size = new Size(75, 23);
            button3.TabIndex = 7;
            button3.Text = "게임 시작";
            button3.UseVisualStyleBackColor = true;
            button3.Visible = false;
            button3.Click += Button3_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(548, 409);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(textBox3);
            Controls.Add(label2);
            Controls.Add(button1);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox textBox1;
        private TextBox textBox2;
        private Button button1;
        private Label label2;
        private TextBox textBox3;
        private Button button2;
        private Button button3;
    }
}
