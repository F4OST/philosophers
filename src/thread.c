/*
** thread.c for PSU_2016_philo
**
** Made by	Cyril Puccio
** Login	cyril.puccio@epitech.eu
**
** Started on	Tue Mar 14 15:43:59 2017 Cyril Puccio
** Last update	Tue Mar 14 16:12:01 2017 Cyril Puccio
*/

#include "extern.h"
#include "philosophe.h"

void *state_loop(void *arg)
{
  (void) arg;
  while (1)
  {
    printf("%s\n", "lel");
    sleep(1);
  }
  return (NULL);
}
