#include "Connector.h"
#include <string>

#define BOARD_HEIGHT 6
#define BOARD_WIDTH 7

#define YELLOW 'Y'
#define RED 'R'
#define NO_MOVE '-'

Connector::Connector()
{
    connectPipeline();
}

Connector::~Connector()
{
    DisconnectNamedPipe(_pipe);
    CloseHandle(_pipe);
}

bool Connector::connectPipeline()
{

    // Create named pipe
    _pipe = CreateNamedPipeA("\\\\.\\pipe\\Connect4Pipe", PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, 1024, 1024, 0, NULL);

    if (_pipe == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to create named pipe.";
        return 1;
    }

    std::cout << "Waiting for client connection..." << std::endl;
    waitForClient();
}

void Connector::waitForClient()
{
    if (ConnectNamedPipe(_pipe, NULL))
    {
        std::cout << "Client connected." << std::endl;
    }
}

void Connector::handleClient()
{
    char buffer[2];

    while (ReadFile(_pipe, buffer, sizeof(buffer), NULL, NULL))
    {
        // Process received data (e.g., game logic)
        buffer[1] = NULL;
        cout << buffer << endl;
        // Send response back to client
        std::string response = "Received data from client.";
        WriteFile(_pipe, response.c_str(), response.size(), NULL, NULL);
    }
}

void Connector::sendBoardToClient(const string& resp)
{
    WriteFile(_pipe, resp.c_str(), BOARD_WIDTH*BOARD_HEIGHT + 1, NULL, NULL);
}

int Connector::getCol()
{
    char buffer[1];

    if (!ReadFile(_pipe, buffer, sizeof(buffer), NULL, NULL))
    {
        cout << "Connection lost, disconnecting" << endl;
        exit(1);
    }
    return buffer[0] - '0';
}
