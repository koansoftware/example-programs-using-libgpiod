// ---------------------------------------------------------------------
// monitor-gpio.c
//
//   This is an example of GPIO monitoring with the libGPIOd library.
//
// Copyright 2018 Christophe BLAESS (christophe@blaess.fr)
// License GPL v2.
// ---------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>

int event_cb(int event, unsigned int offset, const struct timespec *timestamp, void *unused)
{
	fprintf(stderr, "[%ld.%09ld] %s\n",
	         timestamp->tv_sec, timestamp->tv_nsec,
	         (event == GPIOD_CTXLESS_EVENT_CB_RISING_EDGE)? "rising" :
	         (event == GPIOD_CTXLESS_EVENT_CB_FALLING_EDGE)? "falling" :
	         (event == GPIOD_CTXLESS_EVENT_CB_TIMEOUT) ? "timeout" : "??");

	return GPIOD_CTXLESS_EVENT_CB_RET_OK;
}



int main(int argc, char *argv[])
{
	int offset;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <controler> <offset>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (sscanf(argv[2], "%d", &offset) != 1) {
		fprintf(stderr, "invalid offset: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	gpiod_ctxless_event_monitor(argv[1], GPIOD_CTXLESS_EVENT_BOTH_EDGES, 
	                         offset, 0, argv[0], NULL, NULL, event_cb, NULL);

	return EXIT_SUCCESS;
}
