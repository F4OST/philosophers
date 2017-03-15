/*
** my_str_is_num.c for philosophe in /home/prost_m/Rendu/Semestre_4/PSU_2016_philo/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 15 20:09:54 2017 Matthias Prost
** Last update Wed Mar 15 20:50:24 2017 Matthias Prost
*/

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
