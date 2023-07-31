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
#include "lexer.hpp"

static unsigned int max_line_length = 80;
/*static int autoformat = 0;*/
static const char *filename;

static CliArgument arguments[] = {
  {'l', "line-length", CLI_REQUIRED_VALUE, "set max line length (default: 80)"},
  {'s', "style", CLI_NO_VALUE, "turn on coding style checking"},
  {-1, nullptr, CLI_NO_VALUE, nullptr}
};

int
main(int argc, char **argv)
{
  int c;

  set_program_name(argv[0]);
  set_program_desc("Check if CpcdosC+ code is valid and well formated");

  while ((c = cli_get_argument(arguments, argc, argv)) != EOF)
    {
      switch (c)
	{
	case 0:
	  /* TODO: set filename */
	  break;
	default:
	  cli_usage(arguments, EXIT_FAILURE);
	  break;
	}
    }
  return (EXIT_SUCCESS);
}
