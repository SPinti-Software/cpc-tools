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
#include <string.h>

#if defined(_WIN32) && !defined(__CYGWIN__)
# define PATH_SEP '\\'
#else
# define PATH_SEP '/'
#endif /* _WIN32 && !__CYGWIN__ */

static const char *program_name = NULL;
static const char *program_desc = NULL;
static const char *program_version = NULL;

const char *
get_program_name(void)
{
  if (program_name == NULL)
    {
#ifdef PACKAGE
      return (PACKAGE);
#else
      return ("???");
#endif
    }

  return (program_name);
}

void
set_program_name(const char *name)
{
  char *tmp;

  tmp = strrchr(name, PATH_SEP);
  if (tmp != NULL)
    {
      program_name = tmp + 1;
    }
  else
    {
      program_name = tmp;
    }
}

const char *
get_program_desc(void)
{
  return (program_desc);
}

void
set_program_desc(const char *desc)
{
  program_desc = desc;
}

const char *
get_program_version(void)
{
  if (program_version == NULL)
    {
#ifdef PACKAGE_VERSION
      return (PACKAGE_VERSION);
#else
      return ("?.?.?");
#endif /* PACKAGE_VERSION */
    }
  return (program_version);
}

void
set_program_version(const char *version)
{
  program_version = version;
}

const char *
get_program_bugreport(void)
{
  return (NULL);
}

void
set_prgram_bugreport(const char *bugreport)
{
  (void)bugreport;
}
