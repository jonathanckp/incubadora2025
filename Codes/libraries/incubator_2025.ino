#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>      //Librerias del sensor DHT11
#include <DHT_U.h>    //*

#define PIN_DHT  35          //Pin del esp32 utilizado para la transmision de datos
#define DHTTYPE    DHT11    //Declaracion del tipo de sensor, DHT11 o DHT22

// Dirección I2C común: 0x27 o 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección, columnas, filas

float temperatura;
float humedad;

DHT dht(PIN_DHT, DHTTYPE);   //Creacion del objeto dht
 
void setup(){
  Serial.begin(9600);
  dht.begin();           //inicializacion del sensor DHT11
  lcd.begin();       // Inicializa la pantalla
  lcd.backlight();   // Enciende la luz de fondo
  lcd.print("Hola Mundo!");
}
void Dht(){
  temperatura = dht.readTemperature();  //Funcion medidora de temperatura
  humedad = dht.readHumidity();         //Funcion medidora de humedad
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" Humedad: ");
  Serial.println(humedad);
  delay(1000);
}
void loop(){
 Dht();
}