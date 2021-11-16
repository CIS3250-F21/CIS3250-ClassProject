CC = clang
CFLAGS = -std=c99 -Wall -pedantic
EXECS = main
O_FILES = Group1/Group1.o GlobalScaling/GlobalScaling.o ScalingInX/ScalingInX.o ScalingInY/ScalingInY.o ScalingInZ/ScalingInZ.o RotationInX/RotationInX.o RotationInY/RotationInY.o Group8/Group8.o XYZTranslation/XYZTranslation.o XPlaneReflection/XPlaneReflection.o Group11/Group11.o ZPlaneReflection/ZPlaneReflection.o Group13/Group13.o Group14/Group14.o ShearInZ/ShearInZ.o XYZTranslation/XYZTranslation.o OutputResults/OutputResults.o Group1/Group1Tests.o GlobalScaling/GlobalScalingTests.o ScalingInX/ScalingInXTests.o ScalingInY/ScalingInYTests.o ScalingInZ/ScalingInZTests.o RotationInX/RotationInXTests.o RotationInY/RotationInYTests.o Group8/Group8Tests.o XYZTranslation/XYZTranslationTests.o XPlaneReflection/XPlaneReflectionTests.o Group11/Group11Tests.o ZPlaneReflection/ZPlaneReflectionTests.o Group13/Group13Tests.o Group14/Group14Tests.o ShearInZ/ShearInZTests.o XYZTranslation/XYZTranslationTests.o OutputResults/OutputResultsTests.o
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

ScalingInY/ScalingInY.o: ScalingInY/ScalingInY.c ScalingInY/ScalingInY.h main.h
	$(CC) $(CFLAGS) -c ScalingInY/ScalingInY.c -o ScalingInY/ScalingInY.o

ScalingInZ/ScalingInZ.o: ScalingInZ/ScalingInZ.c ScalingInZ/ScalingInZ.h main.h
	$(CC) $(CFLAGS) -c ScalingInZ/ScalingInZ.c -o ScalingInZ/ScalingInZ.o

RotationInX/RotationInX.o: RotationInX/RotationInX.c RotationInX/RotationInX.h main.h
	$(CC) $(CFLAGS) -c RotationInX/RotationInX.c -o RotationInX/RotationInX.o

RotationInY/RotationInY.o: RotationInY/RotationInY.c RotationInY/RotationInY.h main.h
	$(CC) $(CFLAGS) -c RotationInY/RotationInY.c -o RotationInY/RotationInY.o

Group8/Group8.o: Group8/Group8.c Group8/Group8.h main.h
	$(CC) $(CFLAGS) -c Group8/Group8.c -o Group8/Group8.o

XYZTranslation/XYZTranslation.o: XYZTranslation/XYZTranslation.c XYZTranslation/XYZTranslation.h main.h
	$(CC) $(CFLAGS) -c XYZTranslation/XYZTranslation.c -o XYZTranslation/XYZTranslation.o

XPlaneReflection/XPlaneReflection.o: XPlaneReflection/XPlaneReflection.c XPlaneReflection/XPlaneReflection.h main.h
	$(CC) $(CFLAGS) -c XPlaneReflection/XPlaneReflection.c -o XPlaneReflection/XPlaneReflection.o

Group11/Group11.o: Group11/Group11.c Group11/Group11.h main.h
	$(CC) $(CFLAGS) -c Group11/Group11.c -o Group11/Group11.o

ZPlaneReflection/ZPlaneReflection.o: ZPlaneReflection/ZPlaneReflection.c ZPlaneReflection/ZPlaneReflection.h main.h
	$(CC) $(CFLAGS) -c ZPlaneReflection/ZPlaneReflection.c -o ZPlaneReflection/ZPlaneReflection.o

Group13/Group13.o: Group13/Group13.c Group13/Group13.h main.h
	$(CC) $(CFLAGS) -c Group13/Group13.c -o Group13/Group13.o

Group14/Group14.o: Group14/Group14.c Group14/Group14.h main.h
	$(CC) $(CFLAGS) -c Group14/Group14.c -o Group14/Group14.o

ShearInZ/ShearInZ.o: ShearInZ/ShearInZ.c ShearInZ/ShearInZ.h main.h
	$(CC) $(CFLAGS) -c ShearInZ/ShearInZ.c -o ShearInZ/ShearInZ.o

xyzOrthographicProjection/xyzOrthographicProjection.o: xyzOrthographicProjection/xyzOrthographicProjection.c xyzOrthographicProjection/xyzOrthographicProjection.h main.h
	$(CC) $(CFLAGS) -c xyzOrthographicProjection/xyzOrthographicProjection.c -o xyzOrthographicProjection/xyzOrthographicProjection.o

