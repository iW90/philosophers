# Allowed Functions

- **pthread.h**
  - [pthread_create](#pthread_create)
  - [pthread_join](#pthread_join)
  - [pthread_detach](#pthread_detach)
  - pthread_mutex_init
  - pthread_mutex_destroy
  - pthread_mutex_lock
  - pthread_mutex_unlock
- **sys/time.h**
  - gettimeofday
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

## **pthread_create**

Inicia uma nova thread.

`int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);`

  - pthread_t **\*thread**: endereço da thread (necessário alocar);
  - const pthread_attr_t **\*attr**: (ponteiro opcional, nullable) configuração da thread;
  - void **\*(\*start_routine)(void \*)**: ponteiro para função executada assim que a thread for criada.
  - void **\*arg**: Argumento passado para a função acima quando a thread for criada.

Se a thread for criada com sucesso, retornará 0.

## **pthread_join**

Usada para aguardar que uma thread secundária termine sua execução antes que o programa principal continue.

> A função pthread_join bloqueia a execução da thread que a chama até que a thread especificada termine. Depois disso, a thread que chamou pthread_join continua sua execução.

`int pthread_join(pthread_t thread, void **retval);`

  - pthread_t **thread**: thread (não o endereço);
  - void **\*\*retval**: (ponteiro opcional, nullable) Onde o valor de retorno da thread será armazenado quando a thread terminar sua execução.

Se a thread for encerrada com sucesso, retornará 0.

## **pthread_detach**

Usada para indicar que uma thread secundária não precisa ser aguardada pelo programa principal para encerrar.

> Quando uma thread é "detachada", isso significa que, quando ela terminar sua execução, todos os recursos associados a ela (como memória) serão automaticamente liberados pelo sistema operacional.

`int pthread_detach(pthread_t thread);`

  - pthread_t **thread**: thread (não o endereço);

Se a thread for encerrada com sucesso, retornará 0.
