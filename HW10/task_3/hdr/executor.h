#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

int commandInterpreter();

#endif
