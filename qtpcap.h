#ifndef QTPCAP_H
#define QTPCAP_H

#endif // QTPCAP_H

#include "Include/pcap.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifndef WIN32
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#else
#include <winsock.h>
#endif
