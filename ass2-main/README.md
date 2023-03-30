# Ass2
# Implementation:

We created a class called "Socket" which acts like an interface from java. That is to make the code more polymorphic as requested.
Then, we created two classes that implement the class "Socket": Client, Server.

# Client:

Our program creates a client. 
Then, the unclassified data is sent to the server by the socket. The client after the server is done classifing receives the calculated types and writes them into a csv file which we named "result.csv".

# Server:
Our program creates a server. 
Then, the server waits for a client, when the client connects the servers gets his needed data as a string of indices separated by spaces and new lines. The server creates an Iris for each set of indices, classifies it using the Classifier class from ass1 and returns the types.

# Running:
(We used the program MobaXterm)
Do and write the commands or actions in this order:
Open to frames of the program.
Write in one of them: mkdir folderName
Write in both of them: cd folderName
Download the files and copy it to the program inside the folder named folderName.
In one of the frames write: cd server
In the second one write: cd client
In the frame which we written cd server we compile using the command "g++ *.cpp -std=c++11" and then run with the command:./a.out"
Now in the second frame we compile using the command "g++ *.cpp -std=c++11" and then run with the command:./a.out "Unclassified.csv" "result.csv"

Note: The output file is expected to be in the Client folder.