OutputResults/OutputResults.o: OutputResults/OutputResults.c OutputResults/OutputResults.h main.h
	$(CC) $(CFLAGS) -c OutputResults/OutputResults.c -o OutputResults/OutputResults.o

#Group Test O Files
Group1/Group1Tests.o: Group1/Group1Tests.c Group1/Group1Tests.h main.h
	$(CC) $(CFLAGS) -c Group1/Group1Tests.c -o Group1/Group1Tests.o

GlobalScaling/GlobalScalingTests.o: GlobalScaling/GlobalScalingTests.c GlobalScaling/GlobalScalingTests.h main.h
	$(CC) $(CFLAGS) -c GlobalScaling/GlobalScalingTests.c -o GlobalScaling/GlobalScalingTests.o

ScalingInX/ScalingInXTests.o: ScalingInX/ScalingInXTests.c ScalingInX/ScalingInXTests.h main.h
	$(CC) $(CFLAGS) -c ScalingInX/ScalingInXTests.c -o ScalingInX/ScalingInXTests.o

ScalingInY/ScalingInYTests.o: ScalingInY/ScalingInYTests.c ScalingInY/ScalingInYTests.h main.h
	$(CC) $(CFLAGS) -c ScalingInY/ScalingInYTests.c -o ScalingInY/ScalingInYTests.o

ScalingInZ/ScalingInZTests.o: ScalingInZ/ScalingInZTests.c ScalingInZ/ScalingInZTests.h main.h
	$(CC) $(CFLAGS) -c ScalingInZ/ScalingInZTests.c -o ScalingInZ/ScalingInZTests.o

RotationInX/RotationInXTests.o: RotationInX/RotationInXTests.c RotationInX/RotationInXTests.h main.h
	$(CC) $(CFLAGS) -c RotationInX/RotationInXTests.c -o RotationInX/RotationInXTests.o

RotationInY/RotationInYTests.o: RotationInY/RotationInYTests.c RotationInY/RotationInYTests.h main.h
	$(CC) $(CFLAGS) -c RotationInY/RotationInYTests.c -o RotationInY/RotationInYTests.o

Group8/Group8Tests.o: Group8/Group8Tests.c Group8/Group8Tests.h main.h
	$(CC) $(CFLAGS) -c Group8/Group8Tests.c -o Group8/Group8Tests.o

XYZTranslation/XYZTranslationTests.o: XYZTranslation/XYZTranslationTests.c XYZTranslation/XYZTranslationTests.h main.h
	$(CC) $(CFLAGS) -c XYZTranslation/XYZTranslationTests.c -o XYZTranslation/XYZTranslationTests.o

XPlaneReflection/XPlaneReflectionTests.o: XPlaneReflection/XPlaneReflectionTests.c XPlaneReflection/XPlaneReflectionTests.h main.h
	$(CC) $(CFLAGS) -c XPlaneReflection/XPlaneReflectionTests.c -o XPlaneReflection/XPlaneReflectionTests.o

Group11/Group11Tests.o: Group11/Group11Tests.c Group11/Group11Tests.h main.h
	$(CC) $(CFLAGS) -c Group11/Group11Tests.c -o Group11/Group11Tests.o

ZPlaneReflection/ZPlaneReflectionTests.o: ZPlaneReflection/ZPlaneReflectionTests.c ZPlaneReflection/ZPlaneReflectionTests.h main.h
	$(CC) $(CFLAGS) -c ZPlaneReflection/ZPlaneReflectionTests.c -o ZPlaneReflection/ZPlaneReflectionTests.o

Group13/Group13Tests.o: Group13/Group13Tests.c Group13/Group13Tests.h main.h
	$(CC) $(CFLAGS) -c Group13/Group13Tests.c -o Group13/Group13Tests.o

Group14/Group14Tests.o: Group14/Group14Tests.c Group14/Group14Tests.h main.h
	$(CC) $(CFLAGS) -c Group14/Group14Tests.c -o Group14/Group14Tests.o

ShearInZ/ShearInZTests.o: ShearInZ/ShearInZTests.c ShearInZ/ShearInZTests.h main.h
	$(CC) $(CFLAGS) -c ShearInZ/ShearInZTests.c -o ShearInZ/ShearInZTests.o

xyzOrthographicProjection/xyzOrthographicProjectionTests.o: xyzOrthographicProjection/xyzOrthographicProjectionTests.c xyzOrthographicProjection/xyzOrthographicProjectionTests.h main.h
	$(CC) $(CFLAGS) -c xyzOrthographicProjection/xyzOrthographicProjectionTests.c -o xyzOrthographicProjection/xyzOrthographicProjectionTests.o

OutputResults/OutputResultsTests.o: OutputResults/OutputResultsTests.c OutputResults/OutputResultsTests.h main.h
	$(CC) $(CFLAGS) -c OutputResults/OutputResultsTests.c -o OutputResults/OutputResultsTests.o
