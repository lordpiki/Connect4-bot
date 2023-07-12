using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Pipes;
using System.Windows;

namespace Connect4_GUI
{
    internal class Connector
    {
        private NamedPipeClientStream pipeClient = new NamedPipeClientStream(".", "Connect4Pipe", PipeDirection.InOut);

        public void initPipe()
        {
            try
            {
                // Connect to named pipe server
                pipeClient.Connect();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error connecting to named pipe server: " + ex.Message);
            }
        }

        public string sendData(string message)
        {
            byte[] data = Encoding.UTF8.GetBytes(message);
            pipeClient.Write(data, 0, data.Length);

            // Receive response from the server
            byte[] buffer = new byte[1024];
            int bytesRead = pipeClient.Read(buffer, 0, buffer.Length);
            string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);
            Console.WriteLine("Received response: " + response);
            return response;
        }
    }
}
