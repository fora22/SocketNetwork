
namespace SocketClient_1
{
    partial class Client_1
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
            this.ChatLabel = new System.Windows.Forms.Label();
            this.ChatWindow = new System.Windows.Forms.RichTextBox();
            this.InputWindow = new System.Windows.Forms.RichTextBox();
            this.PresentFriendsList = new System.Windows.Forms.RichTextBox();
            this.FriendsList = new System.Windows.Forms.RichTextBox();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.SendButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ChatLabel
            // 
            this.ChatLabel.AutoSize = true;
            this.ChatLabel.Font = new System.Drawing.Font("굴림", 12F);
            this.ChatLabel.Location = new System.Drawing.Point(23, 20);
            this.ChatLabel.Name = "ChatLabel";
            this.ChatLabel.Size = new System.Drawing.Size(68, 16);
            this.ChatLabel.TabIndex = 0;
            this.ChatLabel.Text = "Chatting";
            // 
            // ChatWindow
            // 
            this.ChatWindow.Location = new System.Drawing.Point(26, 49);
            this.ChatWindow.Name = "ChatWindow";
            this.ChatWindow.Size = new System.Drawing.Size(541, 321);
            this.ChatWindow.TabIndex = 1;
            this.ChatWindow.Text = "";
            // 
            // InputWindow
            // 
            this.InputWindow.Location = new System.Drawing.Point(26, 386);
            this.InputWindow.Name = "InputWindow";
            this.InputWindow.Size = new System.Drawing.Size(541, 77);
            this.InputWindow.TabIndex = 1;
            this.InputWindow.Text = "";
            // 
            // PresentFriendsList
            // 
            this.PresentFriendsList.Location = new System.Drawing.Point(583, 49);
            this.PresentFriendsList.Name = "PresentFriendsList";
            this.PresentFriendsList.Size = new System.Drawing.Size(116, 114);
            this.PresentFriendsList.TabIndex = 1;
            this.PresentFriendsList.Text = "";
            // 
            // FriendsList
            // 
            this.FriendsList.Location = new System.Drawing.Point(583, 169);
            this.FriendsList.Name = "FriendsList";
            this.FriendsList.Size = new System.Drawing.Size(116, 201);
            this.FriendsList.TabIndex = 1;
            this.FriendsList.Text = "";
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(583, 386);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(116, 24);
            this.ConnectButton.TabIndex = 2;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            // 
            // SendButton
            // 
            this.SendButton.Location = new System.Drawing.Point(583, 416);
            this.SendButton.Name = "SendButton";
            this.SendButton.Size = new System.Drawing.Size(116, 47);
            this.SendButton.TabIndex = 2;
            this.SendButton.Text = "SEND";
            this.SendButton.UseVisualStyleBackColor = true;
            this.SendButton.Click += new System.EventHandler(this.SendButton_Click);
            this.SendButton.KeyDown += new System.Windows.Forms.KeyEventHandler(this.SendButton_KeyDown);
            // 
            // Client_1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(711, 475);
            this.Controls.Add(this.SendButton);
            this.Controls.Add(this.ConnectButton);
            this.Controls.Add(this.FriendsList);
            this.Controls.Add(this.PresentFriendsList);
            this.Controls.Add(this.InputWindow);
            this.Controls.Add(this.ChatWindow);
            this.Controls.Add(this.ChatLabel);
            this.Name = "Client_1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label ChatLabel;
        private System.Windows.Forms.RichTextBox ChatWindow;
        private System.Windows.Forms.RichTextBox InputWindow;
        private System.Windows.Forms.RichTextBox PresentFriendsList;
        private System.Windows.Forms.RichTextBox FriendsList;
        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.Button SendButton;
    }
}

