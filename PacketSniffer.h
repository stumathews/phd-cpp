#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include <pcap.h>
#include <string>
#include "Packet.h"

using namespace std;

enum Result { success, fail };

class PacketSniffer
{
public:
	PacketSniffer();
	void selectDevice( string* device );
	void setTimeout( int timeout );
	Result start();
	void stop();
	void restart();
private:
	string* device;
	int timeout;
	pcap_t* handle;
	const u_char* packet;
	struct pcap_pkthdr header;
	char errBuff[BUFSIZ];


	static void gotPacket( u_char* args, const struct pcap_pkthdr* header, const u_char* packet);
};
#endif
