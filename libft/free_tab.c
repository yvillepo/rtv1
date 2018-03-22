#include "libft.h"

void    free_tab(char **tabstr)
{
        if (!tabstr)
                return ;
        while (*tabstr)
        {
                if (*tabstr)
                        free(*tabstr);
                tabstr++;
        }
        *tabstr = NULL;
}

void    free_tabstr(char ***tabstr)
{
        free_tab(*tabstr);
        if (*tabstr)
                free(*tabstr);
}
