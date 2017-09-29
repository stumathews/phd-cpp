#include "Packet.h"

char* Packet::getSourceIP(){
	this->ip_address = (struct in_addr) ip_header->ip_src;
	return inet_ntoa( ip_address );
}
char* Packet::getDestinationIP(){
	this->ip_address = (struct in_addr) ip_header->ip_dst;
	return inet_ntoa( ip_address );
}
char* Packet::getSourceMAC(){
	this->ethernet_addr = (struct ether_addr*)ethernet_header->ether_shost;
	return ether_ntoa( (struct ether_addr*)ethernet_header->ether_shost);
	//return ether_ntoa(ethernet_addr);
}
char* Packet::getDestinationMAC(){
	this->ethernet_addr = (struct ether_addr*)ethernet_header->ether_dhost;
	return ether_ntoa(ethernet_addr);
}
bool Packet::isValidIP(){
	return (ip_header->ip_hl & 0x0f) < 20;
}
bool Packet::isValidTCP(){
}
