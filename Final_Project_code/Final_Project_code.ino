/* Group 3: Dwight Thomas, Angel Mitchell, Larry Sanders and Johnathan Curry.
*
* This is our final Project. 
* What it does is show the functionality of our board that we are using to show how the it would alret the user to check for the things on their checklist. 
*
* What will happen is it will show how on the motion of the board, meaning the door is opened, the board red LEDs will light up and the buzzer will sound off to indicate to the user check for your stuff
* at which this these things will not stop until the user pressers the button on the board, meaning they have checked their list for everything and are ready to go. When the button is pressed the 
* buzzer and red LEDs will turn off and the greed LEDS will light up meaning all clear to go.
*
* Hardware:
* 3 red, 3 green LEDs light, a buzzer,  a button, 9 jumper wires, the breadboard, the boosterpack and the launchpad and a UBS cable and a laptop.
*
*/

// define your pitch constant for buzzer
#define NOTE  15000
//Highest freqency 65535, lowest is 31

const int buzzerPin = 19;      // the number of the pin the buzzer is connected to
const int buttonPin = 18;     // the number of the pushbutton pin
const int ledPin =  17;      // the number of red the LED pin
const int ledPin1 = 2;      // the number of green Led pin

int breadboardButtonState = 0; // variable for reading the BB button status
int launchpadButtonState = 0; // variable for reading the LP button state

/* In the setup function we will set our buzzer pin to 
 * output, the led pins to output and the button pin to input. That's all we need to do at setup. 
 */
void setup() 
{
  pinMode(buzzerPin, OUTPUT); // set buzzerPin to OUTPUT
  // initialize the breadboard LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the onboard LED
  pinMode(ledPin1, OUTPUT);      
  // initialize the onboard LED
  pinMode(RED_LED, OUTPUT);
  // initialize the breadboard push button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

/* In the loop section we will use the tone function to 
 * enable enable the sound, light up the red LED light, then on the button press the buzzer and red LEDs will turn off and green LEDs
 * will turn on . Tone needs arguments for the 
 * pin of the buzzer, the note, and the note duration.
 */
 
int oldButtonState = LOW;
void loop() 
{
  // read the state of the push button value:
  breadboardButtonState = digitalRead(buttonPin);
  launchpadButtonState = digitalRead(PUSH2);
  
  if(oldButtonState == LOW)
  {
    //This ensures that at the beginning the buzzer and red LEDs are on.
    digitalWrite(ledPin, HIGH); // turn red LED on:
    int noteDuration = 1000;
    tone(buzzerPin, NOTE, noteDuration);
  }
  
  // check if the breadboard push button is pressed.
  // if it is, turn the green LEDs state to HIGH and red LEDs state to LOW
  if (breadboardButtonState == 0) 
  {
     if (oldButtonState == LOW)  
     {       
       digitalWrite(ledPin, LOW); // turn red LED off:
       digitalWrite(ledPin1, HIGH); // turn green LED on:
       oldButtonState = HIGH;  
       noTone(buzzerPin); // stop the tone playing
     }
   
   breadboardButtonState = digitalRead(buttonPin);
  }
}
