// definir porta de leitura do sensor de ldr
const int portaLDR = GPIO_NUM_26 ;
const float MAX_ADC_READING = 4095.0 ;
const float ADC_REF_VOLTAGE = 3.30 ;
const int REF_RESISTANCE = 10000;
const long LUX_CALC_SCALAR = 12518931 ;
const int LUX_CALC_EXPONENT = -1.405 ;

float leitura = 0;
float resistorVoltage = 0;
float ldrVoltage = 0;
float ldrResistance = 0;
float ldrLux = 0;

void setup() {
  // inicializar serial
  Serial.begin(115200);
  // definir porta do sensor ldr como entrada
  pinMode(portaLDR, INPUT);
}
 
void loop() {
  // realizar leitura do sensor ldr
  leitura = analogRead(portaLDR);
  resistorVoltage = leitura / MAX_ADC_READING * ADC_REF_VOLTAGE ;
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage ;
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE ;
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
  
  // Realizar o print da leitura no serial
  Serial.println("Leitura do Luximetro:");
  Serial.println(ldrLux);
  // realizar um delay e inicializar leitura daqui a 2 segundos
  delay(2000);
 
}
