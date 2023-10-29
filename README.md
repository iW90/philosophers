# 42 Cursus - philosophers

<img src="https://game.42sp.org.br/static/assets/achievements/philosophersn.png" alt="completion-with-bonus-badge" align="left">

**Philosophers** é um programa desenvolvido em torno do famoso problema dos filósofos gastronômicos de _Edsger Dijkstra_, que se passa em uma mesa de jantar. O foco da parte mandatória é encontrar uma solução utilizando apenas threads e mutexes, e com isso aprendemos a gerenciar threads que estejam acontecendo simultaneamente. Já no bônus, deve ser desenvolvido um segundo programa, baseado em semáforos, onde lidaremos com processos simultâneos.


## O Jantar dos Filósofos <img src="https://img.shields.io/badge/GRADE-125%2F100-success?logo=42&logoColor=fff" align="right"/>

É um problema clássico da computação proposto por **Edsger W. Dijkstra** em 1965. Esse problema ilustra os desafios de concorrência e sincronização em sistemas multi-threading.

A situação hipotética é a seguinte: Existem cinco filósofos sentados em torno de uma mesa circular, e cada filósofo passa sua vida alternando entre pensar e comer. Um talher é colocado entre cada par de filósofos, e um filósofo precisa de dois talheres adjacentes para poder comer.

O problema é garantir que os filósofos possam comer de maneira segura, evitando _deadlock_ (impasse), _starvation_ (inanição) e garantindo que todos tenham uma chance justa de comer. Os principais desafios incluem:

  - Evitar deadlock: Se todos os filósofos pegarem um talher ao mesmo tempo, eles podem ficar bloqueados, esperando o segundo talher para sempre.
  - Evitar starvation: Garantir que cada filósofo tenha uma chance justa de pegar talheres e comer, em vez de alguns filósofos sempre comerem antes dos outros.

## Philosophers

Argumentos:

  - **number_of_philosophers**: O número de filósofos e também o número de garfos.
  - **time_to_die** (em milissegundos): Se um filósofo não iniciar a refeição dentro desse tempo desde o início da última refeição ou desde o início da simulação, ele morre.
  - **time_to_eat** (em milissegundos): O tempo que um filósofo leva para comer. Durante esse tempo, eles precisarão segurar dois garfos.
  - **time_to_sleep** (em milissegundos): O tempo que um filósofo passará dormindo.
  - **number_of_times_each_philosopher_must_eat** (argumento opcional): Se todos os filósofos tiverem comido pelo menos essa quantidade de vezes, a simulação para. Se não for especificado, a simulação para quando um filósofo morre.

### Regras do Mandatório

- Cada filósofo é uma thread;
- Há um garfo entre cada par de filósofos. Portanto, se houver vários filósofos, cada filósofo tem um garfo à sua esquerda e um garfo à sua direita. Se houver apenas um filósofo, deve haver apenas um garfo na mesa.
- Para evitar que os filósofos dupliquem garfos, você deve proteger o estado dos garfos com um **mutex** para cada um deles.

### Regras do Bônus (semáforo)

- Todos os garfos são colocados no centro da mesa.
- Eles não têm estados na memória, mas o número de garfos disponíveis é representado por um semáforo.
- Cada filósofo deve ser um processo (fork). No entanto, o processo principal não deve ser um filósofo.

## Compilação e Execução

#### Mandatório

Para compilar, entre na pasta `philo` e execute o comando:

```
make
```

#### Bônus

Entre na pasta `philo_bonus` e execute o comando:

```
make
```

### Execução

#### Mandatório

Basta executar o arquivo `philo` que foi gerado após a compilação e na frente colocar os valores referentes à:

- Quantidade de filósofos (de 1 a 200);
- Tempo máximo que ele aguenta ficar sem comer antes de morrer (em ms);
- Tempo que ele leva para comer (em ms);
- Tempo que ele leva para dormir (em ms);
- \[opcional] Quantidade de vezes que cada filósofo deve se alimentar antes de encerrar a simulação;

```
./philo 5 800 200 200 7
```

#### Bônus

Execute o arquivo `philo_bonus` que foi gerado após a compilação e na frente colocar os valores referentes à:

- Quantidade de filósofos (de 1 a 200);
- Tempo máximo que ele aguenta ficar sem comer antes de morrer (em ms);
- Tempo que ele leva para comer (em ms);
- Tempo que ele leva para dormir (em ms);
- \[opcional] Quantidade de vezes que cada filósofo deve se alimentar antes de encerrar a simulação;

```
./philo_bonus 5 800 200 200 7
```

## Visualização

\[soon]
