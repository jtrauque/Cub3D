#include "cub3d.h"

void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int   ft_space(char *elements)
{
  int i;

  i = 0;
  while (elements[i])
  {
    if (elements[i] == ' ')
      i++;
    else 
      return (i);
  }
  return (-1); 
}

void  ft_error(char *str)
{
  ft_putstr("Error\n");
  ft_putstr(str);
  exit(1); 
}

void  ft_error_map(char *str, t_pars *pars)
{
  int i;

  i = 0;
  ft_putstr("Error\n");
  ft_putstr(str);
  while (pars->map[i]) 
  {
    free(pars->map[i]);
    i++;
  }
  exit(1); 
}

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putnbr(int n)
{
  unsigned long nb;
  nb = n;
  if (n < 0)
  {
    ft_putchar('-');
    nb = -nb;
  }
  if (nb > 9)
  {
    ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
  }
  else 
    ft_putchar(nb + '0');
}
