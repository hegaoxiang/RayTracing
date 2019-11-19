using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace YBREditor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            try
            {
                IntPtr hInstance = Marshal.GetHINSTANCE(this.GetType().Module);
                IntPtr hwnd = this.m_displayPanel.Handle;
                
                NativeMethods.EditorMain(hInstance, IntPtr.Zero, hwnd, 10, this.m_displayPanel.Width, this.m_displayPanel.Height);

            }
            catch (Exception)
            {

                throw;
            }
        }
    }
}
