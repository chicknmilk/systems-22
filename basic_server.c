#include "pipe_networking.h"

int toupper(int c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}

int main() {

  int to_client;
  int from_client;

  while (1) {
    from_client = server_setup();

    char * res = calloc(BUFFER_SIZE, sizeof(char));
    int f = fork();

    if (!f) {
      to_client = server_connect(from_client);

      while (read(from_client, res, BUFFER_SIZE)) {
        int i = 0;

        while (res[i]) {
          res[i] = toupper(res[i]);
          i++;
        }

        write(to_client, res, BUFFER_SIZE);
      }
    }

  }
  
}
