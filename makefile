CC = clang
CFLGS = -std=c99 -Wall -pedantic
EXECS = main
O_FILES = Group1/group1.o Group2/group2.o Group3/group3.o Group4/group4.o Group5/group5.o Group6/group6.o Group7/group7.o Group8/group8.o Group9/group9.o Group10/group10.o Group11/group11.o Group12/group12.o Group13/group13.o Group14/group14.o Group15/group15.o Group16/group16.o Group17/group17.o
H_FILES = Group1/group1.h Group2/group2.h Group3/group3.h Group4/group4.h Group5/group5.h Group6/group6.h Group7/group7.h Group8/group8.h Group9/group9.h Group10/group10.h Group11/group11.h Group12/group12.h Group13/group13.h Group14/group14.h Group15/group15.h Group16/group16.h Group17/group17.h

all: $(EXECS)

clean:
	rm $(EXECS) $(O_FILES)

%: %.o
%: %.c

%.o: %.c main.h $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

main: main.o $(O_FILES) main.h $(H_FILES)
	$(CC) $(CFLAGS) main.o $(O_FILES) -o main
	
main.o: main.c main.h $(H_FILES)
	$(CC) $(CFLASG) -c main.c -o main.o

#Gtroup O Files
Group1/group1.o: Group1/group1.c Group1/group1.h main.h
	$(CC) $(CFLGAS) -c Group1/group1.c -o Group1/group1.o

Group2/group2.o: Group2/group2.c Group2/group2.h main.h
	$(CC) $(CFLGAS) -c Group2/group2.c -o Group2/group2.o

Group3/group3.o: Group3/group3.c Group3/group3.h main.h
	$(CC) $(CFLGAS) -c Group3/group3.c -o Group3/group3.o

Group4/group4.o: Group4/group4.c Group4/group4.h main.h
	$(CC) $(CFLGAS) -c Group4/group4.c -o Group4/group4.o

Group5/group5.o: Group5/group5.c Group5/group5.h main.h
	$(CC) $(CFLGAS) -c Group5/group5.c -o Group5/group5.o

Group6/group6.o: Group6/group6.c Group6/group6.h main.h
	$(CC) $(CFLGAS) -c Group6/group6.c -o Group6/group6.o

Group7/group7.o: Group7/group7.c Group7/group7.h main.h
	$(CC) $(CFLGAS) -c Group7/group7.c -o Group7/group7.o

Group8/group8.o: Group8/group8.c Group8/group8.h main.h
	$(CC) $(CFLGAS) -c Group8/group8.c -o Group8/group8.o

Group9/group9.o: Group9/group9.c Group9/group9.h main.h
	$(CC) $(CFLGAS) -c Group9/group9.c -o Group9/group9.o

Group10/group10.o: Group10/group10.c Group10/group10.h main.h
	$(CC) $(CFLGAS) -c Group10/group10.c -o Group10/group10.o

Group11/group11.o: Group11/group11.c Group11/group11.h main.h
	$(CC) $(CFLGAS) -c Group11/group11.c -o Group11/group11.o

Group12/group12.o: Group12/group12.c Group12/group12.h main.h
	$(CC) $(CFLGAS) -c Group12/group12.c -o Group12/group12.o

Group13/group13.o: Group13/group13.c Group13/group13.h main.h
	$(CC) $(CFLGAS) -c Group13/group13.c -o Group13/group13.o

Group14/group14.o: Group14/group14.c Group14/group14.h main.h
	$(CC) $(CFLGAS) -c Group14/group14.c -o Group14/group14.o

Group15/group15.o: Group15/group15.c Group15/group15.h main.h
	$(CC) $(CFLGAS) -c Group15/group15.c -o Group15/group15.o

Group16/group16.o: Group16/group16.c Group16/group16.h main.h
	$(CC) $(CFLGAS) -c Group16/group16.c -o Group16/group16.o

Group17/group17.o: Group17/group17.c Group17/group17.h main.h
	$(CC) $(CFLGAS) -c Group17/group17.c -o Group17/group17.o
