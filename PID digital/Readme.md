O controlador PID digital é o mais versátil e fácil de ser modiifcado, visto que o contorle dele se baseia em um código do microcontrolador.

Por facilidade de simulação, o microcontrolador escolhido foi da ATMEGA, na forma da placa de desenvolvimento Arduino Nano.

O primiero passo aqui é realizar a projeção de um sensor de tensão que converta -50V -> 50V em 0V -> 5V. 
O motivo disso é que essa é a tensão de entrada aceita pelo pino analógico do Arduino Nano.

Dessa forma foram utilizados amplificadores operacionais nas configurações de:
  - Buffer, para isolar o sina de entrada do resto do circuito do sensor;
  - Somador, para somar 50V ao sinal de entrada e transformando e mudando o range do sinal para 0V até 100V;
  - Inversor, para corrigi o sinal de saída do amplificador somador;
 
Após esses três estágios, foi aplicado um divisor de tensão com a proporção 1:20, fazendo com que o range do sinal de saída fosse 0V até 5V.

O circuito do sensor ficou dessa forma:

![Circuito do sensor de tensão (-50V to 50V para 0V to 5V)](https://user-images.githubusercontent.com/48776982/135687640-11f5c8f8-242d-4a6c-ae05-2e6be08892d5.png)

O software de simulação utiolizado foi o Proteus, então dessa forma foi possível encapsular o circuito o sensor, para que ele ficasse com uma aparência mais amigável, dessa forma ele ficou assim:

![image](https://user-images.githubusercontent.com/48776982/135687751-bf3e58bb-e41d-481f-ad16-c6e63c78cdee.png)


O restante do circuito foi bem básico, pois a pare crucial está dentro do próprio microcontrolador.
Na saída foram utilizados optoacopladores, pois eles podem ser contorlados direto pelo sinal PWM do arduino e fornecer tensões e correntes bem acima da tensão fornecida pelos pinos digitais do Arduino.
Foram usados dois optoacopladores, de tal forma que um controla uma tnesão de -50V e o outro controla uma tensão 50V.

O circuito ficou assim:
![Circuito PID digital](https://user-images.githubusercontent.com/48776982/135688029-48ff92cc-a5ad-4871-add8-1e2c5844d19a.png)

O gráfico de saída do sistema, com as cirvas de entrada, saída com PID e saída sem PID, ficou assim:
![Gráfico do PID digital](https://user-images.githubusercontent.com/48776982/135688072-9344a5cc-0376-45bf-ae65-ff6361d59ef5.png)

Obs.: Nesse circuito forma simuladas dua stensões de entrada em degrau, primeiro +5V e depois 0V. Para observar se o controlador reaponde adequadamente tanto para acréscimo de tensão, como para decréscimo.
