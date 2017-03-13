/*
** main.c for philosophes in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 13 14:43:28 2017 Matthias Prost
** Last update Mon Mar 13 14:50:32 2017 Matthias Prost
*/

#include "extern.h"
#include "philosophe.h"

int	main(int ac, char **av)
{
  printf("%d\n", RCFStartup(ac, av));
  return(0);
}
