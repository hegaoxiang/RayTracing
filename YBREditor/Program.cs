using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace YBREditor
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Form1 form1 = new Form1();
            MessageHandler messageHandler = new MessageHandler(form1.m_displayPanel, form1);

            Application.AddMessageFilter(messageHandler);
            Application.Idle += messageHandler.Application_Idle;
            Application.Run(form1);
        }
    }
}
