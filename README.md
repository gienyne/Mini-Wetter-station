🌦️ Mini Wetterstation (Arduino)

Ein einfaches Arduino-basiertes Mini-Wetterstations-Projekt, das folgende Größen misst:

🌡️ Temperatur (°C)

💧 Luftfeuchtigkeit (%)

💡 Lichtintensität (LDR-Wert)

Die Werte werden auf einem 16x2 LCD angezeigt.
Zusätzlich schaltet sich eine LED ein, wenn der Lichtwert unter einen definierten Grenzwert fällt – ähnlich wie bei Straßenlampen, die in der Nacht automatisch angehen.

🔧 Hardware-Komponenten

Arduino Mega 2560 (oder kompatibles Board)

DHT11-Sensor (Temperatur & Luftfeuchtigkeit)

LDR (Lichtabhängiger Widerstand)

10kΩ Widerstand (für LDR-Spannungsteiler)

10kΩ Potentiometer (für LCD-Kontrast)

16x2 LCD (Parallel-Interface)

1× LED (Statusanzeige)

Breadboard + Jumperkabel

⚡ Schaltplan (Übersicht)
DHT11:
  VCC → 5V
  GND → GND
  DATA → D7

LDR:
  Eine Seite → 5V
  Andere Seite → A4 + 10kΩ Widerstand → GND

LCD (16x2):
  Pin 1 (VSS)  → GND
  Pin 2 (VCC)  → 5V
  Pin 3 (V0)   → Mittlerer Pin Potentiometer (Kontrast)
  Pin 4 (RS)   → D12
  Pin 5 (RW)   → GND
  Pin 6 (E)    → D11
  Pin 11 (D4)  → D5
  Pin 12 (D5)  → D4
  Pin 13 (D6)  → D3
  Pin 14 (D7)  → D2
  Pin 15 (LED+) → 5V
  Pin 16 (LED-) → GND

LED-Indikator:
  Anode (+) → D8
  Kathode (-) → GND

🖥️ Software

Arduino IDE

Notwendige Libraries:

DHT-Sensor-Library

Adafruit Unified Sensor

Eingebaute LiquidCrystal-Bibliothek

Installation der Libraries über den Arduino Library Manager.

🚀 Verwendung

Repository klonen oder herunterladen.

Sketch in der Arduino IDE öffnen.

Auf den Arduino Mega hochladen (oder Uno, ggf. Pins anpassen).

Serial Monitor öffnen (9600 baud), um Live-Werte zu sehen.

LCD zeigt Temperatur, Luftfeuchtigkeit und Lichtstärke.

LED schaltet sich ein, wenn der Lichtwert unter dem Grenzwert (limit = 30) liegt.

🚀 Funktionsweise des Codes

Initialisierung

DHT11 und LCD werden gestartet.

LED-Pin wird als Ausgang definiert.

LCD zeigt beim Start „mini wetter station“ an.

Sensorwerte erfassen

Temperatur und Luftfeuchtigkeit werden mit dht.readTemperature() und dht.readHumidity() gemessen.

Lichtintensität wird mit analogRead(A4) erfasst.

Ungültige Messwerte (NaN) führen zu einer Fehlermeldung im Serial Monitor.

Anzeige auf LCD

Erste Zeile: Temperatur und Luftfeuchtigkeit

Zweite Zeile: Lichtwert

Ausgabe im Serial Monitor

Alle Werte werden zusätzlich seriell ausgegeben.

LED-Steuerung

Wenn der Lichtwert < limit → LED an.

Sonst → LED aus.

Zyklus

Messung alle 2 Sekunden (delay(2000)).

📸 Demo

![Schaltplan](images/Schaltplan.jpg)

![Ausgabe vom Serial Monitor](images/serial_monitor.jpg)

![Licht an](images/aufbau_an.jpg)

![Licht aus](images/aufbau_aus.jpg)


⚙️ Zukünftige Erweiterungen

Datenspeicherung mit SD-Kartenmodul

Echtzeituhr (RTC) für Zeitstempel

Upgrade auf DHT22 (höhere Genauigkeit)

ESP32 + WLAN-Dashboard

👤 Autor

Entwickelt von Dimitry Ntofeu Nyatcha
