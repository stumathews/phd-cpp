#include <iostream>
#include "PacketSniffer.h"
using namespace std;

int main( int argc, char** argv ){
	
	PacketSniffer* packetSniffer = new PacketSniffer();
	packetSniffer->selectDevice( new string("venet0") );
	packetSniffer->setTimeout( 0 );
	packetSniffer->start();
	return 0;

}
