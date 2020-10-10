/*
Sending values from DOUTpin to AdaFruit server through ESP8266
*/
int DOUTpin=13;
void setup () {
pinMode(DOUTpin, INPUT);
}
void server()
{  
// Ensure the connection to the MQTT server is alive (this will make the first
// connection and automatically reconnect when disconnected).  See the MQTT_connect
/ function definition further below.
  MQTT_connect();

// this is our 'wait for incoming subscription packets' busy subloop
// try to spend your time here

/*Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
  if (subscription == &onoffbutton) {
  Serial.print(F("Got: "));
  Serial.println((char *)onoffbutton.lastread); 
  uint16_t state = atoi((char *)onoffbutton.lastread);        
  if(state == 2){
    }
   }
  */
  // Now we can publish stuff!
  Serial.print(F("\nSending sensor val "));
  Serial.print(x);
  Serial.print("...");
  int sensor_value =digitalRead(Doutput);
  if (! sensor.publish(sensor_value)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
}
 
 // Function to connect and reconnect as necessary to the MQTT server.
 // Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

 //Stop if already connected.
  if (mqtt.connected()) {   
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
