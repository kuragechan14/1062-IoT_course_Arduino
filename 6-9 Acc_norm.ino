#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  #include "Wire.h"
#endif
MPU6050 accelgyro;
int16_t ax, ay, az, gx, gy, gz;

void setup() {
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin(); // Wire object from Arduino
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true); // Tweaked Wire object from
  #endif // Gene Knight's NBWire project
  Serial.begin(38400);
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize(); // Initializing I2C devices
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" :
  "MPU6050 connection failed");

}

void loop() {
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  double a;
  a=sqrt(pow(ax,2)+pow(ay,2)+pow(az,2));
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.print(gz); Serial.print("\t");
  Serial.println(a);
  delay(100);
}
