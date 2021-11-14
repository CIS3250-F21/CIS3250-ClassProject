CC = clang
CFLAGS = -std=c99 -Wall -pedantic
EXECS = main
O_FILES = Group1/Group1.o GlobalScaling/GlobalScaling.o ScalingInX/ScalingInX.o Group4/Group4.o Group5/Group5.o Group6/Group6.o RotationInY/RotationInY.o Group8/Group8.o Group9/Group9.o XPlaneReflection/XPlaneReflection.o Group11/Group11.o zPlaneReflection/zPlaneReflection.o ShearInX/ShearInX.o Group14/Group14.o ShearInZ/ShearInZ.o Group16/Group16.o Group17/Group17.o Group1/Group1Tests.o GlobalScaling/GlobalScalingTests.o ScalingInX/ScalingInXTests.o Group4/Group4Tests.o Group5/Group5Tests.o Group6/Group6Tests.o RotationInY/RotationInYTests.o Group8/Group8Tests.o Group9/Group9Tests.o XPlaneReflection/XPlaneReflectionTests.o Group11/Group11Tests.o zPlaneReflection/zPlaneReflectionTests.o ShearInX/ShearInXTests.o Group14/Group14Tests.o ShearInZ/ShearInZTests.o Group16/Group16Tests.o Group17/Group17Tests.o
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
	$(CC) $(CFLAGS) -c main.c -o main.o

#Group O Files
Group1/Group1.o: Group1/Group1.c Group1/Group1.h main.h
	$(CC) $(CFLAGS) -c Group1/Group1.c -o Group1/Group1.o

GlobalScaling/GlobalScaling.o: GlobalScaling/GlobalScaling.c GlobalScaling/GlobalScaling.h main.h
	$(CC) $(CFLAGS) -c GlobalScaling/GlobalScaling.c -o GlobalScaling/GlobalScaling.o

ScalingInX/ScalingInX.o: ScalingInX/ScalingInX.c ScalingInX/ScalingInX.h main.h
	$(CC) $(CFLAGS) -c ScalingInX/ScalingInX.c -o ScalingInX/ScalingInX.o

Group4/Group4.o: Group4/Group4.c Group4/Group4.h main.h
	$(CC) $(CFLAGS) -c Group4/Group4.c -o Group4/Group4.o

Group5/Group5.o: Group5/Group5.c Group5/Group5.h main.h
	$(CC) $(CFLAGS) -c Group5/Group5.c -o Group5/Group5.o

Group6/Group6.o: Group6/Group6.c Group6/Group6.h main.h
	$(CC) $(CFLAGS) -c Group6/Group6.c -o Group6/Group6.o

RotationInY/RotationInY.o: RotationInY/RotationInY.c RotationInY/RotationInY.h main.h
	$(CC) $(CFLAGS) -c RotationInY/RotationInY.c -o RotationInY/RotationInY.o

Group8/Group8.o: Group8/Group8.c Group8/Group8.h main.h
	$(CC) $(CFLAGS) -c Group8/Group8.c -o Group8/Group8.o

Group9/Group9.o: Group9/Group9.c Group9/Group9.h main.h
	$(CC) $(CFLAGS) -c Group9/Group9.c -o Group9/Group9.o

XPlaneReflection/XPlaneReflection.o: XPlaneReflection/XPlaneReflection.c XPlaneReflection/XPlaneReflection.h main.h
	$(CC) $(CFLAGS) -c XPlaneReflection/XPlaneReflection.c -o XPlaneReflection/XPlaneReflection.o

Group11/Group11.o: Group11/Group11.c Group11/Group11.h main.h
	$(CC) $(CFLAGS) -c Group11/Group11.c -o Group11/Group11.o

zPlaneReflection/zPlaneReflection.o: zPlaneReflection/zPlaneReflection.c zPlaneReflection/zPlaneReflection.h main.h
	$(CC) $(CFLAGS) -c zPlaneReflection/zPlaneReflection.c -o zPlaneReflection/zPlaneReflection.o

ShearInX/ShearInX.o: ShearInX/ShearInX.c ShearInX/ShearInX.h main.h
	$(CC) $(CFLAGS) -c ShearInX/ShearInX.c -o ShearInX/ShearInX.o

Group14/Group14.o: Group14/Group14.c Group14/Group14.h main.h
	$(CC) $(CFLAGS) -c Group14/Group14.c -o Group14/Group14.o

ShearInZ/ShearInZ.o: ShearInZ/ShearInZ.c ShearInZ/ShearInZ.h main.h
	$(CC) $(CFLAGS) -c ShearInZ/ShearInZ.c -o ShearInZ/ShearInZ.o

