#include "PacketSniffer.h"
#include <iostream>
using namespace std;

PacketSniffer::PacketSniffer(){
}
void PacketSniffer::selectDevice( string* thatDevice ){
	this->device = thatDevice;
}
void PacketSniffer::setTimeout( int thatTimeout ){
	this->timeout = thatTimeout;
}
Result PacketSniffer::start(){
	handle = pcap_open_live( "venet0", BUFSIZ, -1, this->timeout, errBuff );
	if( handle == NULL ){
		cout << "Couldn't open device " << device->c_str() << endl;
		return fail;
	}else{
		cout << "Proceeding with device " << device->c_str() << endl; 
	}

	pcap_loop( handle, 200, PacketSniffer::gotPacket, (u_char*)this ); 
	pcap_close(handle);
}
void PacketSniffer::stop(){}
void PacketSniffer::restart(){}
void PacketSniffer::gotPacket( u_char* args, const struct pcap_pkthdr* header, const u_char* packet){
	/* We've got a packet. */
	/* Encapsulate it in class Packet */
	Packet* ourPacket = new Packet(packet); // Hasn't been linked to PacketSniffer class just yet...
	if (ourPacket->isValidIP()){
		cout << ourPacket->getSourceIP() << endl;
		cout << ourPacket->getSourceMAC() << endl;
		cout << ourPacket->getDestinationMAC() << endl;
		cout << ourPacket->getDestinationIP() << endl;
		}
}
