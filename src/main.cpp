#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando");
  delay(500);
  Serial.println("Procurando redes...");
  int qtde_redes = WiFi.scanNetworks();
  Serial.println("Redes encontradas:");
  for (int i = 0; i < qtde_redes; i++) {
    Serial.print("Nome da Rede............: ");
    Serial.println(WiFi.SSID(i));
    Serial.print("Potência do Sinal (dBm).: ");
    Serial.println(WiFi.RSSI(i));
    Serial.print("Tipo de Criptografia.....:");
    String cripto;
    switch(WiFi.encryptionType(i)) {
      case 2: cripto = "TKIP (WPA)"; break;
      case 4: cripto = "CCMP (WPA)"; break;
      case 5: cripto = "WEP"; break;
      case 7: cripto = "Nenhuma"; break;
      case 8: cripto = "AUTO"; break;
    }
    Serial.println(cripto);
    Serial.println("-----------------------------");
  }
}
void loop() {
}