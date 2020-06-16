String voice;
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define relay1 2    //Connect relay1 to pin 2
//#define relay2 3    //Connect relay2 to pin 3
#define relay3 10   //Connect relay1 to pin 2
//#define relay4 8    //Connect relay2 to pin 3

////////////////////////////////////////////
#define in 8
#define out 9
//#define fan 10

int count=0;

//////////////////////////////////////
void setup()
{ 
  lcd.begin(16,2);
  lcd.print("Home  Automation");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
//  pinMode(relay3, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);

   
  Serial.begin(9600);            //Set rate for communicating with phone
  pinMode(relay1, OUTPUT);       //Set relay1 as an output
//  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);      //Set relay2 as an output
//  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, LOW);     //Switch relay1 off
//  digitalWrite(relay2, LOW);     //Swtich relay2 off
  digitalWrite(relay3, LOW);     //Switch relay1 off
//  digitalWrite(relay4, LOW);     //Swtich relay2 off
}
void loop()
{
     int in_value = digitalRead(in);
     int out_value = digitalRead(out);
   //if(!Serial.available()){
     while(Serial.available())    //Check if there are available bytes to read
     {
        delay(10);                 //Delay to make it stable
        char c = Serial.read();    //Conduct a serial read
        if (c == '#'){
          break;                   //Stop the loop once # is detected after a word
        }
        voice += c;                //Means voice = voice + c
      }
      if (voice.length() >0)
      {
          Serial.println(voice);
          if(voice == "*switch on"){
            switchon();
          }               
          else if(voice == "*switch off"){
            switchoff();
          }             
  //       else if(voice == "*bulb1 on"){   
  //         digitalWrite(relay1, LOW);
  //      }
  //      else if(voice == "*bulb1 off"){
  //         digitalWrite(relay1, HIGH);
  //      }
   //     else if(voice == "*bulb2 on"){   
   //      digitalWrite(relay2, LOW);
   //     }
   //     else if(voice == "*bulb2 off"){
   //        digitalWrite(relay2, HIGH);
   //     }
          else if(voice == "*fan1 on"){   
             digitalWrite(relay3, LOW);
          }
          else if(voice == "*fan1 off"){
           digitalWrite(relay3, HIGH);
          }
   //     else if(voice == "*fan2 on"){
   //        digitalWrite(relay4, LOW);
   //     }
   //     else if(voice == "*fan2 off"){
   //       digitalWrite(relay4, HIGH);
   //     } 
          voice="";
      
         }
         else if(in_value==LOW || out_value==LOW)
         {
           iR_sensor(in_value,out_value);
         }
//////////////   
     // }
      
///////////////////////////////////////////
   
  /*
   if(in_value == LOW)
   {
     count++;
     lcd.clear();
     lcd.print("Person In Room:");
     lcd.setCursor(0,1);
     lcd.print(count);
     delay(1000);
   }
  
   if(out_value == LOW)
   {
     if(count>0){
       count--;
     }
     lcd.clear();
     lcd.print("Person In Room:");
     lcd.setCursor(0,1);
     lcd.print(count);
     delay(1000);
   }
 
  
   if(count<=0)
   {
     lcd.clear();
     digitalWrite(relay3, HIGH);
     lcd.clear();
     lcd.print("Nobody In Room");
     lcd.setCursor(0,1);
     lcd.print("Fan is Off");
     delay(100);
   }

//////////////////////////////////////////////
  
  
   else if(count>0)
   {
     digitalWrite(relay3, LOW);
   }
*/
}

void iR_sensor(int in_value, int out_value){

   
   if(in_value == LOW)
   {
     count++;
     lcd.clear();
     lcd.print("Person In Room:");
     lcd.setCursor(0,1);
     lcd.print(count);
     delay(1000);
   }
  
   if(out_value == LOW)
   {
     if(count>0){
       count--;
     }
     lcd.clear();
     lcd.print("Person In Room:");
     lcd.setCursor(0,1);
     lcd.print(count);
     delay(1000);
   }
 
   if(count<=0)
   {
     lcd.clear();
     digitalWrite(relay3, HIGH);
     lcd.clear();
     lcd.print("Nobody In Room");
     lcd.setCursor(0,1);
     lcd.print("Fan is Off");
     delay(100);
   }

//////////////////////////////////////////////
  
  
   else if(count>0)
   {
     digitalWrite(relay3, LOW);
   }
  // else{
  //   break ;
  // }
}



void switchon()               //Function for turning on relays
{
//   digitalWrite(relay1, LOW);
//  digitalWrite(relay2, LOW);
   digitalWrite(relay3, LOW);
//  digitalWrite(relay4, LOW);
}


void switchoff()              //Function for turning on relays
{
//   digitalWrite(relay1, HIGH);
//  digitalWrite(relay2, HIGH);
   digitalWrite(relay3, HIGH);
//  digitalWrite(relay4, HIGH);
}
