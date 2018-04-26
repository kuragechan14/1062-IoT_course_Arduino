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
  double ax2,ay2,az2,gx2,gy2,gz2;
  ax2=ax/16384.0;
  ay2=ay/16384.0;
  az2=az/16384.0;
  Serial.print("a/g:\t");
  Serial.print(ax2); Serial.print("\t");
  Serial.print(ay2); Serial.print("\t");
  Serial.print(az2); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);
  delay(100);
}
