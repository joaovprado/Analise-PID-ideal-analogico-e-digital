// Sensor de tensão: A0
// Prog : Ard : Real
// 0    : 0V  : -50V
// 1024 : 5V  :  50V

// Setpoint tensão: A1
// 0    : 0V
// 1024 : 5V

// Saída PWM Controlador (Entrada da planta) 
//    erro = 0 -> saida = 0
//    erro < 0 -> saida = 0:255 no port 5 (-50V)
//    erro > 0 -> saida = 0:255 no port 3 (+50V)

void setup() {
    pinMode(A1, INPUT);  //pino de setpoint
    pinMode(A0, INPUT);  //sensor de tensão
    pinMode( 5, OUTPUT); //saída tensão positiva
    pinMode( 3, OUTPUT); //saída tensão negativa
}

float P  = 0.0;
float I  = 0.0;
float D  = 0.0;
float PID = 0.0;
float erro = 0.0;
float sensorAnterior = 0.0;
float sensor = 0.0;
float setpoint = 0.0;
float erroAnterior = 0.0;

float kp = 5.0;
float ki = 1.0;
float kd = 0.1;

void loop() {
    
////////////// Leitura sensores //////////////
    sensorAnterior = sensor;
    erroAnterior = erro;
    sensor   = analogRead(A0)*100.0/1024-47.37;
    setpoint = analogRead(A1)*5.0/1024;
    erro     = setpoint - sensor;
    

////////////// Cálculo PID //////////////
    P   = kp * erro;                       //parcela proporcional
    I  += ki * erro;                       //parcela integral
    D   = kd * (sensor - sensorAnterior);  //parcela derivativa
    
    PID = abs(P + I + D); //Calcula PID sem sinal
    if (PID > 255) PID = 255; //Corrige a saturação da variável PWM 
    
    //Se a variação do erro for grande, reseta o termo integral
    if(abs(erro - erroAnterior) > 1) I = 0; 
    
////////////// Saída do controlador //////////////  
    
    if (erro < -0.1){
      analogWrite(5, PID);
      analogWrite(3, 0);
    }
    else if (erro > 0.1){
      analogWrite(3, PID);
      analogWrite(5, 0);
    }
    else{
      analogWrite(3, 0);
      analogWrite(5, 0);
    }
}
