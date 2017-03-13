/*
** main.c for philosophes in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 13 14:43:28 2017 Matthias Prost
** Last update Mon Mar 13 16:03:07 2017 Matthias Prost
*/

#include "extern.h"
#include "philosophe.h"

int	main(int ac, char **av)
{
  int			i;
  t_philo	value;

  i = 0;
  while (av[++i])
    {
      if (strcmp(av[i], "-p") == 0)
	value.nb_philo = atoi(av[i++]);
      else if (strcmp(av[i], "-e") == 0)
	value.rice = atoi(av[i++]);
    }
  return(0);
}
