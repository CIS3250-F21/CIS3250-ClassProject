#include "../main.h"
#include "ReadInput.h"


void runReadInputTests();

struct shape* readCSVInputTest(char *);

char ReadInputTest1(char *, char *, char *);

int ReadInputTest2(char *, char *, char[20]);

int ReadInputTest3(char *, char *orgFile, char[20]);

int ReadInputTest4(char *, char *orgFile, char[20]);

int ReadInputTest5(char[20], char[20]);

int ReadInputTest6(char[20], char[20], char[20]);

void freeShape(struct shape *);
