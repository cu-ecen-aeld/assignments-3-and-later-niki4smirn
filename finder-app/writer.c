#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslog.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Incorrect number of arguments\n");
    return 1;
  }
  openlog(NULL, 0, LOG_USER);
  int fd = creat(argv[1], 0644);
  if (fd == -1) {
    syslog(LOG_ERR, "creat: %m\n");
    return 1;
  }
  int nr = write(fd, argv[2], strlen(argv[2]));
  if (nr == -1) {
    syslog(LOG_ERR, "write: %m\n");
    return 1;
  }
  syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
  if (close(fd) == -1) {
    syslog(LOG_ERR, "close: %m\n");
    perror("close");
  }
  return 0;
}