Group16/Group16.o: Group16/Group16.c Group16/Group16.h main.h
	$(CC) $(CFLAGS) -c Group16/Group16.c -o Group16/Group16.o

Group17/Group17.o: Group17/Group17.c Group17/Group17.h main.h
	$(CC) $(CFLAGS) -c Group17/Group17.c -o Group17/Group17.o

#Group Test O Files
Group1/Group1Tests.o: Group1/Group1Tests.c Group1/Group1Tests.h main.h
	$(CC) $(CFLAGS) -c Group1/Group1Tests.c -o Group1/Group1Tests.o

GlobalScaling/GlobalScalingTests.o: GlobalScaling/GlobalScalingTests.c GlobalScaling/GlobalScalingTests.h main.h
	$(CC) $(CFLAGS) -c GlobalScaling/GlobalScalingTests.c -o GlobalScaling/GlobalScalingTests.o

ScalingInX/ScalingInXTests.o: ScalingInX/ScalingInXTests.c ScalingInX/ScalingInXTests.h main.h
	$(CC) $(CFLAGS) -c ScalingInX/ScalingInXTests.c -o ScalingInX/ScalingInXTests.o

Group4/Group4Tests.o: Group4/Group4Tests.c Group4/Group4Tests.h main.h
	$(CC) $(CFLAGS) -c Group4/Group4Tests.c -o Group4/Group4Tests.o

Group5/Group5Tests.o: Group5/Group5Tests.c Group5/Group5Tests.h main.h
	$(CC) $(CFLAGS) -c Group5/Group5Tests.c -o Group5/Group5Tests.o

Group6/Group6Tests.o: Group6/Group6Tests.c Group6/Group6Tests.h main.h
	$(CC) $(CFLAGS) -c Group6/Group6Tests.c -o Group6/Group6Tests.o

RotationInY/RotationInYTests.o: RotationInY/RotationInYTests.c RotationInY/RotationInYTests.h main.h
	$(CC) $(CFLAGS) -c RotationInY/RotationInYTests.c -o RotationInY/RotationInYTests.o

Group8/Group8Tests.o: Group8/Group8Tests.c Group8/Group8Tests.h main.h
	$(CC) $(CFLAGS) -c Group8/Group8Tests.c -o Group8/Group8Tests.o

Group9/Group9Tests.o: Group9/Group9Tests.c Group9/Group9Tests.h main.h
	$(CC) $(CFLAGS) -c Group9/Group9Tests.c -o Group9/Group9Tests.o

XPlaneReflection/XPlaneReflectionTests.o: XPlaneReflection/XPlaneReflectionTests.c XPlaneReflection/XPlaneReflectionTests.h main.h
	$(CC) $(CFLAGS) -c XPlaneReflection/XPlaneReflectionTests.c -o XPlaneReflection/XPlaneReflectionTests.o

Group11/Group11Tests.o: Group11/Group11Tests.c Group11/Group11Tests.h main.h
	$(CC) $(CFLAGS) -c Group11/Group11Tests.c -o Group11/Group11Tests.o

zPlaneReflection/zPlaneReflectionTests.o: zPlaneReflection/zPlaneReflectionTests.c zPlaneReflection/zPlaneReflectionTests.h main.h
	$(CC) $(CFLAGS) -c zPlaneReflection/zPlaneReflectionTests.c -o zPlaneReflection/zPlaneReflectionTests.o

ShearInX/ShearInXTests.o: ShearInX/ShearInXTests.c ShearInX/ShearInXTests.h main.h
	$(CC) $(CFLAGS) -c ShearInX/ShearInXTests.c -o ShearInX/ShearInXTests.o

Group14/Group14Tests.o: Group14/Group14Tests.c Group14/Group14Tests.h main.h
	$(CC) $(CFLAGS) -c Group14/Group14Tests.c -o Group14/Group14Tests.o

ShearInZ/ShearInZTests.o: ShearInZ/ShearInZTests.c ShearInZ/ShearInZTests.h main.h
	$(CC) $(CFLAGS) -c ShearInZ/ShearInZTests.c -o ShearInZ/ShearInZTests.o

Group16/Group16Tests.o: Group16/Group16Tests.c Group16/Group16Tests.h main.h
	$(CC) $(CFLAGS) -c Group16/Group16Tests.c -o Group16/Group16Tests.o

Group17/Group17Tests.o: Group17/Group17Tests.c Group17/Group17Tests.h main.h
	$(CC) $(CFLAGS) -c Group17/Group17Tests.c -o Group17/Group17Tests.o
