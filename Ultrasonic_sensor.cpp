#include "mbed.h”

Serial PC(USBTX, USBRX);

DigitalOut trigger(PC_8);

DigitalIn echo(PC_0);

int distance = 0;

Timer sonar;

int main()

{

  while (1) {

    trigger = 1;

    sonar.reset();

    wait_us(10.0);

    trigger = 0;

    while (echo == 0);

    sonar.start();

    while (echo == 1);

    sonar.stop()

        distance = (sonar.read_us()) / 58.0;

    PC.printf(“Distance is % d cm\n\n”, distance);

    wait(0.2);
  }
}