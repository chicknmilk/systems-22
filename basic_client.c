#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while (1) {
    char *req = malloc(BUFFER_SIZE);

    printf("Enter a string: ");
    fgets(req, BUFFER_SIZE, stdin);
    sscanf(req, "%s", req);

    if (strcmp(req, "exit") == 0) {
      printf("Exiting...\n");
      break;
    }

    write(to_server, req, BUFFER_SIZE);

    char *res = malloc(BUFFER_SIZE);
    read(from_server, res, BUFFER_SIZE);

    printf("response: %s\n", res);

  }

  return 0;
}
