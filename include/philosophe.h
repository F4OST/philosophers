/*
** philosophe.h for philosophe in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/include/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 13 14:48:38 2017 Matthias Prost
** Last update	Tue Mar 14 22:56:47 2017 Cyril Puccio
*/

#ifndef _PHILOSOPHE_H_
#define _PHILOSOPHE_H_

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct			s_values
{
  int				nb_philo;
  int				rice;
}				t_values;

typedef struct			s_philo
{
  int				rice;
  int				state;
  int       id;
  struct s_philo		*hand;
  pthread_mutex_t		mutex;
  t_values			*val;
}				t_philo;

void *state_loop(void *arg);
void rest(t_philo *philo);

#endif
