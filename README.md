# CyberNexus-File-Retriever
This is a C++ script that downloads a file from a specified URL using the libcurl library. It saves the file to the local file system as "file.pdf". The script also changes the file permissions to make it executable.

The script also uses the chmod function from the unistd.h header and the sys/stat.h header to change the file permissions so that the file can be executed. The S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH value sets the permissions to allow the file owner to read, write and execute, and to allow others to read and execute.

The script then runs in a loop as long as the user wants to persist. After each iteration of the loop, the script asks the user if they want to persist, and the loop continues if the answer is "y". If the user enters any other value, the script stops.

The script also includes error handling for failed curl initialization and failed file permission change. If either of these errors occur, the script will terminate.
