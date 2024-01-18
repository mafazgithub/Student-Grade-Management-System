IDENTIFICATION DIVISION.
PROGRAM-ID. CalculateGrades.

DATA DIVISION.
FILE SECTION.
FD Student-File
   RECORD CONTAINS 80 CHARACTERS
   DATA RECORD IS Student-Data.

01 Student-Data.
   05 Student-Name    PIC X(50).
   05 Student-Grade   PIC 999.

WORKING-STORAGE SECTION.
01 Total-Grade         PIC 999 VALUE 0.
01 Total-Students      PIC 999 VALUE 0.
01 Average-Grade       PIC 999.

PROCEDURE DIVISION.
OPEN INPUT Student-File.
PERFORM UNTIL EOF
   READ Student-File INTO Student-Data
      AT END SET EOF TO TRUE
      NOT AT END
         ADD Student-Grade TO Total-Grade
         ADD 1 TO Total-Students
   END-READ
END-PERFORM.

IF Total-Students NOT EQUAL TO ZERO
   COMPUTE Average-Grade = Total-Grade / Total-Students
END-IF.

CLOSE Student-File.
