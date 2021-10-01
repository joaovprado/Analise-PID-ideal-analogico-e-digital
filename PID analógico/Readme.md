Nesta pasta está contemplado o modelo de PID analógico. 
Para sua confecção foram utilizados Amplificadores Operacionais em quatro prinicpai configurações: 
 - Somador, para somar os termos PID do controlador;
 - Subtrator, para achar o erro entre o setpoint e a saída da planta;
 - Diferencial, para calcular o termo D do contorlador;
 - Integrador, para calcular o termo I do contorlador;
 - Proporcional, para calcular o termo P do contorlador.
 
 
A topologia escolhida foi do PID paralelo, obtendo dessa forma o circuito abaixo:
![Circuito PID analógico](https://user-images.githubusercontent.com/48776982/135686624-17e24a10-16bc-4c97-be63-89f53cbcc14c.png)

O gráfico com as curvas de entrada, saída com PID e sem PID, pode ser visto logo abaixo:
![Gráfico do PID analógico](https://user-images.githubusercontent.com/48776982/135686683-c9794e09-1d52-4ac8-84ea-fbb267ee7154.png)
