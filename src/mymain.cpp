#include <Arduino.h>
#include <crazygaze/micromuc/Logging.h>
#include <crazygaze/micromuc/SerialStringReader.h>


// Putting this before mut.h so we can detect if CZMUT_SERIAL is set
#ifdef CZMUT_SERIAL
	#define MySerial_RXPin 17
	#define MySerial_TXPin 16
#endif

#include <crazygaze/mut/mut.h>

#if CZ_SERIAL_LOG_ENABLED
	cz::SerialLogOutput gSerialLogOutput;
#endif

#if CONSOLE_COMMANDS
	cz::SerialStringReader<> gSerialStringReader;
#endif

void setup()
{
#ifdef MySerial_RXPin
	CZMUT_SERIAL.setRX(MySerial_RXPin);
	CZMUT_SERIAL.setTX(MySerial_TXPin);
#endif

#if CZ_SERIAL_LOG_ENABLED
	gSerialLogOutput.begin(CZMUT_SERIAL, 115200);
#endif

#if CONSOLE_COMMANDS
	gSerialStringReader.begin(CZMUT_SERIAL);
#endif

	CZ_LOG(logDefault, Log, "Starting. czmut test tag filter=%s", CZMUT_COMPILE_TIME_TAGS);
	cz::mut::run();
}

void loop()
{
}