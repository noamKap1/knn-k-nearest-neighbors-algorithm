cmake_minimum_required(VERSION 3.16.3)

project(Server)
find_package(Threads)

add_executable(Server main.cpp Classifier.h Classifiable.h Flower.h
        Flower.cpp CsvReader.h CsvReader.cpp Server.cpp Server.h distances/Distance.h
        distances/EucDistance.h distances/CheDistance.h distances/ManDistance.h commands/Command.h
        IOs/DefaultIO.h commands/UploadCommand.h IOs/StandardIO.cpp
        IOs/StandardIO.h commands/ChangeAlgorithmPropertiesCommand.h IOs/SocketIO.cpp IOs/SocketIO.h
        commands/ConfusionMatrixCommand.h
        Data.h commands/ClassifyCommand.h commands/CommandLineResultsCommand.h CLI.h commands/FileResultsCommand.h)

target_link_libraries(Server ${CMAKE_THREAD_LIBS_INIT})
