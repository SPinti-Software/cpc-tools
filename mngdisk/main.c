/*
 * Copyright (C) 2023 d0p1
 *
 * This file is part of CpcTools.
 *
 * CpcTools are free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CpcTools are distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CpcTools.  If not, see <http://www.gnu.org/licenses/>.
 */

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
