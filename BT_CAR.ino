char dir;//variable to read the letters F, B, L, R, S comming from app.
void setup()
{
  pinMode(5, OUTPUT);     //left motor connect for forward movement
  pinMode(6, OUTPUT);     //left motor connect for backward movement
  pinMode(9, OUTPUT);     //right motor connect for forward movement
  pinMode(10, OUTPUT);    //right motor connect for backward movement
  Serial.begin(9600);     //port opened to read input letters from app
}
void loop()
{
  if(Serial.available())  //as long as port is open
  {
    dir = Serial.read();  //read the input data from app
  }
  if(dir == 'F')          //if app sends letter F, move forward
  {
    digitalWrite(5,HIGH); //rotate left moter forward
    digitalWrite(9,HIGH); //rotate right moter forward
  }
  if(dir == 'B')          //if app sends letter B, move backward
  {
    digitalWrite(6,HIGH); //rotate left moter backward
    digitalWrite(10,HIGH);//rotate right moter backward
  }
  if(dir == 'L')          //for letter L, turn left(left moter does not rotate)
  {
    digitalWrite(9,HIGH); //rotate right moter forward
  }
  if(dir == 'R')          //for letter R, turn right(right moter does not rotate)
  {
    digitalWrite(5,HIGH); //rotate left moter forward
  }
  if(dir == 'S')          //if app sends letter S, Stop all motors
  {
    digitalWrite(5, LOW); //stop left forward motor
    digitalWrite(6, LOW); //stop left backward motor
    digitalWrite(9, LOW); //stop right forward motor
    digitalWrite(10, LOW); //stop right backward motor
  }
  delay(100);
}                         //loop() ends here