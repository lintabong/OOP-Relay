class RELAY{
    int pin;
    // initiate strat time of blinking relay
    unsigned long startTime;
    unsigned long onTime;
    unsigned long offTime;
    unsigned long prevTime;
    unsigned long mastTime;

    public:
    RELAY(int p, long st, long on, long off){
        pin = p;
        pinMode(p, OUTPUT);
        digitalWrite(p, HIGH);
        
        startTime = st  * 100;
        onTime    = on  * 100;
        offTime   = off * 100;
        prevTime  = 0;        
    }

    void Update(){
        if (millis() >= startTime){
            unsigned long currTime = millis() - prevTime;
            if (currTime <= onTime){
                digitalWrite(pin, LOW);
            }else if (currTime >= onTime && currTime <= offTime + onTime){
                digitalWrite(pin, HIGH);
            }else if (currTime >= offTime + onTime){
                prevTime = millis();
            }
        }
    }
};

RELAY relay1(9,   0, 10, 10);
RELAY relay2(8, 100, 10, 10);
RELAY relay3(7, 100, 11, 11);
RELAY relay4(6, 140,  3,  3);
RELAY relay5(5, 160,  2,  2);
RELAY relay6(4, 160,  7,  3);
RELAY relay7(3, 170, 20, 20);
RELAY relay8(2, 170, 30, 10);

void setup() {
    Serial.begin(9600);

}

void loop() {
    relay1.Update();
    relay2.Update();
    relay3.Update();
    relay4.Update();
    relay5.Update();
    relay6.Update();
    relay7.Update();
    relay8.Update();

}
