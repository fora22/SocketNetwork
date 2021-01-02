
namespace FirstApp
{
    partial class JeonHaTalk
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.ConnectButton = new System.Windows.Forms.Button();
            this.SendButton = new System.Windows.Forms.Button();
            this.WindowRichTextBox = new System.Windows.Forms.RichTextBox();
            this.PresentChattingList = new System.Windows.Forms.RichTextBox();
            this.FirendsList = new System.Windows.Forms.RichTextBox();
            this.InputRichTextBox = new System.Windows.Forms.RichTextBox();
            this.ChattingLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(656, 351);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(128, 30);
            this.ConnectButton.TabIndex = 0;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            // 
            // SendButton
            // 
            this.SendButton.Location = new System.Drawing.Point(656, 387);
            this.SendButton.Name = "SendButton";
            this.SendButton.Size = new System.Drawing.Size(128, 35);
            this.SendButton.TabIndex = 1;
            this.SendButton.Text = "Send";
            this.SendButton.UseVisualStyleBackColor = true;
            // 
            // WindowRichTextBox
            // 
            this.WindowRichTextBox.Location = new System.Drawing.Point(26, 22);
            this.WindowRichTextBox.Name = "WindowRichTextBox";
            this.WindowRichTextBox.Size = new System.Drawing.Size(610, 318);
            this.WindowRichTextBox.TabIndex = 2;
            this.WindowRichTextBox.Text = "";
            // 
            // PresentChattingList
            // 
            this.PresentChattingList.Location = new System.Drawing.Point(655, 22);
            this.PresentChattingList.Name = "PresentChattingList";
            this.PresentChattingList.Size = new System.Drawing.Size(146, 175);
            this.PresentChattingList.TabIndex = 3;
            this.PresentChattingList.Text = "";
            // 
            // FirendsList
            // 
            this.FirendsList.Location = new System.Drawing.Point(654, 220);
            this.FirendsList.Name = "FirendsList";
            this.FirendsList.Size = new System.Drawing.Size(146, 119);
            this.FirendsList.TabIndex = 4;
            this.FirendsList.Text = "";
            // 
            // InputRichTextBox
            // 
            this.InputRichTextBox.Location = new System.Drawing.Point(26, 351);
            this.InputRichTextBox.Name = "InputRichTextBox";
            this.InputRichTextBox.Size = new System.Drawing.Size(610, 71);
            this.InputRichTextBox.TabIndex = 5;
            this.InputRichTextBox.Text = "";
            // 
            // ChattingLabel
            // 
            this.ChattingLabel.AutoSize = true;
            this.ChattingLabel.Location = new System.Drawing.Point(24, 7);
            this.ChattingLabel.Name = "ChattingLabel";
            this.ChattingLabel.Size = new System.Drawing.Size(51, 12);
            this.ChattingLabel.TabIndex = 6;
            this.ChattingLabel.Text = "Chatting";
            this.ChattingLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // JeonHaTalk
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(813, 463);
            this.Controls.Add(this.ChattingLabel);
            this.Controls.Add(this.InputRichTextBox);
            this.Controls.Add(this.FirendsList);
            this.Controls.Add(this.PresentChattingList);
            this.Controls.Add(this.WindowRichTextBox);
            this.Controls.Add(this.SendButton);
            this.Controls.Add(this.ConnectButton);
            this.Name = "JeonHaTalk";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.Button SendButton;
        private System.Windows.Forms.RichTextBox WindowRichTextBox;
        private System.Windows.Forms.RichTextBox PresentChattingList;
        private System.Windows.Forms.RichTextBox FirendsList;
        private System.Windows.Forms.RichTextBox InputRichTextBox;
        private System.Windows.Forms.Label ChattingLabel;
    }
}

