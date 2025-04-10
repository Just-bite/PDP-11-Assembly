START:  MOV #42, R0
        ADD (R1)+, R2
LOOP:   CMP R0, R2
        BNE LOOP
        HALT