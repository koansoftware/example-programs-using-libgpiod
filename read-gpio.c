// ---------------------------------------------------------------------
// read-gpio.c
//
//   This is an example of simple GPIO access with the libGPIOd library.
//
// Copyright 2018 Christophe BLAESS (christophe@blaess.fr)
// License GPL v2.
// ---------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int value;
	int offset;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <controler> <offset>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (sscanf(argv[2], "%d", &offset) != 1) {
		fprintf(stderr, "invalid offset: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	value = gpiod_ctxless_get_value(argv[1], offset, 0, argv[0]);

	if (value < 0) {
		perror("gpiod_ctxless_get_value");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", value);
	return EXIT_SUCCESS;
}
