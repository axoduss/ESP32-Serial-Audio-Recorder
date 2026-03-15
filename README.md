# 🎙️ ESP32 Audio Recorder via Seriale (INMP441)

Progetto per registrare audio da microfono **INMP441** utilizzando **ESP32** e salvare i campioni sul PC tramite porta seriale. I dati vengono catturati da uno script Python e convertiti in file `.wav` riproducibile.

---


## 📁 Struttura del Progetto



## 🔧 Hardware Requirements

|      Component     | Quantity |                      Notes                      |
|------------------|:--------:|-----------------------------------------------|
| ESP32-S3 Dev Board | 1x       | Any ESP32-S3 variant (e.g., ESP32-S3-DevKitC-1) |
| INMP441 Microphone | 1x       | I2S omnidirectional MEMS microphone             |
| Jumper Wires       | 5x       | For connecting microphone to ESP32              |
| USB Cable          | 1x       | For programming and power                       |

## 🔌 Wiring Diagram

|      INMP441     | ESP32		 |
|------------------|:-------------:|
| VDD 				| 3.3V       | 
| GND				| GND       |
| WS      			| GPIO       | 
| SCK          		| GPIO       | 
| SD 				| GPIO
| L/R 				| GND		|




## 💻 Software Requirements
On ESP32-S3
- Arduino IDE 2.x
- ESP32 Arduino Core 3.x (by Espressif)

On PC/Server
- Python 3.8+
- Dependencies: 
> pip install pyserial

or

> py -m pip install pyserial


## 🚀 Installazione e Configurazione

1. Arduino IDE
Apri il file .ino nella cartella Arduino/
Modifica i pin I2S se necessario (vedi sezione collegamenti)
Imposta il baud rate (consigliato: 2000000 per qualità migliore)
Carica il codice sull'ESP32
2. Script Python
Apri il file MyPC/record_audio.py
Modifica la porta seriale in base al tuo sistema:
python

SERIAL_PORT = 'COM3'  # Windows (controlla in Gestione Dispositivi)
# SERIAL_PORT = '/dev/ttyUSB0'  # Linux/Mac


Assicurati che BAUD_RATE e SAMPLE_RATE corrispondano al codice Arduino



## ▶️ Come Usare

Chiudi Arduino IDE o il Monitor Seriale (la porta COM deve essere libera)
Collega l'ESP32 al PC
Apri il terminale nella cartella MyPC/
Esegui lo script:

python record_audio.py

Parla nel microfono (vedrai dei puntini ... mentre registra)
Premi Ctrl+C per fermare la registrazione
Il file registrazione.wav verrà salvato nella stessa cartella
Apri il file con un lettore audio (VLC, Windows Media Player, ecc.)


## 🤝 Contributi

Contributi sono benvenuti! Se trovi bug o hai suggerimenti per migliorare la qualità audio, apri una Issue o invia una Pull Request.

Buona registrazione! 🎵