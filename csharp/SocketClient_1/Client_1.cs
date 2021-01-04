using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SocketClient_1
{
    public partial class Client_1 : Form
    {
        public Client_1()
        {
            InitializeComponent();
        }

        private void SendButton_Click(object sender, EventArgs e)
        {
            ChatWindow.Text = ChatWindow.Text + "\n" + InputWindow.Text;
            InputWindow.Clear();
        }

        private void SendButton_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Shift && e.KeyCode == Keys.Enter) {
                InputWindow.Text = InputWindow + "\n";
                InputWindow.SelectionStart = InputWindow.Text.Length;
            } else if (e.KeyCode = Keys.Enter) {
                InputWindow.Text = ChatWindow.Text + "\n" + InputWindow.Text;

                stirng msg = InputWindow.Text;

                // Socket Send need
            }
                        
        }
    }
}
