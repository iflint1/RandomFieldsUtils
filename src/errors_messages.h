

/*
 Authors 
 Martin Schlather, schlather@math.uni-mannheim.de


 Copyright (C) 2015 -- 2021 Martin Schlather

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  
*/


// Datei wi

#ifndef rfutils_error_H
#define rfutils_error_H 1


#define NOERROR 0                 
#define ERRORMEMORYALLOCATION 1 
#define ERRORFAILED 2      /* method didn't work for the specified parameters */
#define ERRORNOTPROGRAMMEDYET 3
#define ERRORM 4          /* a single error message */
#define ERRORMEND 12      /* a single error message -- und alles dazwischen */
 


#ifdef SCHLATHERS_MACHINE
#define ERRLINE PRINTF("(ERROR in %s, line %d)\n", __FILE__, __LINE__)
#else
#define ERRLINE 
#endif

#ifndef ERR
  #define ERR ERR0
#endif


#define ERR0(X) {ERRLINE; RFERROR("%s", X);}
#define ERR00(X) ERRLINE; errorstring_type E_AUX;
#define ERR1(X,Y) {ERR00(X);SPRINTF(E_AUX,X,Y); RFERROR("%s", E_AUX);}
#define ERR2(X,Y,Z) {ERR00(X);SPRINTF(E_AUX,X,Y,Z); RFERROR("%s", E_AUX);}
#define ERR3(X,Y,Z,A) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A); RFERROR("%s", E_AUX);}
#define ERR4(X,Y,Z,A,B) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A,B); RFERROR("%s", E_AUX);}
#define ERR5(X,Y,Z,A,B,C) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A,B,C); RFERROR("%s", E_AUX);}
#define ERR6(X,Y,Z,A,B,C,D) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A,B,C,D); RFERROR("%s", E_AUX);}
#define ERR7(X,Y,Z,A,B,C,D,E) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A,B,C,D,E); RFERROR("%s", E_AUX);}
#define ERR8(X,Y,Z,A,B,C,D,E,F) {ERR00(X);SPRINTF(E_AUX,X,Y,Z,A,B,C,D,E,F); RFERROR("%s", E_AUX);}



#ifndef LOCAL_ERRORSTRING
  #define LOCAL_ERRORSTRING errorstring_type loc_errorstring
#endif
#ifndef WHICH_ERRORSTRING 
  #define WHICH_ERRORSTRING loc_errorstring
#endif
#define FERR0(X) LOCAL_ERRORSTRING; \
  STRNCPY(WHICH_ERRORSTRING, X, MAXERRORSTRING); DEBUGINFOERR
#if ! defined FERR
  #define FERR FERR0
#endif
#define FERR1(X,Y) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING, X, Y); DEBUGINFOERR
#define FERR2(X,Y,Z) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING, X, Y, Z); DEBUGINFOERR
#define FERR3(X,Y,Z,A) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING, X, Y, Z, A); DEBUGINFOERR
#define FERR4(X,Y,Z,A,B) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING,X,Y,Z,A,B); DEBUGINFOERR
#define FERR5(X,Y,Z,A,B,C) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING,X,Y,Z,A,B,C); DEBUGINFOERR 
#define FERR6(X,Y,Z,A,B,C,D) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING,X,Y,Z,A,B,C,D); DEBUGINFOERR 
#define FERR7(X,Y,Z,A,B,C,D,E) LOCAL_ERRORSTRING; \
  SPRINTF(WHICH_ERRORSTRING,X,Y,Z,A,B,C,D,E); DEBUGINFOERR


#ifndef LOCAL_ERROR
  #define LOCAL_ERROR(N) {}
#endif
#define NERR00(N) LOCAL_ERROR(N); return N;
#define NERR0(N,X) { FERR0(X); NERR00(N)}
#if ! defined NERR
  #define NERR NERR0
#endif
#define NERR1(N,X,Y) { FERR1(X, Y); NERR00(N)}
#define NERR2(N,X, Y, Z) { FERR2(X, Y, Z); NERR00(N)}
#define NERR3(N,X, Y, Z, A) { FERR3(X, Y, Z, A); NERR00(N)}
#define NERR4(N,X, Y, Z, A, B) { FERR4(X, Y, Z, A, B); NERR00(N)}
#define NERR5(N,X, Y, Z, A, B, C) { FERR5(X, Y, Z, A, B, C); NERR00(N)}
#define NERR6(N,X, Y, Z, A, B, C, D) { FERR6(X, Y, Z, A,B,C,D); NERR00(N)}
#define NERR7(N,X,Y,Z, A, B, C, D, E) { FERR7(X,Y,Z,A,B,C,D,E); NERR00(N)}

