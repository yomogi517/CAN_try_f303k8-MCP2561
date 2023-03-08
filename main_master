#include "mbed.h"
 
DigitalOut led1(LED1);
// DigitalOut led2(LED2);
// DigitalOut led3(LED3);
// CAN can2(PB_8, PB_9);
CAN can1(PA_11, PA_12, 500000);
//EventQueue queue(32 * EVENTS_EVENT_SIZE);
//Thread t;

char counter[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
char RcvData[8];

CANMessage msg(0x456, counter, 8, CANData, CANStandard);

void send() {
    if(counter[0] % 0x10 == 0) {
        msg.id = 0x456;
        for(uint8_t i=0; i<8; i++) {
            msg.data[i] = counter[i]++;
        }
    } else {
        msg.id = 0x500;
        for(uint8_t i=0; i<8; i++) {
            msg.data[i] = counter[i]++;
        }
    }
    if(can1.write(msg)) {
        led1 = !led1;
        printf("\033[1;1HCAN1 TRANSID: 0x%x", msg.id);
        printf("\033[2;1HCAN1 DATA[0]: 0x%x", msg.data[0]);
        printf("\033[3;1HCAN1 DATA[1]: 0x%x", msg.data[1]);
        printf("\033[4;1HCAN1 DATA[2]: 0x%x", msg.data[2]);
        printf("\033[5;1HCAN1 DATA[3]: 0x%x", msg.data[3]);
        printf("\033[6;1HCAN1 DATA[4]: 0x%x", msg.data[4]);
        printf("\033[7;1HCAN1 DATA[5]: 0x%x", msg.data[5]);
        printf("\033[8;1HCAN1 DATA[6]: 0x%x", msg.data[6]);
        printf("\033[9;1HCAN1 DATA[7]: 0x%x", msg.data[7]);
    }
    if(counter[0] >= 0xF0)
        printf("\033[2J");if(counter[0] % 0x10 == 0) {
        msg.id = 0x456;
        for(uint8_t i=0; i<8; i++) {
            msg.data[i] = counter[i]++;
        }
    } else {
        msg.id = 0x500;
        for(uint8_t i=0; i<8; i++) {
            msg.data[i] = counter[i]++;
        }
    }
    if(can1.write(msg)) {
        led1 = !led1;
        printf("\033[1;1HCAN1 TRANSID: 0x%x", msg.id);
        printf("\033[2;1HCAN1 DATA[0]: 0x%x", msg.data[0]);
        printf("\033[3;1HCAN1 DATA[1]: 0x%x", msg.data[1]);
        printf("\033[4;1HCAN1 DATA[2]: 0x%x", msg.data[2]);
        printf("\033[5;1HCAN1 DATA[3]: 0x%x", msg.data[3]);
        printf("\033[6;1HCAN1 DATA[4]: 0x%x", msg.data[4]);
        printf("\033[7;1HCAN1 DATA[5]: 0x%x", msg.data[5]);
        printf("\033[8;1HCAN1 DATA[6]: 0x%x", msg.data[6]);
        printf("\033[9;1HCAN1 DATA[7]: 0x%x", msg.data[7]);
    }
    if(counter[0] >= 0xF0)
        printf("\033[2J");
}

int main() {
    EventQueue *queue = mbed_event_queue();
    //t.start(callback(&queue, &EventQueue::dispatch_forever)); 
    queue->call_every(1s, send); 
    
    CANMessage msg;
    while(1) {
        /*
        if(can2.read(msg)) {
            printf("Message received: %d\n", msg.data[0]);
            // led2 = !led2;
        } 
        ThisThread::sleep_for(100ms);
        led1 = !led1;
        */
    }
    
}
