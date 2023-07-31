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

#ifndef CPCTOOLS_BASE_CLI_H
# define CPCTOOLS_BASE_CLI_H 1

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

typedef enum
{
  CLI_NO_VALUE,
  CLI_REQUIRED_VALUE,
  CLI_OPTIONAL_VALUE
} CliValueInfo;

typedef struct
{
  int short_name;
  const char *long_name;
  CliValueInfo has_value;
  const char *help_string;
} CliArgument;

const char *get_program_name(void);
void set_program_name(const char *name);
const char *get_program_desc(void);
void set_program_desc(const char *desc);
const char *get_program_version(void);
void set_program_version(const char *version);
const char *get_program_bugreport(void);
void set_program_bugreport(const char *bugreport);

void cli_usage(const CliArgument *arguments, int status);
void cli_version(void);
int cli_get_argument(const CliArgument *arguments, int argc, char **argv);

# ifdef __cplusplus
}
# endif /* __cplusplus */


#endif /* !CPCTOOLS_BASE_CLI_H */
