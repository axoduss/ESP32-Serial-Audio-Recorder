import serial
import wave
import struct
import sys

# CONFIGURAZIONE
SERIAL_PORT = 'COM3'  # Cambia con la tua porta (es. /dev/ttyUSB0 su Linux/Mac)
BAUD_RATE = 921600
OUTPUT_FILE = 'registrazione.wav'
SAMPLE_RATE = 24000   # Deve corrispondere a quello nell'Arduino
CHANNELS = 1
SAMPLE_WIDTH = 2      # 2 byte per 16-bit

def main():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print(f"Connessione aperta su {SERIAL_PORT}... Premi Ctrl+C per fermare.")
        
        frames = []

        while True:
            if ser.in_waiting > 0:
                data = ser.read(ser.in_waiting)
                frames.append(data)
                # Stampa un punto ogni tanto per mostrare che sta registrando
                if len(frames) % 100 == 0:
                    sys.stdout.write('.')
                    sys.stdout.flush()

    except KeyboardInterrupt:
        print("\n\nRegistrazione interrotta. Salvataggio file...")
        ser.close()
        
        # Scrivi il file WAV
        with wave.open(OUTPUT_FILE, 'wb') as wf:
            wf.setnchannels(CHANNELS)
            wf.setsampwidth(SAMPLE_WIDTH)
            wf.setframerate(SAMPLE_RATE)
            wf.writeframes(b''.join(frames))
        
        print(f"File salvato come: {OUTPUT_FILE}")

if __name__ == "__main__":
    main()