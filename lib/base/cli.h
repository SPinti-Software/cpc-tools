#ifndef CPCTOOLS_BASE_CLI_H
# define CPCTOOLS_BASE_CLI_H 1

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


#endif /* !CPCTOOLS_BASE_CLI_H */
