#include "mbed.h"

DigitalOut led1(LED1);
CircularBuffer<CANMessage, 32> queue;
RawCAN can(PA_11, PA_12, 1000000);

char RcvData[8]; 

void canListen() {  // ISR
    CANMessage msg;

    if (can.read(msg)) {
        queue.push(msg);
    }
}

int main(void) {
    // can.frequency(250000);
    can.mode(CAN::Normal);

    can.attach(&canListen, CAN::RxIrq);

    while (1) {
        while (!queue.empty()) {
            CANMessage msg;
            queue.pop(msg);
            led1 = !led1;
            printf("\033[1;25HCAN RCVID: 0x%x", msg.id);
            for(uint8_t i=0; i<8; i++) {
                RcvData[i] = msg.data[i];
            }
            printf("\033[2;25HCAN DATA[0]: 0x%x", RcvData[0]);        
            printf("\033[3;25HCAN DATA[0]: 0x%x", RcvData[1]);
            printf("\033[4;25HCAN DATA[0]: 0x%x", RcvData[2]);
            printf("\033[5;25HCAN DATA[0]: 0x%x", RcvData[3]);
            printf("\033[6;25HCAN DATA[0]: 0x%x", RcvData[4]);
            printf("\033[7;25HCAN DATA[0]: 0x%x", RcvData[5]);
            printf("\033[8;25HCAN DATA[0]: 0x%x", RcvData[6]);
            printf("\033[9;25HCAN DATA[0]: 0x%x", RcvData[7]);
            // led1 = !led1;
        }
    }
}
