/* 
  Checks If Process Is Protected 
  Fun Fact Protected Process If Terminated You BSOD With StopCode Critical_Process_Died 
*/

bool __fastcall PsIsProtectedProcess(_EPROCESS* eproc)
{
  return (*(BYTE*)(eproc + 0x87A) & 7) != 0;  //  +0x87a Protection: _PS_PROTECTION Ands with 7 and returns true if its 1 and not equal to zero 
  
  /*
    IDA:
          test    byte ptr [rcx+87Ah], 7      ; rcx = _EPROCESS 
          mov     eax, 0
          setnbe  al      ; Set byte to 1 if not below zero or equal to zero if the byte is set the result is true the process is protected ! 
          retn
  */ 
}