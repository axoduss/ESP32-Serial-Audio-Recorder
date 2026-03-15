# 🎙️ ESP32 Audio Recorder via Seriale (INMP441)

Progetto per registrare audio da microfono **INMP441** utilizzando **ESP32** e salvare i campioni sul PC tramite porta seriale. I dati vengono catturati da uno script Python e convertiti in file `.wav` riproducibile.

---

## 📁 Struttura del Progetto

```text
.
├── Arduino/              # Codice sorgente per ESP32 (.ino)
├── MyPC/                 # Script Python per catturare l'audio (record_audio.py)
├── AudioSample/          # Esempio di registrazione (.wav)
└── README.md             # Questo file