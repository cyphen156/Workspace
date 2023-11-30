

namespace WinFormsEx
{
    partial class Calculator
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
            tableLayoutPanel1 = new TableLayoutPanel();
            button16 = new Button();
            button15 = new Button();
            button14 = new Button();
            button2 = new Button();
            button1 = new Button();
            button3 = new Button();
            button6 = new Button();
            button4 = new Button();
            button8 = new Button();
            button5 = new Button();
            button7 = new Button();
            button9 = new Button();
            button11 = new Button();
            button12 = new Button();
            button10 = new Button();
            button13 = new Button();
            label1 = new Label();
            button17 = new Button();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 4;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.Controls.Add(button16, 0, 3);
            tableLayoutPanel1.Controls.Add(button15, 0, 3);
            tableLayoutPanel1.Controls.Add(button14, 0, 3);
            tableLayoutPanel1.Controls.Add(button2, 1, 2);
            tableLayoutPanel1.Controls.Add(button1, 0, 2);
            tableLayoutPanel1.Controls.Add(button3, 2, 2);
            tableLayoutPanel1.Controls.Add(button6, 2, 1);
            tableLayoutPanel1.Controls.Add(button4, 0, 1);
            tableLayoutPanel1.Controls.Add(button8, 1, 0);
            tableLayoutPanel1.Controls.Add(button5, 1, 1);
            tableLayoutPanel1.Controls.Add(button7, 0, 0);
            tableLayoutPanel1.Controls.Add(button9, 2, 0);
            tableLayoutPanel1.Controls.Add(button11, 3, 0);
            tableLayoutPanel1.Controls.Add(button12, 3, 1);
            tableLayoutPanel1.Controls.Add(button10, 3, 2);
            tableLayoutPanel1.Controls.Add(button13, 0, 3);
            tableLayoutPanel1.Location = new Point(12, 46);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.Size = new Size(292, 264);
            tableLayoutPanel1.TabIndex = 0;
            tableLayoutPanel1.Paint += tableLayoutPanel1_Paint;
            // 
            // button16
            // 
            button16.Location = new Point(222, 201);
            button16.Name = "button16";
            button16.Size = new Size(67, 59);
            button16.TabIndex = 14;
            button16.Text = "+";
            button16.UseVisualStyleBackColor = true;
            button16.Click += button16_Click;
            // 
            // button15
            // 
            button15.Location = new Point(76, 201);
            button15.Name = "button15";
            button15.Size = new Size(67, 59);
            button15.TabIndex = 13;
            button15.Text = "0";
            button15.UseVisualStyleBackColor = true;
            button15.Click += button15_Click;
            // 
            // button14
            // 
            button14.Location = new Point(149, 201);
            button14.Name = "button14";
            button14.Size = new Size(67, 59);
            button14.TabIndex = 12;
            button14.Text = ".";
            button14.UseVisualStyleBackColor = true;
            button14.Click += button14_Click;
            // 
            // button2
            // 
            button2.Location = new Point(76, 135);
            button2.Name = "button2";
            button2.Size = new Size(67, 59);
            button2.TabIndex = 1;
            button2.Text = "2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.Location = new Point(3, 135);
            button1.Name = "button1";
            button1.Size = new Size(67, 59);
            button1.TabIndex = 0;
            button1.Text = "1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button3
            // 
            button3.Location = new Point(149, 135);
            button3.Name = "button3";
            button3.Size = new Size(67, 59);
            button3.TabIndex = 1;
            button3.Text = "3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button6
            // 
            button6.Location = new Point(149, 69);
            button6.Name = "button6";
            button6.Size = new Size(67, 59);
            button6.TabIndex = 4;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // button4
            // 
            button4.Location = new Point(3, 69);
            button4.Name = "button4";
            button4.Size = new Size(67, 59);
            button4.TabIndex = 2;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button8
            // 
            button8.Location = new Point(76, 3);
            button8.Name = "button8";
            button8.Size = new Size(67, 59);
            button8.TabIndex = 6;
            button8.Text = "8";
            button8.UseVisualStyleBackColor = true;
            button8.Click += button8_Click;
            // 
            // button5
            // 
            button5.Location = new Point(76, 69);
            button5.Name = "button5";
            button5.Size = new Size(67, 59);
            button5.TabIndex = 3;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button7
            // 
            button7.Location = new Point(3, 3);
            button7.Name = "button7";
            button7.Size = new Size(67, 59);
            button7.TabIndex = 5;
            button7.Text = "7";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // button9
            // 
            button9.Location = new Point(149, 3);
            button9.Name = "button9";
            button9.Size = new Size(67, 59);
            button9.TabIndex = 7;
            button9.Text = "9";
            button9.UseVisualStyleBackColor = true;
            button9.Click += button9_Click;
            // 
            // button11
            // 
            button11.Location = new Point(222, 3);
            button11.Name = "button11";
            button11.Size = new Size(67, 59);
            button11.TabIndex = 9;
            button11.Text = "÷";
            button11.UseVisualStyleBackColor = true;
            button11.Click += button11_Click;
            // 
            // button12
            // 
            button12.Location = new Point(222, 69);
            button12.Name = "button12";
            button12.Size = new Size(67, 59);
            button12.TabIndex = 10;
            button12.Text = "×";
            button12.UseVisualStyleBackColor = true;
            button12.Click += button12_Click;
            // 
            // button10
            // 
            button10.Location = new Point(222, 135);
            button10.Name = "button10";
            button10.Size = new Size(67, 59);
            button10.TabIndex = 8;
            button10.Text = "-";
            button10.UseVisualStyleBackColor = true;
            button10.Click += button10_Click;
            // 
            // button13
            // 
            button13.Location = new Point(3, 201);
            button13.Name = "button13";
            button13.Size = new Size(67, 59);
            button13.TabIndex = 11;
            button13.Text = "AC";
            button13.UseVisualStyleBackColor = true;
            button13.Click += button13_Click;
            // 
            // label1
            // 
            label1.BackColor = SystemColors.ButtonHighlight;
            label1.BorderStyle = BorderStyle.FixedSingle;
            label1.Font = new Font("맑은 고딕", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 129);
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(292, 35);
            label1.TabIndex = 1;
            label1.Text = "0";
            label1.TextAlign = ContentAlignment.MiddleRight;
            label1.Click += label1_Click;
            // 
            // button17
            // 
            button17.Location = new Point(12, 309);
            button17.Name = "button17";
            button17.Size = new Size(292, 57);
            button17.TabIndex = 2;
            button17.Text = "=";
            button17.UseVisualStyleBackColor = true;
            button17.Click += button17_Click;
            // 
            // Calculator
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ButtonHighlight;
            ClientSize = new Size(310, 379);
            Controls.Add(button17);
            Controls.Add(label1);
            Controls.Add(tableLayoutPanel1);
            Name = "Calculator";
            Text = "Calculator";
            tableLayoutPanel1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button button1;
        private Button button3;
        private Button button4;
        private Button button5;
        private Button button6;
        private Button button2;
        private Button button9;
        private Button button7;
        private Button button8;
        private Button button16;
        private Button button15;
        private Button button14;
        private Button button11;
        private Button button12;
        private Button button10;
        private Button button13;
        private Label label1;
        private Button button17;
    }
}
