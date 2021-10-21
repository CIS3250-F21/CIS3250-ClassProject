CC = clang
CFLGS = -std=c99 -Wall -pedantic
EXECS = main group1
O_FILES = group1.o group2.o group3.o group4.o group5.o group6.o group7.o group8.o group9.o group10.o group11.o group12.o group13.o group14.o group15.o group16.o group17.o
H_FILES = group1.h group2.h group3.h group4.h group5.h group6.h group7.h group8.h group9.h group10.h group11.h group12.h group13.h group14.h group15.h group16.h group17.h

all: $(EXECS)

clean:
	rm $($EXECS) *.o

%: %.o
%: %.c

%.o: %.c main.h $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

main: main.o $(O_FILES) main.h $(H_FILES)
	$(CC) $(CFLAGS) main.o $(O_FILES) -o main
	
main.o: main.c main.h $(H_FILES)
	$(CC) $(CFLASG) -c main.c -o main.o

#Group O Files
group1.o: group1.c group1.h main.h
	$(CC) $(CFLGAS) -c group1.c -o group1.o

group2.o: group2.c group2.h main.h
	$(CC) $(CFLGAS) -c group2.c -o group2.o

group3.o: group3.c group3.h main.h
	$(CC) $(CFLGAS) -c group3.c -o group3.o

group4.o: group4.c group4.h main.h
	$(CC) $(CFLGAS) -c group4.c -o group4.o

group5.o: group5.c group5.h main.h
	$(CC) $(CFLGAS) -c group5.c -o group5.o

group6.o: group6.c group6.h main.h
	$(CC) $(CFLGAS) -c group6.c -o group6.o

group7.o: group7.c group7.h main.h
	$(CC) $(CFLGAS) -c group7.c -o group7.o

group8.o: group8.c group8.h main.h
	$(CC) $(CFLGAS) -c group8.c -o group8.o

group9.o: group9.c group9.h main.h
	$(CC) $(CFLGAS) -c group9.c -o group9.o

group10.o: group10.c group10.h main.h
	$(CC) $(CFLGAS) -c group10.c -o group10.o

group11.o: group11.c group11.h main.h
	$(CC) $(CFLGAS) -c group11.c -o group11.o

group12.o: group12.c group12.h main.h
	$(CC) $(CFLGAS) -c group12.c -o group12.o

group13.o: group13.c group13.h main.h
	$(CC) $(CFLGAS) -c group13.c -o group13.o

group14.o: group14.c group14.h main.h
	$(CC) $(CFLGAS) -c group14.c -o group14.o

group15.o: group15.c group15.h main.h
	$(CC) $(CFLGAS) -c group15.c -o group15.o

group16.o: group16.c group16.h main.h
	$(CC) $(CFLGAS) -c group16.c -o group16.o

group17.o: group17.c group17.h main.h
	$(CC) $(CFLGAS) -c group17.c -o group17.o
