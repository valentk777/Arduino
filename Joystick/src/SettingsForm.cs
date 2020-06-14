using System;
using System.Drawing;
using System.Windows.Forms;

namespace Pingpong
{
    public partial class SettingsForm : Form
    {
        public SettingsForm() => InitializeComponent();

        private void NumericUpDown_ValueChanged(object sender, EventArgs e)
        {
            var Btn = (NumericUpDown)sender;
            if (Btn.Value > 0)
            {
                switch (Btn.Name)
                {
                    case "numericUpDown1":
                        Properties.Settings.Default.BallSpeed = (int)numericUpDown1.Value;
                        break;

                    case "numericUpDown2":
                        Properties.Settings.Default.Timer_Enemy = (int)numericUpDown2.Value;
                        break;

                    case "numericUpDown3":
                        Properties.Settings.Default.Timer_Movement = (int)numericUpDown3.Value;
                        break;

                    case "numericUpDown4":
                        Properties.Settings.Default.EnemySpeed = (int)numericUpDown4.Value;
                        break;

                    case "numericUpDown5":
                        Properties.Settings.Default.Speed_Player = (int)numericUpDown5.Value;
                        break;
                }
            }
            else
            {
                Btn.Value = 1;
            }
            Properties.Settings.Default.Save();
        }

        private void PictureBox4_Click(object sender, EventArgs e)
        {
            ColorDialog CD = new ColorDialog();
            if (CD.ShowDialog() == DialogResult.OK)
            {
                pictureBox4.BackColor = CD.Color;
                Properties.Settings.Default.Color_Player = CD.Color;
            }
            Properties.Settings.Default.Save();
        }

        private void PictureBox3_Click(object sender, EventArgs e)
        {
            ColorDialog CD = new ColorDialog();
            if (CD.ShowDialog() == DialogResult.OK)
            {
                pictureBox3.BackColor = CD.Color;
                Properties.Settings.Default.Color_Enemy = CD.Color;
            }
            Properties.Settings.Default.Save();
        }

        private void PictureBox2_Click(object sender, EventArgs e)
        {
            ColorDialog CD = new ColorDialog();
            if (CD.ShowDialog() == DialogResult.OK)
            {
                pictureBox2.BackColor = CD.Color;
                Properties.Settings.Default.Color_Ball = CD.Color;
            }
            Properties.Settings.Default.Save();
        }

        private void PictureBox1_Click(object sender, EventArgs e)
        {
            ColorDialog CD = new ColorDialog();
            if (CD.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.BackColor = CD.Color;
                Properties.Settings.Default.Color_Frame = CD.Color;
            }
            Properties.Settings.Default.Save();
        }

        private void SettingsForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.OpenForms["Form1"].Focus();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            pictureBox1.BackColor = Color.White;
            pictureBox2.BackColor = Color.Black;
            pictureBox3.BackColor = Color.Red;
            pictureBox4.BackColor = Color.Green;

            numericUpDown1.Value = 6;
            numericUpDown2.Value = 10;
            numericUpDown3.Value = 1;
            numericUpDown4.Value = 1;
            numericUpDown5.Value = 5;

            Properties.Settings.Default.Timer_Enemy = 10;
            Properties.Settings.Default.Timer_Movement = 1;
            Properties.Settings.Default.BallSpeed = 6;
            Properties.Settings.Default.EnemySpeed = 1;
            Properties.Settings.Default.Speed_Player = 5;
            Properties.Settings.Default.Color_Ball = Color.Black;
            Properties.Settings.Default.Color_Frame = Color.White;
            Properties.Settings.Default.Color_Enemy = Color.Red;
            Properties.Settings.Default.Color_Player = Color.Green;

            Properties.Settings.Default.Save();
        }

        private void SettingsForm_Load(object sender, EventArgs e)
        {
            pictureBox1.BackColor = Properties.Settings.Default.Color_Frame;
            pictureBox2.BackColor = Properties.Settings.Default.Color_Ball;
            pictureBox3.BackColor = Properties.Settings.Default.Color_Enemy;
            pictureBox4.BackColor = Properties.Settings.Default.Color_Player;

            numericUpDown1.Value = Properties.Settings.Default.BallSpeed;
            numericUpDown2.Value = Properties.Settings.Default.Timer_Enemy;
            numericUpDown3.Value = Properties.Settings.Default.Timer_Movement;
            numericUpDown4.Value = Properties.Settings.Default.EnemySpeed;
            numericUpDown5.Value = Properties.Settings.Default.Speed_Player;
        }
    }
}