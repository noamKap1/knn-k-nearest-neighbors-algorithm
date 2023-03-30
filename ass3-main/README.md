# ASS3
# Our Implementation:
We changed the code of the client and the server in a specific way that so the server supports unlimited amount of columns in a csv file (the request was 10) and unlimited-size messages, and for the fact that the client will not know what server receives his messages and what server sends him messages.

We changed the classify function and the classifier class so that can work with the client choosing which metric system he wants from the algorithm in run-time, then the classifier chooses the closest type which has the most votes like in ass1.

# Server:
We built the server with multithreading so he can handle time using commands on a different thread so the client will be able to send more messages while waiting for response and for handling multiple clients all in once.

# Client:
We built the client has with 2 threads the receiving thread and the sending thread so the client can keep sending messages without having to wait for response from the server.

# Compiling and Running:
## We used std::make_unique which is can't be compiled on c++11 so please run the code in c++14 (We heard in the class that you agreed to other couple and we did the same mistake).
You should use our CMakeLists.txt file to compile and run. <br/>
example: 
(we used vscode and ubuntu to compile and run)
first write: mkdir "depository name" <br/>
afterwards: cd "depository name" <br/>
afterwards: cmake .. <br/>
afterwards: make <br/>
then you should open another command-line (its like that in vscode), one for the server and one for the client. <br/>
in the first command-line write: cd server, and then ./Server <br/>
after we run the server write in the second command-line: cd client, and then ./Client <br/>
we dont provide the files so in the upload comman you should put a right path, for example open in "depository name" another depository named "files" 
and in her put the train and the test files, to uplaod the train file for example you should write the path: ../files/train.csv <br/>
after using a command press enter until you returned to the manu - press once after every command execute, for example in the confusion matrix command press enter again after the matrix is shown, same in command line result command and in file result command. <br/>
in the file result command, when we entered "result" the filed appeard in the client depository. <br/>

# Work management:
We both have equally worked on this assignment, but from convenience considerations Noam has managed the git and took care of uploading all files the readme.

# Final assignment:
**Thank you for this semester**
![**Thank you for this semester**](https://image.shutterstock.com/image-vector/thank-you-poster-spectrum-brush-260nw-1153070891.jpg)
