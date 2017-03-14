/*
** thread.c for PSU_2016_philo
**
** Made by	Cyril Puccio
** Login	cyril.puccio@epitech.eu
**
** Started on	Tue Mar 14 15:43:59 2017 Cyril Puccio
** Last update	Tue Mar 14 23:00:17 2017 Cyril Puccio
*/

#include "extern.h"
#include "philosophe.h"

void            eat(t_philo *philo)
{
  printf("Le philosophe %d mange\n", philo->id);
  philo->rice--;
  philo->state = 1;
  usleep(100);
  lphilo_eat();
  pthread_mutex_unlock(&philo->mutex);
  pthread_mutex_unlock(&philo->hand->mutex);
  rest(philo);
}

void            think(t_philo *philo, int a)
{
  printf("Le philosophe %d pense\n", philo->id);
  philo->state = 0;
  lphilo_think();
  if (a == 0)
    pthread_mutex_unlock(&philo->mutex);
  else
    pthread_mutex_unlock(&philo->hand->mutex);
}

void            rest(t_philo *philo)
{
  lphilo_sleep();
  printf("Le philosophe %d dors\n", philo->id);
  philo->state = 2;
}

void      *state_loop(void *arg)
{
  t_philo	*philo;

  philo = (t_philo*)arg;
/*  printf("%p %p\n", philo, philo->hand); */
  while (philo->rice > 0)
  {
    int a = pthread_mutex_trylock(&philo->mutex);
    int b = pthread_mutex_trylock(&philo->hand->mutex);
    if (a == 0 && b == 0)
      eat(philo);
    else if (a == 0 || b == 0)
      think(philo, a);
    else
      rest(philo);
/*    sleep(1); */
    printf("----\n");
  }
  return (NULL);
}
