#define ID_SIG			34
#include <stdlib.h>
#include <signal.h>

typedef	void			(*t_handling_func)(void *);

struct					s_signal
{
	void				*youzhik;
	t_handling_func		handling_func[ID_SIG];
};

void						quitting_func(void *youzhik)
{
	///restorer terminal
//	free(youzhik) (ou qqch de ce style)
	exit(EXIT_FAILURE);
}

struct s_signal					*init_static(struct s_signal *signal)
{
	static struct s_signal 	*st;

	if (signal && signal != st)
		st = signal;
	return (st);
}
void						handling_func(int sig)
{
	struct s_signal 				i_love_alexis;

	init_static(&i_love_alexis);
	if (i_love_alexis.handling_func[sig])
		((i_love_alexis.handling_func[sig]))(i_love_alexis.youzhik);
}

void						get_signal(void *youzhik)
{
	struct s_signal				sig;
	size_t					i = 0;

	sig.youzhik = youzhik;
	sig.handling_func[SIGQUIT] = &quitting_func;
	sig.handling_func[SIGABRT] = &quitting_func;
	/////// on fera cela pour tous les signaux qu'on doit gerer;
	while (i < ID_SIG)
	{
		if (sig.handling_func[i])
			signal(i, &handling_func);
		i++;
	}
}

int 						main()
{
	char				*term = "caca";

	raise(SIGQUIT);
	get_signal((void *)term);
}