#define SERR0(X) NERR0(ERRORM, X)
#if ! defined SERR
  #define SERR SERR0
#endif
#define SERR1(X,Y) NERR1(ERRORM, X, Y)
#define SERR2(X,Y,Z) NERR2(ERRORM, X, Y, Z)
#define SERR3(X,Y,Z, A) NERR3(ERRORM, X, Y, Z, A)
#define SERR4(X,Y,Z, A, B) NERR4(ERRORM, X, Y, Z, A, B)
#define SERR5(X,Y,Z, A, B, C) NERR5(ERRORM, X, Y, Z, A, B, C)
#define SERR6(X,Y,Z, A, B, C, D) NERR6(ERRORM, X, Y, Z, A, B, C, D)
#define SERR7(X,Y,Z, A, B, C, D, E) NERR7(ERRORM, X, Y, Z, A, B, C, D, E)

#define CERR00 err=ERRORM; continue;
#define CERR0(X) { FERR0(X); CERR00}
#if ! defined CERR
  #define CERR CERR0
#endif
#define CERR1(X,Y) { FERR1(X, Y); CERR00}
#define CERR2(X, Y, Z) { FERR2(X, Y, Z);  CERR00}
#define CERR3(X, Y, Z, A) { FERR3(X, Y, Z, A); CERR00}


#define GERR00 LOCAL_ERROR(ERRORM); err = ERRORM; goto ErrorHandling;
#define GERR0(X) {FERR0(X); GERR00}
#if ! defined GERR
  #define GERR GERR0
#endif
#define GERR1(X,Y) {FERR1(X,Y); GERR00}
#define GERR2(X,Y,Z) {FERR2(X,Y,Z); GERR00}
#define GERR3(X,Y,Z,A) {FERR3(X,Y,Z,A); GERR00}
#define GERR4(X,Y,Z,A,B) {FERR4(X,Y,Z,A,B); GERR00}
#define GERR5(X,Y,Z,A,B,C) {FERR5(X,Y,Z,A,B,C); GERR00}
#define GERR6(X,Y,Z,A,B,C,D) {FERR6(X,Y,Z,A,B,C,D); GERR00}

#define GNERR00(N) err = N; goto ErrorHandling;
#define GNERR0(N,X) {FERR0(X); GNERR00(N)}
#if ! defined GNERR
  #define GNERR GNERR0
#endif
#define GNERR1(N,X,Y) {FERR1(X,Y);GNERR00(N)}
#define GNERR2(N,X,Y,Z) {FERR2(X,Y,Z); GNERR00(N)}
#define GNERR3(N,X,Y,Z,A) {FERR3(X,Y,Z,A); GNERR00(N)}
#define GNERR4(N,X,Y,Z,A,B) {FERR4(X,Y,Z,A,B); GNERR00(N)}
#define GNERR5(N,X,Y,Z,A,B,C) {FERR5(X,Y,Z,A,B,C); GNERR00(N)}
#define GNERR6(N,X,Y,Z,A,B,C,D) {FERR6(X,Y,Z,A,B,C,D); GNERR00(N)}

#define RFWARNING warning
#define WARN0(X) RFWARNING("%s", X)
#define WARN1(X, Y) {errorstring_type  W_MSG; \
    SPRINTF(W_MSG, X, Y); RFWARNING("%s", W_MSG);}
#define WARN2(X, Y, Z) {errorstring_type  W_MSG; \
    SPRINTF(W_MSG, X, Y, Z); RFWARNING("%s", W_MSG);}
#define WARN3(X, Y, Z, A) {errorstring_type  W_MSG;\
    SPRINTF(W_MSG, X, Y, Z, A); RFWARNING("%s", W_MSG);}
#define WARN4(X, Y, Z, A, B) {errorstring_type  W_MSG;	\
    SPRINTF(W_MSG, X, Y, Z, A, B); RFWARNING("%s", W_MSG);}
#define WARN5(X, Y, Z, A, B, C) {errorstring_type  W_MSG;	\
    SPRINTF(W_MSG, X, Y, Z, A, B, C); RFWARNING("%s", W_MSG);}
#define WARN6(X, Y, Z, A, B,C,D) {errorstring_type  W_MSG;	\
    SPRINTF(W_MSG, X, Y, Z, A, B, C, D); RFWARNING("%s", W_MSG);}
#define WARN7(X, Y, Z,A,B,C,D,E) {errorstring_type  W_MSG;	\
    SPRINTF(W_MSG, X, Y, Z, A, B, C, D, E); RFWARNING("%s", W_MSG);}



#endif
