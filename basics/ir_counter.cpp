
void loop{
counter();
}
void show() {
Serial. print("count=") ;
Serial. println(total) ;
}

void counter()
{
if (digitalRead(8) ==LOW){
if(digitalRead(7) ==HIGH) {
Serial.println("Entering") ;
total++;
show() ;
delay(1000) ;
}
}else if(digitalRead(7) ==LOW) {
if(digitalRead(8) ==HIGH) {
Serial.println("Leaving") ;
total--;
show();
delay(1000);
}
}}
