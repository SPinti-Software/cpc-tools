#include <stdlib.h>
#include <stdio.h>
#include "base/cli.h"

static const CliArgument arguments[] = {
  {0, NULL, 0, NULL}
};

int
main(int argc, char **argv)
{
  int c;

  set_program_name(argv[0]);
  while ((c = cli_get_argument(arguments, argc, argv)) != EOF)
    {
      switch (c)
	{
	case 'v':
	  break;
	default:
	  cli_usage(arguments, EXIT_FAILURE);
	  break;
	}
    }
  return (EXIT_SUCCESS);
}
