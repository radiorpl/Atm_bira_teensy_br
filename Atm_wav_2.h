/*
header file for function to play wav in loop
button stops or starts
7/15/17
loop function works by putting playCheck in ON_LOOP event 
added button skips tracks
added play function has input filename
7/19/17
*/
#pragma once

#include <Automaton.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

class Atm_wav_2 : public Machine {
	public:
		enum { WAV1_1_ON, WAV1_2_ON, WAV1_3_ON, WAV1_4_ON, WAV1_5_ON, WAV1_OFF, WAV2_1_ON, WAV2_2_ON, WAV2_3_ON, WAV2_4_ON, WAV2_5_ON, WAV2_OFF }; //STATES
		enum { EVT_ENC_DOWN, EVT_ENC_UP, EVT_BTN_1, EVT_PLAY_CHECK_1, EVT_PLAY_CHECK_2, ELSE }; //EVENTS
		//enum {WAV_START, WAV_STOP}; //ACTIONS
		
		Atm_wav_2( void ) : Machine(){};
		Atm_wav_2& begin( void );
		Atm_wav_2& play( int player, const char *filename ); 
		Atm_wav_2& stop( int player );
		Atm_wav_2& playCheck( void );
		Atm_wav_2& trace( Stream& stream );
		Atm_wav_2& onPress( Machine& machine, int event = 0 );
		Atm_wav_2& onPress( atm_cb_push_t callback, int idx = 0 ); 
		Atm_wav_2& trigger( int event );
		int state( void );
		//Atm_controller looper;
		//Atm_wav_2& btn_1( void );
		//int pin;
		//Atm_wav_2& volume( int volume );
		
	private:
     	enum { ENT_WAV1_1_ON, ENT_WAV1_2_ON, ENT_WAV1_3_ON, ENT_WAV1_4_ON, ENT_WAV1_5_ON, ENT_WAV1_OFF, ENT_WAV2_1_ON, ENT_WAV2_2_ON, ENT_WAV2_3_ON, ENT_WAV2_4_ON, ENT_WAV2_5_ON, ENT_WAV2_OFF, ENT_PLAY_CHECK }; // ACTIONS
     	enum { ON_PRESS, CONN_MAX }; // CONNECTORS
     	atm_connector connectors[CONN_MAX];
		//atm_timer_millis check_timer;
		//atm_counter counter;
		
     	int event( int id ); 
     	void action( int id );	
};
