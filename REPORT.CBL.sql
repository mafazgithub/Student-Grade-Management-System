IDENTIFICATION DIVISION.
PROGRAM-ID. GenerateReport.

DATA DIVISION.
FILE SECTION.
FD Student-File
   RECORD CONTAINS 80 CHARACTERS
   DATA RECORD IS Student-Data.

01 Student-Data.
   05 Student-Name    PIC X(50).
   05 Student-Grade   PIC 999.

PROCEDURE DIVISION.
OPEN INPUT Student-File.
DISPLAY '***** Student Grade Report *****'.
DISPLAY 'Student Name        Grade'.
PERFORM UNTIL EOF
   READ Student-File INTO Student-Data
      AT END SET EOF TO TRUE
      NOT AT END
         DISPLAY Student-Name '     ' Student-Grade
   END-READ
END-PERFORM.

CLOSE Student-File.
