#include <DHT.h>               // Bibliothek für den DHT-Sensor (Temperatur & Luftfeuchtigkeit)
#include <LiquidCrystal.h>     // Bibliothek für das LCD-Display

// --- Pin-Definitionen ---
#define DHT_PIN 7              // Datenpin für den DHT11
#define DHT_TYPE DHT11         // Sensortyp: DHT11
#define LED 8                  // LED-Pin für Lichtanzeige
#define LDR_PIN A4             // Analoger Pin für LDR (Lichtsensor)


DHT dht(DHT_PIN, DHT_TYPE);    // DHT-Sensor initialisieren
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD-Display: RS=12, E=11, D4=5, D5=4, D6=3, D7=2

// --- Parameter ---
int limit = 30;                // Schwellenwert für LDR (Helligkeit)

void setup() {
    pinMode(LED, OUTPUT);      // LED-Pin als Ausgang definieren
    Serial.begin(9600);        // Serielle Kommunikation starten
    dht.begin();               // DHT-Sensor starten
    lcd.begin(16, 2);          // LCD-Display initialisieren (16 Zeichen, 2 Zeilen)

    
    lcd.print("mini wetter station");
    delay(1000);
    lcd.clear();               // Display nach 1 Sekunde löschen
}

void loop() {
    // --- Sensordaten lesen ---
    float temp = dht.readTemperature(); // Temperatur in °C
    float hum = dht.readHumidity();     // Luftfeuchtigkeit in %
    int ldr_wert = analogRead(LDR_PIN); // Helligkeit (0-1023)

    // Fehlerbehandlung für den DHT11
    if (isnan(temp) || isnan(hum)) { // wird ausgeführt wenn der gelesene Wert keine zahl ist
        Serial.println("Fehler beim Lesen des DHT11");
    }

    // --- Werte auf LCD anzeigen ---
    lcd.setCursor(0, 0);         // Erste Zeile
    lcd.print("T: ");
    lcd.print(temp);
    lcd.print((char)223);        // Grad-Symbol
    lcd.print("C ");
    lcd.print("H: ");
    lcd.print(hum);
    lcd.print("%");

    lcd.setCursor(0, 1);         // Zweite Zeile
    lcd.print("Light: ");
    lcd.print(ldr_wert);

    // --- Werte im Serial Monitor ausgeben ---
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" *C, Humiditaet: ");
    Serial.print(hum);
    Serial.print(" %, Licht: ");
    Serial.println(ldr_wert);

    delay(2000);                 // 2 Sekunden warten
    lcd.clear();                 // Display leeren für nächste Aktualisierung

    // --- LED-Steuerung abhängig von der Helligkeit ---
    if (ldr_wert < limit) {
        digitalWrite(LED, HIGH); // LED einschalten (wenn dunkel)
    } else {
        digitalWrite(LED, LOW);  // LED ausschalten (wenn hell)
    }
}