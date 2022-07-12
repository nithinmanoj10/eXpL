// Outputs fancy error messages for eXpL

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ERR_TYPE 0
#define ERR_FUNC 1

extern int errorLineNumber;
extern char *errorInputFileName;

void printError(int errorType, char *errorMessage);
char *getErrorName(int errorType);