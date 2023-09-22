# Allowed Functions

- **stdio.h**
  - printf
- **stdlib.h**
  - malloc
  - free
- **string.h**
  - memset
- **unistd.h**
  - write
  - usleep
- **pthread.h**
  - pthread_create
  - pthread_detach
  - pthread_join
  - pthread_mutex_init
  - pthread_mutex_destroy
  - pthread_mutex_lock
  - pthread_mutex_unlock
- **sys/time.h**
  - gettimeofday

## **pthread_create**

`int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);`

  - pthread_t **\*thread**: endereço da thread;
  - const pthread_attr_t **\*attr**: (ponteiro opcional, nullable) configuração da thread;
  - void **\*(\*start_routine)(void \*)**: ponteiro para função executada assim que a thread for criada.
  - void **\*arg**: Argumento passado para a função start_routine quando a thread for criada.

