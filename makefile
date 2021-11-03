CC = clang
CFLGS = -std=c99 -Wall -pedantic
EXECS = main
O_FILES = Group1/Group1.o Group2/Group2.o Group3/Group3.o Group4/Group4.o Group5/Group5.o Group6/Group6.o Group7/Group7.o Group8/Group8.o Group9/Group9.o Group10/Group10.o Group11/Group11.o Group12/Group12.o Group13/Group13.o Group14/Group14.o Group15/Group15.o Group16/Group16.o Group17/Group17.o Group1/Group1Tests.o Group2/Group2Tests.o Group3/Group3Tests.o Group4/Group4Tests.o Group5/Group5Tests.o Group6/Group6Tests.o Group7/Group7Tests.o Group8/Group8Tests.o Group9/Group9Tests.o Group10/Group10Tests.o Group11/Group11Tests.o Group12/Group12Tests.o Group13/Group13Tests.o Group14/Group14Tests.o Group15/Group15Tests.o Group16/Group16Tests.o Group17/Group17Tests.o
H_FILES = main.h groupIncludes.h groupTestIncludes.h

all: $(EXECS)

clean:
	rm $(EXECS) $(O_FILES) main.o

%: %.o
%: %.c

%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

main: main.o $(O_FILES) $(H_FILES)
	$(CC) $(CFLAGS) main.o $(O_FILES) -o main -lm
	
main.o: main.c $(H_FILES)
	$(CC) $(CFLASG) -c main.c -o main.o

#Group O Files
Group1/Group1.o: Group1/Group1.c Group1/Group1.h main.h
	$(CC) $(CFLGAS) -c Group1/Group1.c -o Group1/Group1.o

Group2/Group2.o: Group2/Group2.c Group2/Group2.h main.h
	$(CC) $(CFLGAS) -c Group2/Group2.c -o Group2/Group2.o

Group3/Group3.o: Group3/Group3.c Group3/Group3.h main.h
	$(CC) $(CFLGAS) -c Group3/Group3.c -o Group3/Group3.o

Group4/Group4.o: Group4/Group4.c Group4/Group4.h main.h
	$(CC) $(CFLGAS) -c Group4/Group4.c -o Group4/Group4.o

Group5/Group5.o: Group5/Group5.c Group5/Group5.h main.h
	$(CC) $(CFLGAS) -c Group5/Group5.c -o Group5/Group5.o

Group6/Group6.o: Group6/Group6.c Group6/Group6.h main.h
	$(CC) $(CFLGAS) -c Group6/Group6.c -o Group6/Group6.o

Group7/Group7.o: Group7/Group7.c Group7/Group7.h main.h
	$(CC) $(CFLGAS) -c Group7/Group7.c -o Group7/Group7.o

Group8/Group8.o: Group8/Group8.c Group8/Group8.h main.h
	$(CC) $(CFLGAS) -c Group8/Group8.c -o Group8/Group8.o

Group9/Group9.o: Group9/Group9.c Group9/Group9.h main.h
	$(CC) $(CFLGAS) -c Group9/Group9.c -o Group9/Group9.o

Group10/Group10.o: Group10/Group10.c Group10/Group10.h main.h
	$(CC) $(CFLGAS) -c Group10/Group10.c -o Group10/Group10.o

Group11/Group11.o: Group11/Group11.c Group11/Group11.h main.h
	$(CC) $(CFLGAS) -c Group11/Group11.c -o Group11/Group11.o

Group12/Group12.o: Group12/Group12.c Group12/Group12.h main.h
	$(CC) $(CFLGAS) -c Group12/Group12.c -o Group12/Group12.o

Group13/Group13.o: Group13/Group13.c Group13/Group13.h main.h
	$(CC) $(CFLGAS) -c Group13/Group13.c -o Group13/Group13.o

Group14/Group14.o: Group14/Group14.c Group14/Group14.h main.h
	$(CC) $(CFLGAS) -c Group14/Group14.c -o Group14/Group14.o

Group15/Group15.o: Group15/Group15.c Group15/Group15.h main.h
	$(CC) $(CFLGAS) -c Group15/Group15.c -o Group15/Group15.o

