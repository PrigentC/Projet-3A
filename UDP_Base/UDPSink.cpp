//
//  UDPSink.cpp
//  osc
//
//  Created by Jean-Marc Perronne on 14/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#include "stdafx.h"

#include "UDPSink.h"
#include "UDPError.h"


namespace stream
{
    UDPSink::UDPSink(const std::string& targetHost, short targetPort)
    {
        setupAddress(targetHost, targetPort);
        setupSocket();
    }
    
    void UDPSink::setupAddress(const std::string& targetHost, short targetPort)
    {
		int iResult = getaddrinfo(targetHost.c_str(), (PCSTR)targetPort, &hints, &result);

		ptr = result;
		

		/*memset( (char*)&serverAddress, 0, sizeof(serverAddress) );
		hostInfo = gethostbyname(targetHost.c_str());
        
        if (hostInfo == NULL) 
            throw UDPError("problem interpreting host: " + targetHost);
        
        serverAddress.sin_family = hostInfo->h_addrtype; 
        memcpy((char *) &serverAddress.sin_addr.s_addr, hostInfo->h_addr_list[0], hostInfo->h_length);
        serverAddress.sin_port = htons(targetPort);*/

    }
    
    void UDPSink::setupSocket()
    {
		connectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		
		
		/*socketDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
        if (socketDescriptor < 0)
            throw UDPError("cannot create socket");*/
    }

    void UDPSink::close() const
    {
		closesocket(connectSocket);
		
		/*closesocket(socketDescriptor);*/
    }

    void UDPSink::sendPacket(jmp::ByteBuffer& packet) const
    {
		int iResult = send(connectSocket, packet.array(), (int)strlen(packet.array()), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(connectSocket);
			WSACleanup();
		}
		
		
		/*int i = sendto(socketDescriptor, packet.array()+packet.position(), packet.remaining(), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        if ( i<0)
            throw UDPError("cannot send data");*/
    }
}
