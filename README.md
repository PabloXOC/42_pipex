# 42 Pipex  

**Pipex** is a program that replicates the functionality of the shell pipeline: `< file1 cmd1 | cmd2 > file2`. It reads input from a file, processes it through two commands, and writes the final output to another file.  


## Project Overview  

The **Pipex** program takes four arguments: two file names and two shell commands with their parameters. It replicates the behavior of a shell pipeline by redirecting input and output through the specified commands, enabling powerful data processing workflows.  

## Usage  

### Syntax  

```bash  
./pipex file1 cmd1 cmd2 file2  
```  

- **file1**: The input file.  
- **cmd1**: The first shell command to execute.  
- **cmd2**: The second shell command to execute.  
- **file2**: The output file where the final result will be written.  

### Example  

1. **Command**:  
   ```bash  
   ./pipex infile "ls -l" "wc -l" outfile  
   ```  
   **Equivalent Shell Command**:  
   ```bash  
   < infile ls -l | wc -l > outfile  
   ```  

2. **Command**:  
   ```bash  
   ./pipex infile "grep a1" "wc -w" outfile  
   ```  
   **Equivalent Shell Command**:  
   ```bash  
   < infile grep a1 | wc -w > outfile  
   ```  


## Compilation Instructions

To compile the code, use the following command:

```bash
make
```

### Cleaning Up
Use the following commands for cleanup:

- `make clean`: Remove object files.
- `make fclean`: Remove object files and the compiled library.
- `make re`: Rebuild the library from scratch.



## Error Handling  

The program checks and handles the following errors:  

- Invalid file names or permissions for `file1` or `file2`.  
- Missing or invalid commands for `cmd1` or `cmd2`.

If an error occurs, the program exits cleanly with an appropriate error message.  
