/* This code was copied from https://www.codeproject.com/info/cpol10.aspx
 * I took this game code, witch worked with keyboard and add possibility to play using Arduino Joystick
 */

using System;
using System.Windows.Forms;

namespace Pingpong
{
    internal static class Program
    {
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}