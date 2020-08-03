
#include "ft_printf.h"

t_data	*initialize(t_data *ptr, const char *format)
{
	if (!(ptr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	ptr->format = format;
	ptr->len = 0;
	ptr->i = 0;
	ptr->minus = 0;
	ptr->plus = 0;
	ptr->space = 0;
	ptr->hash = 0;
	ptr->zero = 0;
	ptr->field_width = 0;
	ptr->precision = 0;
	ptr->length = 0;
	ptr->f_print = (char *)ptr->format;
	ptr->f_copy = (char *)ptr->format;
	return (ptr);
}

int		ft_printf(const char *format, ...)
{
	t_data *ptr;
	va_list	args;

	// function that create struct
	if (!(ptr = initialize(ptr, format)))
		return (-1);

	if (format)
	{
		va_start(args, format);
		ptr->len = parser(ptr);
		va_end(args);
	}

	// clear struct
	free(ptr);

	// return (length of string)
	return (ptr->len);
}


