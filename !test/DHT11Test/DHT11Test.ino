#  
#include "DHT.h"

#define DHT11_PIN   (33)

DHT dht(DHT11_PIN, DHT11);  // 温湿度センサーのインスタンス

void setup() 
{
    Serial.begin(115200);
    while (!Serial) ;

    // DHT11初期化
    dht.begin();
}

void loop() 
{
    float  humid = dht.readHumidity(); // 湿度[%]
    float  temp = dht.readTemperature(); // 気温[摂氏]
    Serial.printf("temp: %.1f, humid: %.1f\r\n", temp, humid);

    delay(3 * 1000); // 3秒おきに計測・表示
}