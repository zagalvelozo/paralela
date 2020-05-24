# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=mpicxx
MXX=mpicxx
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_DISTDIR=dist
CND_BUILDDIR=build


# Object Directory
OBJECTDIR=${CND_BUILDDIR}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/blowfish.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
#DEBUG
#CFLAGS=-Wall -DDEBUG -g3
#Sin Debug
CFLAGS=-Wall -g3

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lssl -lcrypto

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f Makefile ${CND_DISTDIR}/programa

${CND_DISTDIR}/cryptoapp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}
	${LINK.c} -o ${CND_DISTDIR}/programa ${OBJECTFILES} ${LDLIBSOPTIONS} 
	${RM} -fr ${CND_BUILDDIR}
	${RM} -fr core

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	$(CC) $(CFLAGS) -c -o ${OBJECTDIR}/main.o main.cpp
	
	
${OBJECTDIR}/blowfish.o: blowfish.c
	${MKDIR} -p ${OBJECTDIR}
	$(CC) $(CFLAGS) -c -o ${OBJECTDIR}/blowfish.o blowfish.c

# Clean Targets
clean: ${CLEAN_SUBPROJECTS}
	${RM} -fr ${CND_BUILDDIR}
	${RM} -fr ${CND_DISTDIR}
	${RM} -fr core

# Subprojects
.clean-subprojects:


