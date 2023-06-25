

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

typedef struct s_vars
{
	char	*infile;
	char	**cmds;
	char	*outfile;
	// char	**envp;
	char	**path;
	t_list	**_envp;
	t_list	**envp;
	int		here_doc;
	char	*here_doc_lim;
	char	**here_doc_limiters;
	int		output_flag;
}			t_vars;

#endif
