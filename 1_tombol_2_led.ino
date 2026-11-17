// Slamet Indriyanto
// DEMO 4: 1 tombol, 2 LED
// Tekan 1x = LED 1 nyala
// Tekan 2x = LED 2 ikut nyala (kedua LED nyala)
// Tekan 3x = kedua LED mati, lalu mengulang dari awal
// Tombol: pin 8 | LED 1: pin 9 | LED 2: pin 10

const int TOMBOL = 8;
const int LED1 = 9;
const int LED2 = 10;

int langkah = 0;                 // 0, 1, 2
bool tombolSebelumnya = HIGH;

bool tombolDitekan(int pin, bool &sebelumnya) {
  bool sekarang = digitalRead(pin);
  bool hasil = (sebelumnya == HIGH && sekarang == LOW);
  if (sekarang != sebelumnya) delay(20);
  sebelumnya = sekarang;
  return hasil;
}

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  if (tombolDitekan(TOMBOL, tombolSebelumnya)) {
    langkah = (langkah + 1) % 3;   // 0 -> 1 -> 2 -> 0 ...

    if (langkah == 0) {            // semua mati
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
    } else if (langkah == 1) {     // LED 1 nyala
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
    } else {                       // langkah 2: kedua LED nyala
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
    }
  }
}
