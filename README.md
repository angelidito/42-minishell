# 42-minishell

## Things to do:<br>
1. Parse a string input
2. Execute commands

#### Parsing User Input
   - Read and tokenize the user input.
   - Turns tokens into a "readable" tree (possibly a binary tree?)
   - Handle different types of tokens (commands, arguments, redirections, etc.).

#### Command Execution
   - Implement the execution of external commands.
   - Handle built-in commands separately (e.g., `cd`, `echo`, `ls`).
   - Handle command execution with arguments and options (e.g., `ls -l -a`).

#### Redirection and Pipes
   - Handle input/output redirection using `<` and `>` symbols.
   - Implement pipe functionality using `|` symbol.
   - Redirect input/output appropriately for command execution.

#### Environment Variables
   - Implement support for environment variables (e.g., `$HOME`, `$PATH`).
   - Handle variable expansion in command arguments.

#### Signal Handling
   - Handle signals like `Ctrl+C` and `Ctrl+D`.
   - Implement signal handlers to perform appropriate actions.

#### Built-in Commands
   - Implement additional built-in commands like `env`, `setenv`, `unsetenv`.
   - Handle their functionalities according to the shell specifications.

#### Shell Prompt
   - Display a prompt to the user for input.
   - Continuously accept and process user commands until the shell is terminated.

#### Error Handling and Edge Cases
   - Implement appropriate error handling for various scenarios.
   - Consider edge cases and handle them gracefully.

#### Testing and Debugging
   - Develop test cases to verify the correctness of your shell.
   - Debug and fix any issues or unexpected behavior.

#### Documentation and Submission
   - Document the code.
   - Norminette.
   - Prepare the necessary files for submission.
