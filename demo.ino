
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

int valx = A0;
int valy = A1;
int valz = A2;

int x_sensor ;
int y_sensor ;
int z_sensor ;

int last_x, last_y,last_z;


/* void Sensor_Calibrate()
{
  delay(5000);
 send_signal(64,1);
 delay(5000);
  send_signal(64,2);
  delay(5000);
  send_signal(64,3);
  delay(5000); 
}
*/

/*void send_signal(char port_no, int channel_no)
{
  int val = 0;
  x = analogRead(port_no)/4;
  if(val > 126)
  {
    val = 127;
  }
  */
  
  
  void setup()
  {
    MIDI.begin(4);
    Serial.begin(115200);
   
  }
  
  void loop()
  { 
    x_sensor = analogRead(valx);
  if(x_sensor - last_x > 5 || x_sensor - last_x < -5)
  {
  MIDI.sendNoteOn(1,127,1);
  MIDI.sendNoteOff(1,127,1);
  last_x = x_sensor;
  delay(200);
  }
  
  }
  
/*void setup()
{
  MIDI.begin(4);
  Serial.begin(115200);
  Sensor_Calibrate();
}
void loop()
{
  send_signal(x_sensor,1);
  send_signal(y_sensor,2);
  send_signal(z_sensor,3);
  delay(100);
  
}


*/
