#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# ifdef __APPLE__
#  define OP OPEN_MAX
# elif _WIN32 || _WIN64 || __linux__
#  define OP FOPEN_MAX
# else
#  error "Unsupported operating system"
# endif

int ft_printf(const char *p, ...);

#endif
