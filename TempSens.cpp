""" INITALIZE AND GET CURRENT TEMPRATURE FROM A TEMPRATURE SENSOR """


char c1=0;                                           
void setup() 
{
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);
  Serial.println("ENTER 1 FOR DEGREES CELCIUS");
  Serial.println("ENTER 2 FOR KELVIN");   
  Serial.println();            
}
void loop()
{                                        
  if(Serial.available()>0)                            
  {
    c1=Serial.read();
    if(c1=='1'||c1=='2')                                                                
    {
      if(c1=='1')
      {
        Serial.print("TEMPRATURE IN DEGREES CELCIUS IS: ");
        Serial.println(((analogRead(1)/1024.0)*5000)/10);
        Serial.println("ENTER 2 FOR CHANGING UNIT TO KELVIN");
        Serial.println();
      }
      else
      { 
        Serial.print("TEMPRATURE IN KELVIN IS: ");
        Serial.println((((analogRead(1)/1024.0)*5000)/10.0)+273);
        Serial.println("ENTER 1 FOR CHANGING UNIT TO CELCIUS");
        Serial.println();
      }
    }
    else                                                                            
    { 
      Serial.println("INVALID CHOICE!!!");
      Serial.println("ENTER 1 FOR DEGREES CELCIUS");
      Serial.println("ENTER 2 FOR KELVIN");
      Serial.println();
      c1=0;
    }
  }
}
""" COMPLETE """
