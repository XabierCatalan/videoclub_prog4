/*
 * logger.c
 *
 *  Created on: 3 abr 2023
 *      Author: Usuario
 */
#include <stdio.h>
enum LogLevel { DEBUG, INFO, WARN, ERROR };

void log(enum LogLevel level, const char* message) {
  switch (level) {
    case DEBUG:
      printf("[DEBUG] %s\n", message);
      break;
    case INFO:
      printf("[INFO] %s\n", message);
      break;
    case WARN:
      printf("[WARN] %s\n", message);
      break;
    case ERROR:
      printf("[ERROR] %s\n", message);
      break;
  }
}
