#include "motors.h"
#include "BNO.h"
#include "PID.h"

unsigned long start_millis;
unsigned long current_millis;
int setpint = 0;
double yaw;
double output;

Motors motors(
    MOTOR1_PWM, MOTOR1_IN1, MOTOR1_IN2, 
    MOTOR2_PWM, MOTOR2_IN1, MOTOR2_IN2, 
    MOTOR3_PWM, MOTOR3_IN1, MOTOR3_IN2, 
    MOTOR4_PWM, MOTOR4_IN1, MOTOR4_IN2
);

Bno bno;

PID pid(0.6, 0.00735, 45, 200);


void setup() {
    Serial.begin(9600);
    motors.InitializeMotors();  // Inicializar los motores
    Serial.println("Prueba de motores iniciada.");

    bno.bno_begin();

    start_millis = millis();

}

void loop() {

    bno.getEuler();
    yaw = bno.getYaw();

    output = pid.Calculate(setpint, yaw);
    Serial.println(output);


    delay(20);  
    /*
    Serial.println("Mover hacia adelante");
    motors.SetAllSpeeds(90);
    motors.MoveForward();
    
    Serial.println("Mover hacia atrás");
    motors.MoveBackward();
    delay(2000);

    Serial.println("Girar a la izquierda");
    motors.MoveLeft();
    delay(2000);

    Serial.println("Girar a la derecha");
    motors.MoveRight();
    delay(2000);

    Serial.println("Girar en círculos");
    for (int angle = 0; angle < 360; angle += 45) {  // Gira en múltiples ángulos
        motors.MoveMotors(angle, 255);
        delay(500);
    }

    Serial.println("Detener motores");
    motors.StopMotors();
    delay(3000);  
    */
}

