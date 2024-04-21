# Mini Shell Command Executor

## Overview

This project is a minimalist command-line interpreter (shell) capable of executing standard Unix commands, handling directory changes, and facilitating command pipelining. Designed to work on POSIX-compliant systems, it leverages core system calls to execute and manage processes efficiently. This shell is perfect for educational purposes, offering a glimpse into the workings of more sophisticated shells.

## Features

- **Command Execution**: Directly runs typical UNIX commands as entered by the user.
- **CD Command Support**: Explicitly handles `cd` for changing the working directory.
- **Piping**: Allows for single-level piping (`|`), linking the output of one command directly to the input of another.
- **Error Handling**: Outputs error messages for incorrect commands or failed operations directly to standard error (stderr).

## Usage Examples and Operational Expectations

Here's how you can expect this mini shell to function with various examples of usage:

###  **Running Simple Commands**
   - **Example**: Executing `ls`
   - **Expectation**: Lists all files and directories in the current directory.

###  **Displaying Text**
   - **Example**: Using `echo "Hello, World!"`
   - **Expectation**: Prints "Hello, World!" to the console.

###  **Filtering Output with grep**
   - **Example**: Combining `ls` with `grep` as in `ls | grep "2024"`
   - **Expectation**: Lists files and then filters to show only those containing "2024".

###  **Changing Directories**
   - **Example**: Navigating to another directory with `cd /usr/local`
   - **Expectation**: Changes the current directory to `/usr/local`. If the directory does not exist, an error message is displayed.

###  **Combining Multiple Commands with Pipe**
   - **Example**: Using `cat file.txt | grep "data"`
   - **Expectation**: Displays lines from `file.txt` that contain the word "data".

###  **Handling Errors**
   - **Example**: Entering a non-existent command like `xyz`
   - **Expectation**: The shell returns an error message indicating that the command could not be found or executed.

###  **Using Wildcards in Commands**
   - **Example**: `ls *.txt`
   - **Expectation**: Lists all `.txt` files in the current directory.

###  **Viewing File Contents**
   - **Example**: Viewing the content of a file with `cat example.txt`
   - **Expectation**: Outputs the contents of `example.txt` to the screen.

###  **Directing Output to a File**
   - **Example**: Redirecting the output to a file as in `ls > files.txt`
   - **Expectation**: The list of directory contents will be written to `files.txt` instead of being displayed on the terminal.

###  **Showing Command Execution History**
   - **Example**: Typing a history command might not be supported directly, but one could implement or simulate it.
   - **Expectation**: Displays previously executed commands, if implemented.

###  **Checking Command Status**
   - **Example**: After running commands, check the status with `echo $?`
   - **Expectation**: Outputs the exit status of the last command executed, which can help in scripting and debugging.

These examples illustrate the basic functionality expected from this mini shell, providing a clear guide on how to use it effectively for various common tasks in a Unix-like environment.

## Future Enhancements

While the current version of the shell provides basic functionality, future enhancements might include:

- **Multiple Command Execution**: Support for sequences of commands separated by semicolons (e.g., `ls; echo Done`).
- **Advanced Piping**: Handling multiple levels of piping to allow more complex command chaining.
- **Improved Error Diagnostics**: Enhanced error messages that provide more detailed diagnostic information to help with troubleshooting.

## Conclusion

This minimal shell is a practical tool for learning about system processes, command execution, and shell programming. It serves as a foundational platform for those interested in deeper Unix system exploration or developing more complex shell environments.
