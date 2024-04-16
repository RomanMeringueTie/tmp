#pragma once
#include <fcntl.h>
#include <mySimpleComputer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

enum keys
{
  up,
  down,
  right,
  left,
  l,
  r,
  s,
  t,
  i,
  esc,
  enter,
  f5,
  f6
};

int rk_readkey (enum keys *);

int rk_mytermsave (void);

int rk_mytermrestore (void);

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);

int rk_readvalue (int *value, int timeout);