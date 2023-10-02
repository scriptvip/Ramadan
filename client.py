import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_address = ('localhost', 12345)
client_socket.connect(server_address)

try:
    # Send data to the server
    message = "Hello, server!"
    client_socket.sendall(message.encode())

    # Receive the response from the server
    data = client_socket.recv(1024)
    print("Received from server:", data.decode())

except Exception as e:
    print("Error:", e)

finally:
    # Close the client socket
    client_socket.close()