Group16/Group16.o: Group16/Group16.c Group16/Group16.h main.h
	$(CC) $(CFLGAS) -c Group16/Group16.c -o Group16/Group16.o

Group17/Group17.o: Group17/Group17.c Group17/Group17.h main.h
	$(CC) $(CFLGAS) -c Group17/Group17.c -o Group17/Group17.o

#Group Test O Files
Group1/Group1Tests.o: Group1/Group1Tests.c Group1/Group1Tests.h main.h
	$(CC) $(CFLGAS) -c Group1/Group1Tests.c -o Group1/Group1Tests.o

Group2/Group2Tests.o: Group2/Group2Tests.c Group2/Group2Tests.h main.h
	$(CC) $(CFLGAS) -c Group2/Group2Tests.c -o Group2/Group2Tests.o

Group3/Group3Tests.o: Group3/Group3Tests.c Group3/Group3Tests.h main.h
	$(CC) $(CFLGAS) -c Group3/Group3Tests.c -o Group3/Group3Tests.o

Group4/Group4Tests.o: Group4/Group4Tests.c Group4/Group4Tests.h main.h
	$(CC) $(CFLGAS) -c Group4/Group4Tests.c -o Group4/Group4Tests.o

Group5/Group5Tests.o: Group5/Group5Tests.c Group5/Group5Tests.h main.h
	$(CC) $(CFLGAS) -c Group5/Group5Tests.c -o Group5/Group5Tests.o

Group6/Group6Tests.o: Group6/Group6Tests.c Group6/Group6Tests.h main.h
	$(CC) $(CFLGAS) -c Group6/Group6Tests.c -o Group6/Group6Tests.o

Group7/Group7Tests.o: Group7/Group7Tests.c Group7/Group7Tests.h main.h
	$(CC) $(CFLGAS) -c Group7/Group7Tests.c -o Group7/Group7Tests.o

Group8/Group8Tests.o: Group8/Group8Tests.c Group8/Group8Tests.h main.h
	$(CC) $(CFLGAS) -c Group8/Group8Tests.c -o Group8/Group8Tests.o

Group9/Group9Tests.o: Group9/Group9Tests.c Group9/Group9Tests.h main.h
	$(CC) $(CFLGAS) -c Group9/Group9Tests.c -o Group9/Group9Tests.o

Group10/Group10Tests.o: Group10/Group10Tests.c Group10/Group10Tests.h main.h
	$(CC) $(CFLGAS) -c Group10/Group10Tests.c -o Group10/Group10Tests.o

Group11/Group11Tests.o: Group11/Group11Tests.c Group11/Group11Tests.h main.h
	$(CC) $(CFLGAS) -c Group11/Group11Tests.c -o Group11/Group11Tests.o

Group12/Group12Tests.o: Group12/Group12Tests.c Group12/Group12Tests.h main.h
	$(CC) $(CFLGAS) -c Group12/Group12Tests.c -o Group12/Group12Tests.o

Group13/Group13Tests.o: Group13/Group13Tests.c Group13/Group13Tests.h main.h
	$(CC) $(CFLGAS) -c Group13/Group13Tests.c -o Group13/Group13Tests.o

Group14/Group14Tests.o: Group14/Group14Tests.c Group14/Group14Tests.h main.h
	$(CC) $(CFLGAS) -c Group14/Group14Tests.c -o Group14/Group14Tests.o

Group15/Group15Tests.o: Group15/Group15Tests.c Group15/Group15Tests.h main.h
	$(CC) $(CFLGAS) -c Group15/Group15Tests.c -o Group15/Group15Tests.o

Group16/Group16Tests.o: Group16/Group16Tests.c Group16/Group16Tests.h main.h
	$(CC) $(CFLGAS) -c Group16/Group16Tests.c -o Group16/Group16Tests.o

Group17/Group17Tests.o: Group17/Group17Tests.c Group17/Group17Tests.h main.h
	$(CC) $(CFLGAS) -c Group17/Group17Tests.c -o Group17/Group17Tests.o
