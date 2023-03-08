#include "mbed.h"
 
DigitalOut led1(LED1);
// DigitalOut led2(LED2);
// DigitalOut led3(LED3);
CAN can2(PA_11, PA_12, 500000);
//CAN can1(PB_12, PB_13);
//EventQueue queue(32 * EVENTS_EVENT_SIZE);
//Thread t;

char counter[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
char RcvData[8]; 

void canRcv();
CANMessage msg(0x500,CANStandard);

/* 
void send() {
    printf("send()\n");
    if(can1.write(CANMessage(1337, &counter, 1))) {
        counter++;
        printf("Message sent: %d\n", counter);
        // led3 = !led3;
    } 
}
*/
 
int main() {
    // EventQueue *queue = mbed_event_queue();
    // t.start(callback(&queue, &EventQueue::dispatch_forever)); 
    // queue->call_every(1s, send); 
    
    CANMessage msg;
    while(1) {
        if(can2.read(msg)) {
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
            led1 = !led1;
        }
        ThisThread::sleep_for(100ms);
        //led1 = !led1;
    }
    
}
/* 受信割り込みがmbedOS6のCANライブラリだと使えないらしい
void canRcv(void){
    can2.read(msg);
    printf("\033[1;25HCAN RCVID: 0x%x\n", msg.id);
    if(msg.id == 0x500) {
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
        led1 = !led1;
    }
}
*/
