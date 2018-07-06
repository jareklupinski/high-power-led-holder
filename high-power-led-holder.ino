#define OE_PIN 6
#define SDI_PIN 11
#define CLK_PIN 13
#define LE_PIN 7

void setup() {
  pinMode( OE_PIN, OUTPUT );
  pinMode( SDI_PIN, OUTPUT );
  pinMode( CLK_PIN, OUTPUT );
  pinMode( LE_PIN, OUTPUT );
  analogWrite( OE_PIN, 254 );
  digitalWrite( LE_PIN, LOW );
}

void loop() {
  for ( int i = 0; i < 256; i++ ) {
    shiftOut( SDI_PIN, CLK_PIN, MSBFIRST, i );
    shiftOut( SDI_PIN, CLK_PIN, MSBFIRST, i );
    shiftOut( SDI_PIN, CLK_PIN, MSBFIRST, i );
    digitalWrite( LE_PIN, HIGH );
    digitalWrite( LE_PIN, LOW );
    delay( 500 );
  }
}
