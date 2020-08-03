

#include "ft_printf.h"

int	next_parser(t_data *ptr)
{
	//check for arguments after '%'
	// %[флаги][ширина][.точность][размер]тип
	// type is mandatory
	ptr->i++;
	if (ptr->f_copy[ptr->i] == // flags)
	{
		// ptr->len += function;

	}
	else if (ptr->f_copy[ptr->i] == //width)
	{
		// ptr->len += function;
	}
	else if (ptr->f_copy[ptr->i] == //precision)
	{
		// ptr->len += function;
	}
	else if (ptr->f_copy[ptr->i] == //length)
	{
		// ptr->len += function;
	}
	else if (ptr->f_copy[ptr->i] == //type)
	{
		// ptr->len += function;
	}
	return (ptr->len);
}

int	parser(t_data *ptr)
{
	// check if format valid
	/*
	if (ft_strcmp(ptr->f_copy, "%") == 0)
		return (0);
	 */
	while (ptr->f_copy[ptr->i] != '\0')
	{
		if (ptr->f_copy[ptr->i] == '%')
		{
			ptr->len += next_parser(ptr);
		}
		else
		{
			// print beginning of format string
			ptr->len++;
		}
		ptr->i++;
	}
	return (ptr->len);
}