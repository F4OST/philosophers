/*
** main.c for philosophes in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 13 14:43:28 2017 Matthias Prost
** Last update Mon Mar 13 17:50:59 2017 Cyril
*/

#include "extern.h"
#include "philosophe.h"

int	my_str_is_num(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] > '9' || str[i] < '0')
      return(-1);
  return (atoi(str));
}

int	main(int ac, char **av)
{
  int			i;
  t_philo	value;

  i = 0;
  if (ac != 5)
    return (fprintf(stderr, "USAGE: ./philo -p [nbr] -e [nbr]\n"));
  while (++i != ac)
    {
      if (strcmp(av[i], "-p") == 0)
	{
	  if ((value.nb_philo = my_str_is_num(av[++i])) == -1)
	    return (fprintf(stderr, "Error: argument -p is invalid\n"));
	}
      else if (strcmp(av[i], "-e") == 0)
	{
	  if ((value.rice = my_str_is_num(av[++i])) == -1)
	    return (fprintf(stderr, "Error: argument -e is invalid\n"));
	}
      else
	return (fprintf(stderr, "USAGE: ./philo -p [nbr] -e [nbr]\n"));
    }
  return(0);
}
