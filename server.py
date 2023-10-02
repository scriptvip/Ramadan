import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 12345)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(5)
print("Server is listening on", server_address)

while True:
    print("Waiting for a connection...")
    client_socket, client_address = server_socket.accept()
    print("Connected to", client_address)

    try:
        # Receive data from the client
        data = client_socket.recv(1024)
        if data:
            print("Received:", data.decode())
            # Send the received data back to the client
            client_socket.sendall(data)
        else:
            print("No data received from the client.")
    except Exception as e:
        print("Error:", e)
    finally:
        # Close the client socket
        client_socket.close()
