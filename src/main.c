/*
** main.c for philosophes in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 13 14:43:28 2017 Matthias Prost
** Last update	Wed Mar 15 16:26:51 2017 Cyril Puccio
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

int		init_thread(t_philo *philo)
{
  pthread_t	threads[philo->val->nb_philo];
  int		i;

  (void)threads;
  i = -1;
  while (++i != philo->val->nb_philo)
    {
      if (pthread_create(&threads[i], NULL, &state_loop, &philo[i]))
      	{
      	  fprintf(stderr, "Thread creation failed\n");
      	  return (-1);
      	}
    }
  i = -1;
  while (++i != philo->val->nb_philo)
    pthread_join(threads[i], NULL);
  return (0);
}

int		fill_tab(t_values *values)
{
  t_philo	*philo;
  int		i;

  i = -1;
  if ((philo = malloc(sizeof(t_philo) * values->nb_philo)) == NULL)
    return (-1);
  philo->val = values;
  while (++i != values->nb_philo)
    {
      philo[i].id = i;
      if (rand() % 2 == 0)
        philo[i].state = 0;
      else 
        philo[i].state = 2;
      philo[i].rice = values->rice;
      philo[i].hand = &philo[i + 1];
      philo[i].mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    }
  philo[values->nb_philo - 1].hand = &philo[0];
  return (init_thread(philo));
}

int		main(int ac, char **av)
{
  int	       	i;
  t_values	value;

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
  RCFStartup(ac, av);
  if (fill_tab(&value) == -1)
  {
    RCFCleanup();
    return (0);
  }
  RCFCleanup();
  return(0);
}
