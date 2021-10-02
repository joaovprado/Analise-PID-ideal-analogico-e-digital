O circuito da planta a ser controlador foi pensado de tal forma que fosse possível obter uma saída oscilante no momento inicial.
Salientando, porém, que o controlador aqui projeto pode ser utilizado no controle de qualquer outro sistema, desde que sejam feitos os ajustes necessários.

O circuito do sistema ser controlado foi obtido por um resistor, um indutor e um capacitor, todos em série. A entrada é um sinal contínuo e a saída é a tensão sobre o capacitor.

Ilustrando, teremos o circuito abaixo:

![Circuito Planta](https://user-images.githubusercontent.com/48776982/135686956-96458b37-6bcd-43f4-862b-aef744f48896.png)


Com o programa em Python e em diagrama de blocos, conseguimos prever qual a saída ideal para esse circuito mostrado com degrau unitário na entrada. O gráfico obtido foi esse:
![gráfico](https://user-images.githubusercontent.com/48776982/135700836-b2cde048-cf9e-49ba-b8d7-696b054bd1b9.png)

Pode-se notar que a curva que está na cor preta é bem difícil de se notar, pois está bem próxima do degrau, tendo uma acomodação muito rápida.
Esse modelo é praticamente perfeito, dificilmente será alcançado pelos modelos mais próximos do real. Mas servirá de base para a comparação.
