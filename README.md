# 42-minishell

###### Specifications:

- [X] Display a prompt when waiting for a new command.
- [X] Have a working history.
- [ ] Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- [ ] Not use more than one global variable. Think about it. You will have to explain its purpose.
- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as \(backslash) or ;(semicolon).
- [ ] Handle `'` (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence.
- [ ] Handle `"` (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for `$` (dollar sign).
- [ ] Implement redirections:
  - [ ] `<` should redirect input.
  - [ ] `>` should redirect output.
  - [ ] `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - [ ] `>>` should redirect output in append mode.
- [ ] Implement pipes ( `|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [ ] Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
- [ ] Handle `$?` which should expand to the exit status of the most recently executed
  foreground pipeline.
- [ ] Handle `ctrl-C`, `ctrl-D` and `ctrl-\` which should behave like in bash.
- [ ] In interactive mode:
  - [ ] `ctrl-C` displays a new prompt on a new line.
  - [ ] `ctrl-D` exits the shell.
  - [ ] `ctrl-\` does nothing.
- [ ] Your shell must implement the following builtins:
  - [ ] `echo` with option -n
  - [ ] `cd` with only a relative or absolute path
  - [ ] `pwd` with no options
  - [ ] `export` with no options
  - [ ] `unset` with no options
  - [ ] `env` with no options or arguments
  - [ ] `exit` with no options

## Things to do:`<br>`

1. Parse a string input
2. Execute commands

#### Parsing User Input

- Lexer read and tokenize the user input.
- Parser turns tokens into a "readable" tree (possibly a binary tree?)
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

## Resources:

- [42 Docs - Minishell](https://harm-smits.github.io/42docs/projects/minishell)
  - [Writting your own shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
  - [Shell Syntax](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
- [Hardvard about Shell](https://cs61.seas.harvard.edu/site/2019/Section7/)
- [Bash Cookbook](https://theswissbay.ch/pdf/Gentoomen%20Library/Programming/Bash/O%27Reilly%20bash%20CookBook.pdf)
- [Mindblowing tree of how sell thinks](https://ast-viewer.datacamp.com/editor?code=.%2Fscript%5C%20of%5C%20four%5C%20words%20arg1%20%22arg%20number%202%22%20%27%20arg3%20%27%20%20%20%22%20arg%20%27number%204%27%20this%20is%20%5C%22bad%5C%22%20...%22%0A%0A.%2F%22script%20of%20four%20words%22%20arg1%20%22arg%20number%202%22%20%27%20arg3%20%27%20%20%20%22%20arg%20%27number%204%27%20this%20is%20%5C%22bad%5C%22%20...%22%0A&start=NA&grammar=shell)
- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/html_node/index.html#SEC_Contents)
- [Termios](https://dev.to/tanishqsingla/termios-564j)
