  	// code by rishabh jain
  	// you may alter and use this how so ever you may like
  	//there might be small errors

   * LCD RS  pin to analog pin A0

   * LCD  Enable pin to analog pin A1

   * LCD D4  pin to analog pin A2

   * LCD D5  pin to analog pin A3

   * LCD D6  pin to analog pin A4

   * LCD D7  pin to analog pin A5

   The  Arduino circuit connection MAtrix Key Pad:

   * ROW1 pin  to digital pin 5

   * ROW2 pin  to digital pin 4

   * ROW3 pin  to digital pin 3

   * ROW4 pin  to digital pin 2

   * COLUMN1  pin to digital pin 6

   * COLUMN2  pin to digital pin 7

   * COLUMN3  pin to digital pin 8

   * COLUMN4  pin to digital pin 9

   e-mail:-rishabhhasanemail@gmail.com

   */
 

  #include <LiquidCrystal.h>
  #include <Keypad.h>
  #include <ctype.h>
  int i=0;
  int j=0;

  char array[16][2] = {}
  void setcursor(int i,int j);
  void buffr(int i, int j, char elem);
  LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
   const byte ROWS = 4; // Four rows

  const byte COLS = 4; // Four columns

  // Define the Keymap

  char keys[ROWS][COLS] = 

  {

   
  {'1','2','3','A'},

   
  {'4','5','6','B'},

   
  {'7','8','9','C'},

   
  {'*','0','#','D'}

  };
  	byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
	byte colPins[COLS] = {9,8, 7, 6}; //connect to the column pinouts of the keypad
	Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
	 

	 void setup()  {
   
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  int l,k;
  int setpoint=1209;

  }

  void loop(){
  char key = keypad.getKey();
  
  if (key){

    switch(key){

    case '1' : lcd.print (key);
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '2' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '4' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '5' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '6' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '7' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '8' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case '9' : lcd.print (key); 
    			buffr(i,j,key);
    			i++;
    			setcursor(i,j);
    case 'A' : lcd.clear();
    			i=0;
    			j=0;
    case 'B' : 	if(i!=0){
    					i--;
    					setcursor(i,j);
    					lcd.print(" ");
   					 }
   	case 'C' : 
   		for(k=0;k<=j;k++){
   		for(l=0;l<=i;l++){
   			lcd.setCursor(l,k);
   			lcd.print(array[l][k])
   		}
   		}
   	case 'D' : 
   		lcd.clear();
   		i=0;
   		j=0;
   		lcd.print(setpoint);
   	case '#' : 
   		lcd.clear();
   		lcd.setCursor(0,0)
   		lcd.print('0')

	}


  }
}

	void setcursor(int i,int j){

		if(i<16){
			lcd.setCursor(i,j)
		}
		else {
			i=0;
			if(j<2){
				j++;
			else{
				j=0;
				}
			}
			lcd.setCursor(i,j);
		}
	}


	void buffr(int i, int j, char elem){

		array[i][j]= elem;
	}