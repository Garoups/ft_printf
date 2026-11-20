#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		ft_ret;
	int		orig_ret;
	int		num;
	char	*str;

	num = -42;
	str = "Hello, 42!";
	
	printf("========== FT_PRINTF TESTER ==========\n\n");

	/* %c */
	printf("--- %%c ---\n");
	orig_ret = printf("Original: [%c]\n", 'A');
	ft_ret = ft_printf("FT:       [%c]\n", 'A');
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %a */
	printf("--- %%s ---\n");
	orig_ret = printf("Original: [%s]\n", str);
	ft_ret = ft_printf("FT:       [%s]\n", str);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %p */
	printf("--- %%p ---\n");
	orig_ret = printf("Original: [%p]\n", str);
	ft_ret = ft_printf("FT:       [%p]\n", str);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %d */
	printf("--- %%d ---\n");
	orig_ret = printf("Original: [%d]\n", num);
	ft_ret = ft_printf("FT:       [%d]\n", num);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %i */
	printf("--- %%i ---\n");
	orig_ret = printf("Original: [%i]\n", INT_MIN);
	ft_ret = ft_printf("FT:       [%i]\n", INT_MIN);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %u */
	printf("--- %%u ---\n");
	orig_ret = printf("Original: [%u]\n", UINT_MAX);
	ft_ret = ft_printf("FT:       [%u]\n", UINT_MAX);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %x */
	printf("--- %%x ---\n");
	orig_ret = printf("Original: [%x]\n", 255);
	ft_ret = ft_printf("FT:       [%x]\n", 255);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %X */
	printf("--- %%X ---\n");
	orig_ret = printf("Original: [%X]\n", 255);
	ft_ret = ft_printf("FT:       [%X]\n", 255);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* %% */
	printf("--- %%%% ---\n");
	orig_ret = printf("Original: [%%]\n");
	ft_ret = ft_printf("FT:       [%%]\n");
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* Multiple conversions */
	printf("--- MULTIPLE CONVERSIONS ---\n");
	orig_ret = printf("Original: %s | %d | %x | %c | %%\n",
		"42", -42, 42, 'A');
	ft_ret = ft_printf("FT:       %s | %d | %x | %c | %%\n",
		"42", -42, 42, 'A');
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	/* NULL string */
	printf("--- NULL STRING ---\n");
	orig_ret = printf("Original: [%s]\n", (char *)NULL);
	ft_ret = ft_printf("FT:       [%s]\n", (char *)NULL);
	printf("Return: original=%d | ft=%d\n\n", orig_ret, ft_ret);

	return (0);
}