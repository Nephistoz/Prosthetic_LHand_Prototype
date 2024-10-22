#include <Servo.h>

Servo pulgar;
Servo indice;
Servo medio;
Servo anular;
Servo menique;  // Crear un objeto servo

int Angle = 90; // Posición inicial del servo
int n=0;

void setup() {
  // Iniciar el monitor serie
  Serial.begin(9600);

  pulgar.attach(11);  // Adjuntar el servo al pin PWM 11
  indice.attach(10);
  medio.attach(9);
  anular.attach(6);
  menique.attach(5);

  // Posición inicial en grados
  pulgar.write(150);
  indice.write(Angle);
  medio.write(Angle);
  anular.write(Angle);
  menique.write(Angle);

  delay(500);
  Serial.println("Seleccione una funcion:");
  Serial.println("1: Tomar Cepillo");
  Serial.println("2: Tomar Objeto Redondo");
  Serial.println("3: Abrir la mano");
  Serial.println("4: Saludar");
  Serial.println("5: Despedirse");
}


void loop() {
  // Esperar a que haya datos disponibles en el monitor serie
  if (Serial.available()) {
    // Leer la opción del usuario
    char opcion = Serial.read();

    // Llamar a la función correspondiente
    switch (opcion) {
      case '1':
        if(n==0){
          Brush();
          n++;
          }else if(n==1){
            Serial.println("Error...Reiniciando");
            Open();
            n=0;
            }
        break;
      case '2':
        if(n==0){
          Object();
          n++;
          }else if(n==1){
            Serial.println("Error...Reiniciando");
            Open1();
            n=0;
            }
        break;
      case '3':
        if(n==1){
          Open();
          n=0;
          }
        break;
      case '4':
        if(n==0){
          Hi();
          n++;
          }else if(n==1){
            Serial.println("Error...Reiniciando");
            Open2();
            n=0;
            }
        break;
      case '5':
        if(n==0){
          Bye();
          n++;
          }else if(n==1){
            Serial.println("Error...Reiniciando");
            Open3();
            n=0;
            }
        break;
      default:
        Serial.println("Opcion invalida. Por favor, seleccione 1, 2, 3, 4 o 5.");
        break;
    }

    // Pedir de nuevo la opción después de ejecutar una función
    Serial.println("Seleccione una funcion:");
    Serial.println("1: Tomar cepillo");
    Serial.println("2: Tomar Objeto Redondo");
    Serial.println("3: Abrir la mano");
    Serial.println("4: Saludar");
    Serial.println("5: Despedirse");
  }
}

// Función para tomar cepillo
void Brush() {
  Serial.println("Tomando Cepillo");
  pulgar.write(80);
  Angle=180;
  indice.write(Angle);
  delay(120);
  medio.write(Angle);
  delay(120);
  anular.write(Angle);
  delay(120);
  menique.write(Angle);
  delay(120);
  Angle=90;
  indice.write(Angle);
  delay(120);
  medio.write(Angle);
  delay(127);
  anular.write(Angle);
  delay(120);
  menique.write(Angle);
  delay(1500);
}

// Función para abrir la mano
void Open() {
  Serial.println("Abriendo");
  pulgar.write(150);
  Angle = 0;
  indice.write(Angle);
  delay(100);
  medio.write(Angle);
  delay(100);
  anular.write(Angle);
  delay(100);
  menique.write(Angle);
  delay(100);
  Angle=90;
  indice.write(Angle);
  delay(100);
  medio.write(Angle);
  delay(100);
  anular.write(Angle);
  delay(100);
  menique.write(Angle);
  delay(1500);
}

// Función para tomar objeto redondo
void Object() {
  Serial.println("Tomando Objeto Redondo");
  pulgar.write(60);
  Angle=180;
  indice.write(Angle);
  delay(60);
  medio.write(Angle);
  delay(60);
  anular.write(Angle);
  delay(60);
  menique.write(Angle);
  delay(60);
  Angle=90;
  indice.write(Angle);
  delay(60);
  medio.write(Angle);
  delay(60);
  anular.write(Angle);
  delay(60);
  menique.write(Angle);
  delay(1500);
}

void Open1() {
  Serial.println("Abriendo");
  pulgar.write(150);
  Angle = 0;
  indice.write(Angle);
  delay(36);
  medio.write(Angle);
  delay(36);
  anular.write(Angle);
  delay(36);
  menique.write(Angle);
  delay(36);
  Angle=90;
  indice.write(Angle);
  delay(36);
  medio.write(Angle);
  delay(36);
  anular.write(Angle);
  delay(34);
  menique.write(Angle);
  delay(1500);
}

void Hi() {
  Serial.println("Saludando");
  pulgar.write(150);
  Angle=180;
  medio.write(Angle);
  delay(150);
  anular.write(Angle);
  delay(150);
  Angle=90;
  delay(150);
  medio.write(Angle);
  delay(150);
  anular.write(Angle);
  delay(1500);
}

void Open2() {
  Serial.println("Abriendo");
  pulgar.write(150);
  Angle = 0;
  medio.write(Angle);
  delay(130);
  anular.write(Angle);
  delay(130);
  Angle=90;
  delay(130);
  medio.write(Angle);
  delay(130);
  anular.write(Angle);
  delay(1500);
}

void Bye() {
  Serial.println("Despidiendo");
  pulgar.write(80);
  Angle=180;
  indice.write(Angle);
  delay(150);
  anular.write(Angle);
  delay(150);
  menique.write(Angle);
  Angle=90;
  delay(150);
  indice.write(Angle);
  delay(150);
  anular.write(Angle);
  delay(150);
  menique.write(Angle);
  delay(1500);
}

void Open3() {
  Serial.println("Abriendo");
  pulgar.write(150);
  Angle = 0;
  indice.write(Angle);
  delay(130);
  anular.write(Angle);
  delay(130);
  menique.write(Angle);
  Angle=90;
  delay(130);
  indice.write(Angle);
  delay(130);
  anular.write(Angle);
  delay(130);
  menique.write(Angle);
  delay(1500);
}