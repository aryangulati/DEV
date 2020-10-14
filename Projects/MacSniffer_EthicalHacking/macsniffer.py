#!/usr/bin/python

import socket
#this library helps in  communication over internet and pcs
from struct import *
#string to binary


def eth_addr(a):
	b = "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x" % (ord(a[0]), ord(a[1]), ord(a[2]), ord(a[3]), ord(a[4]), ord(a[5]))
	#%.2 denotes the value of mac address and x represents hexa decimal, ord(a[0]) prints the value in the %
	return b



try:
	s = socket.socket(socket.AF_PACKET,socket.SOCK_RAW, socket.ntohs(0x0003))
	#manipulate packets at protocol level, converts packet to raw , converts  of positive numbers from network to host
except:
	print("[!!]Error on creating socket objects")
	exit(0)



while True:
	packet = s.recvfrom(65535)
	#recieve the packets from 65535 ports
	packet = packet[0]
	#the first part of packet is shown by [0]
	eth_length = 14
	eth_header = packet[:eth_length]
	#strips the packet from the ethernet variable to the eth_length i.e. 14 bytes

	eth = unpack('!6s6sH',eth_header)
	#uses struct libraary for unpacking
	eth_protocol = socket.ntohs(eth[2])
	#takes the protocol bytes from packet i.e. 3rd part of packet denoted by eth[2]
	print('[+] Destination MAC: '+ eth_addr(packet[0:6]) + '[+] Source MAC: '+ eth_addr(packet[6:12]) + '[+] protocol: ' + str(eth_protocol))
	#prints the sniffing actions taking place

