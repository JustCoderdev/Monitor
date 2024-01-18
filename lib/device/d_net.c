/* #ifndef __APPLE__ */
/* extern const int TRANSLATION_MOCK; */
/* #else */

/* #include <arpa/inet.h> */
/* #include <sys/socket.h> */

#include "../device.h"

char *device_net_ssid(void)
{
	return "*Webpocket";

#if 0
	int sock = -1;
	struct sockaddr_in address = {0};
	socklen_t address_len = sizeof(address);
	struct in_addr addr = {0};
	/* u8 i; */

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		log_errno("Couldn't connect with socket");
		exit(1);
	}


	address.sin_family = AF_INET;
	address.sin_addr = addr;
	address.sin_port = htons(80);

	if(bind(sock, (struct sockaddr *)&address, address_len) == -1)
	{
		log_errno("Couldn't bind socket");
		exit(1);
	}

	/* if(connect(sock, &address, address_len) == -1) { */
	/* 	log_errno("Couldn't connect with socket"); */
	/* 	exit(1); */
	/* } */

	if(getsockname(sock, (struct sockaddr *)&address, &address_len) == -1)
	{
		log_errno("Couldn't retrieve socket name");
		exit(1);
	}

	/* printf("address len: %u\n", address.sa_len); */
	/* printf("address family: %u\n", address.sa_family); */
	printf("address data: %s\n", inet_ntoa(address.sin_addr));
	/* printf("address data: "); */
	/* for (i = 0; i < 14; ++i) { */
	/* 	printf("(%d)", address.sa_data[i]); */
	/* } */

	printf("\n===\n");

	return "error";
#endif
}
char *device_net_address(void)
{
	/* 192.168.1.150 */
	return "*Disconnected";
}

/* #endif */
