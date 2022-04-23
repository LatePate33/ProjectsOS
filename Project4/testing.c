#include "fcntl.h"
#include "types.h"
#include "user.h"

int main() {
  int count = getreadcount();
  printf(1, "%d\n", count);
  int fd = open("README", O_RDONLY);
  char buf[200];
  read(fd, buf, 1);
  count = getreadcount();
  printf(1, "%d\n", count);
  close(fd);
  exit();
}
