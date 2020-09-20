// ---------------------------------------------------------------------
// ctxless-toggle-gpio.c
//
//   This is an example of simple GPIO access with the libGPIOd library.
//
// Copyright 2018 Christophe BLAESS (christophe@blaess.fr)
// License GPL v2.
// ---------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	for (;;) {
		gpiod_ctxless_set_value(argv[1], offset, 0, 0, argv[0], NULL, NULL);
		gpiod_ctxless_set_value(argv[1], offset, 1, 0, argv[0], NULL, NULL);
	}
	return EXIT_SUCCESS;
}
