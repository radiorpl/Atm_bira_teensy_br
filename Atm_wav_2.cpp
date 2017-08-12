/*
src file for function to play wav in loop
button stops or starts
7/15/17
+++++++++++
loop function works by putting playCheck in ON_LOOP event 
added button skips tracks
added play function has input filename
++++++++++++++++++++++++++++
7/19/17
changed to encoders to toggle tracks up and down
works but needs debouncing or something b/c encoder is too sensitive
+++++++++++++++++++++++++++++++++++++++++++++++
Change to 2 wav players
8/1/17
*/
#include "Atm_wav_2.h"

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=394,289
AudioPlaySdWav           playSdWav2;     //xy=398,385
AudioMixer4              mixer1;         //xy=594,297
AudioMixer4              mixer2;         //xy=591,395
AudioOutputI2S           i2s1;           //xy=824,334
AudioConnection          patchCord1(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord2(playSdWav1, 1, mixer1, 1);
AudioConnection          patchCord3(playSdWav2, 0, mixer2, 2);
AudioConnection          patchCord4(playSdWav2, 1, mixer2, 3);
AudioConnection          patchCord5(mixer2, 0, i2s1, 1);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=744,575
// GUItool: end automatically generated code

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

Atm_wav_2& Atm_wav_2::begin( void ) {
  	// clang-format off
	static const state_t state_table[] PROGMEM = {
		/*               	ON_ENTER    		ON_LOOP    	ON_EXIT		EVT_ENC_UP		  EVT_ENC_DOWN	 	EVT_BTN_1		EVT_PLAY_CHECK_1    EVT_PLAY_CHECK_2  	ELSE */
		/*	WAV1_1_ON */		ENT_WAV1_1_ON, 	ENT_PLAY_CHECK,		-1,		WAV1_2_ON,	  	 	-1,				WAV2_1_ON,		WAV1_1_ON,				-1,			-1,	  
		/*	WAV1_2_ON */		ENT_WAV1_2_ON, 	ENT_PLAY_CHECK,		-1,		WAV1_3_ON,	  	 WAV1_1_ON,			WAV2_1_ON,		WAV1_2_ON,				-1,			-1,
		/*	WAV1_3_ON */		ENT_WAV1_3_ON, 	ENT_PLAY_CHECK,		-1,		WAV1_4_ON,	  	 WAV1_2_ON,			WAV2_1_ON,		WAV1_3_ON,				-1,			-1,
		/*	WAV1_4_ON */		ENT_WAV1_4_ON, 	ENT_PLAY_CHECK,		-1,		WAV1_5_ON,	  	 WAV1_3_ON,			WAV2_1_ON,		WAV1_4_ON,				-1,			-1,
		/*	WAV1_5_ON */		ENT_WAV1_5_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 	 WAV1_4_ON,			WAV2_1_ON,		WAV1_5_ON,				-1,			-1,
		/*	WAV1_OFF */			ENT_WAV1_OFF,		-1,				-1,			-1,	 			-1,				WAV2_1_ON,			-1,					-1,			-1,
		/*	WAV2_1_ON */		ENT_WAV2_1_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 		-1,				WAV2_OFF,			-1,					WAV2_1_ON,		-1,	  
		/*	WAV2_2_ON */		ENT_WAV2_2_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 		-1,				WAV2_OFF,			-1,					WAV2_1_ON,		-1,
		/*	WAV2_3_ON */		ENT_WAV2_3_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 		-1,				WAV2_OFF,			-1,					WAV2_1_ON,		-1,
		/*	WAV2_4_ON */		ENT_WAV2_4_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 		-1,				WAV2_OFF,			-1,					WAV2_1_ON,		-1,
		/*	WAV2_5_ON */		ENT_WAV2_5_ON, 	ENT_PLAY_CHECK,		-1,			-1,	  	 		 -1,			WAV2_OFF,			-1,					WAV2_1_ON,		-1,
		/*	WAV2_OFF */			ENT_WAV2_OFF,		-1,				-1,			-1,	 			-1,				WAV2_1_ON			-1,						-1,			-1,
		
		
		
	};
    // clang-format on
    Machine::begin( state_table, ELSE );	
	AudioMemory(8);
	sgtl5000_1.enable();
	sgtl5000_1.volume(0.5);
    mixer1.gain(0, 0.5);
    mixer1.gain(1, 0.5);
    mixer2.gain(0, 0.5);
    mixer2.gain(1, 0.5);
	SPI.setMOSI(SDCARD_MOSI_PIN);
	SPI.setSCK(SDCARD_SCK_PIN);
	if (!(SD.begin(SDCARD_CS_PIN))) {
	   while (1) {
	     Serial.println("Unable to access the SD card");   
	   }   
	 }
    return *this;	
}

int Atm_wav_2::event( int id ) {
  switch ( id ) {
    case EVT_ENC_UP:
	return 0;  
  }
  switch ( id ) {
    case EVT_ENC_DOWN:
	return 0;  
  }
  switch ( id ) {
    case EVT_BTN_1:
	return 0;  
  }
  switch ( id ) {
    case EVT_PLAY_CHECK_1: 
	return 0;
  } 
  switch ( id ) {
    case EVT_PLAY_CHECK_2: 
	return 0; 
	}
}
/* Add C++ code for each action
 * This generates the 'output' for the state machine
 *
 * Available connectors:
 *   push( connectors, ON_PRESS, 0, <v>, <up> );
 */
void Atm_wav_2::action( int id ) {
	switch ( id ) {
		case ENT_WAV1_1_ON:
			play(1, "DRONE1.WAV");
			return;
		case ENT_WAV1_2_ON:
			play(1, "DRONE2.WAV");
			return;
		case ENT_WAV1_3_ON:
			play(1, "DRONE3.WAV");
			return;	
		case ENT_WAV1_4_ON:
			play(1, "DRONE4.WAV");
			return;
		case ENT_WAV1_5_ON:
			play(1, "DRONE5.WAV");
			return;				
		case ENT_WAV1_OFF:
			stop(1);
			return;
		case ENT_WAV2_1_ON:
			play(2, "DRONE1.WAV");
			return;
		case ENT_WAV2_2_ON:
			play(2, "DRONE2.WAV");
			return;
		case ENT_WAV2_3_ON:
			play(2, "DRONE3.WAV");
			return;	
		case ENT_WAV2_4_ON:
			play(2, "DRONE4.WAV");
			return;
		case ENT_WAV2_5_ON:
			play(2, "DRONE5.WAV");
			return;				
		case ENT_WAV2_OFF:
			stop(2);
			return;
		case ENT_PLAY_CHECK:
			playCheck();
			return;
		}	
}

/* Optionally override the default trigger() method
 * Control how your machine processes trigger
 */

Atm_wav_2& Atm_wav_2::trigger( int event ) {
  Machine::trigger( event );
  return *this;
}

/* Optionally override the default state() method
 * Control what the machine returns when another process requests its state
 */

int Atm_wav_2::state( void ) {
  return Machine::state();
}

Atm_wav_2& Atm_wav_2::play( int player, const char *filename ) {
	//while (state() == 0) //loops with if, but no button. this is correct way to do state
	//while ( state() == 0 ) cycle(); 
	//if (playSdWav1.isPlaying() == false)
	//if ( state() == 0 && playSdWav1.isPlaying() == false) //does not make loop on its own		
	if ( player == 1 ){
		playSdWav1.play( filename ); //play wav file
		delay(10);
		Serial.println( player );
		Serial.println( filename );	
	}
	else if ( player == 2 ){
		playSdWav2.play( filename ); //play wav file
		delay(10);
		Serial.println( player );
		Serial.println( filename );
	}	
		return *this;
	
}


Atm_wav_2& Atm_wav_2::stop( int player ) {
	if ( player == 1){
		playSdWav1.stop(); //stop wav file
		Serial.println("stop");
	}
	else if ( player == 2){
		playSdWav2.stop(); //stop wav file
		Serial.println("stop");
	}
	return *this;
}

Atm_wav_2& Atm_wav_2::playCheck( void ) {
	if ( state() != 5 && playSdWav1.isPlaying() == false ) { //doesn't stop trigger with true/false or 0/1
		trigger( EVT_PLAY_CHECK_1 );
		Serial.println("playCheck1");
		}
	else if ( state() != 11 && playSdWav2.isPlaying() == false ) {
		trigger( EVT_PLAY_CHECK_2 );
		Serial.println("playCheck2");
		}	
	return *this;
}
/* Nothing customizable below this line                          
 ************************************************************************************************
*/

/* Public event methods
 *
 */
/*
Atm_wav_2& Atm_wav_2::btn_1() {
  trigger( EVT_BTN_1 );
  return *this;
}
*/
/*
 * onPress() push connector variants ( slots 1, autostore 0, broadcast 0 )
 */

Atm_wav_2& Atm_wav_2::onPress( Machine& machine, int event ) {
  onPush( connectors, ON_PRESS, 0, 1, 1, machine, event );
  return *this;
}

Atm_wav_2& Atm_wav_2::onPress( atm_cb_push_t callback, int idx ) {
  onPush( connectors, ON_PRESS, 0, 1, 1, callback, idx );
  return *this;
}

/* State trace method
 * Sets the symbol table and the default logging method for serial monitoring
 */

Atm_wav_2& Atm_wav_2::trace( Stream & stream ) {
  Machine::setTrace( &stream, atm_serial_debug::trace,
    "WAV_1\0EVT_ENC_UP\0EVT_ENC_DOWN\0EVT_PLAY_CHECK_1\0EVT_CHECK_TIMER\0ELSE\0WAV1_1_ON\0WAV_2_ON\0WAV_3_ON\0WAV_4_ON\0WAV_5_ON\0WAV_OFF" );
  return *this;
}
/*
Atm_led& Atm_led::trigger( int event ) {
  if ( event > ELSE ) {
    play();
  } else {
    Machine::trigger( event );
  }
  return *this;
}
*/