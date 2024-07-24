#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef enum e_null_ptr_representation
{
    NULL_PTR_0X0,
    NULL_PTR_NIL,
    NULL_PTR_NULL
} t_null_ptr_representation;

extern t_null_ptr_representation null_ptr_rep;

void init_null_ptr_representation(void);
const char *null_ptr_representation_to_string(t_null_ptr_representation rep);

int ft_printf(const char *p, ...);

#endif
