using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace YBREditor
{
    class MessageHandler : IMessageFilter
    {
        Panel m_displayPanel;
        Form1 m_parent;

        public MessageHandler(Panel displayPanel, Form1 parent)
        {
            m_displayPanel = displayPanel;
            m_parent = parent;
        }

        public bool PreFilterMessage(ref Message m)
        {


            if (m.HWnd == m_displayPanel.Handle)
            {
                NativeMethods.WndProc(m_displayPanel.Handle, m.Msg, m.WParam.ToInt32(), m.LParam.ToInt32());
                return true;
            }
            return false;
        }

        public void Application_Idle(object sender, EventArgs e)
        {
            try
            {
                // Render the scene if we are idle
                NativeMethods.RenderFrame();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            m_parent.Invalidate();
        }
    }
}
