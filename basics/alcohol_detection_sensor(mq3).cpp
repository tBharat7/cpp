int DOUTpin=10;
int LEDpin=13;

void setup() {
pinMode(DOUTpin, INPUT);
pinMode(LEDpin, OUTPUT);

}

void loop() {
alcohol();
delay(3000);
}

void alcohol() 
{
value=digitalRead(DOUTpin) ;
Serial. print("value:") ;
delay(1000) ;
if(value==HIGH) {
digitalWrite(LEDpin, HIGH) ;
}
else{
digitalWrite(LEDpin, LOW) ;
}
}
