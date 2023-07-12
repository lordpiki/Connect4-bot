#include "Connector.h"

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
}

void Connector::waitForClient()
{
    if (ConnectNamedPipe(_pipe, NULL))
    {
        std::cout << "Client connected." << std::endl;
        handleClient();
    }
}

void Connector::handleClient()
{
    char buffer[1024];

    while (ReadFile(_pipe, buffer, sizeof(buffer), NULL, NULL))
    {
        // Process received data (e.g., game logic)

        // Send response back to client
        std::string response = "Received data from client.";
        WriteFile(_pipe, response.c_str(), response.size(), NULL, NULL);
    }
}
