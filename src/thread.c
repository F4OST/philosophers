/*
** thread.c for PSU_2016_philo
**
** Made by	Cyril Puccio
** Login	cyril.puccio@epitech.eu
**
** Started on	Tue Mar 14 15:43:59 2017 Cyril Puccio
** Last update	Tue Mar 14 19:36:59 2017 Cyril Puccio
*/

#include "extern.h"
#include "philosophe.h"

void            eat(t_philo *philo)
{
  philo->hand->stick += 1;
  while (pthread_mutex_trylock(&philo->mutex) == 0);
  while (pthread_mutex_trylock(&philo->hand->mutex) == 0);
  printf("Le philosophe %d mange, stick : %d\n", philo->id, philo->stick);
  philo->rice--;
  philo->state = 1;
  philo->stick -= 1;
  philo->hand->stick += 1;
  pthread_mutex_unlock(&philo->mutex);
  pthread_mutex_unlock(&philo->hand->mutex);
}

void            think(t_philo *philo)
{
  while (pthread_mutex_trylock(&philo->mutex) == 0);
  while (pthread_mutex_trylock(&philo->hand->mutex) == 0);
  printf("Le philosophe %d pense, stick : %d\n", philo->id, philo->stick);
  philo->state = 0;
  if (philo->hand->stick >= 1 && philo->hand->state != 0)
    {
      philo->stick += 1;
      philo->hand->stick -= 1;
    }
  pthread_mutex_unlock(&philo->mutex);
  pthread_mutex_unlock(&philo->hand->mutex);
}

void            rest(t_philo *philo)
{
  while (pthread_mutex_trylock(&philo->mutex) == 0);
  while (pthread_mutex_trylock(&philo->hand->mutex) == 0);
  printf("Le philosophe %d dors, stick : %d\n", philo->id, philo->stick);
  philo->state = 2;
  if (philo->hand->stick >= 1 && philo->hand->state != 0)
    {
      philo->stick += 1;
      philo->hand->stick -= 1;
    }
  pthread_mutex_unlock(&philo->mutex);
  pthread_mutex_unlock(&philo->hand->mutex);
}

void      *state_loop(void *arg)
{
  t_philo	philo;

  philo = *(t_philo*)arg;
  while (philo.rice > 0)
  {
    if (philo.stick == 2)
      eat(&philo);
    else if (philo.stick == 1)
      think(&philo);
    else
      rest(&philo);
    sleep(1);
    printf("---\n");
  }
  return (NULL);
}
