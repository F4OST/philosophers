/*
** thread.c for PSU_2016_philo
**
** Made by	Cyril Puccio
** Login	cyril.puccio@epitech.eu
**
** Started on	Tue Mar 14 15:43:59 2017 Cyril Puccio
** Last update	Tue Mar 14 18:09:07 2017 Cyril Puccio
*/

#include "extern.h"
#include "philosophe.h"

void            eat(t_philo *philo)
{
  pthread_mutex_lock(&philo->mutex);
  pthread_mutex_lock(&philo->hand->mutex);
  printf("Le philosophe mange - ");
  philo->rice--;
  printf("stick %d\n", philo->stick);
  pthread_mutex_unlock(&philo->mutex);
  pthread_mutex_unlock(&philo->hand->mutex);
}

void      *state_loop(void *arg)
{
  t_philo	*philo;

  philo = (t_philo*)arg;
  while (philo->rice > 0)
  {
    printf("%d\n", philo->rice);
    if (philo->stick == 2)
      eat(philo);
/*    else if (philo->stick == 1)
      think(philo);
    if (philo->stick == 0)
      rest(philo); */
    sleep(1);
  }
  return (NULL);
}
