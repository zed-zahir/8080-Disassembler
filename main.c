#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main( int argc, char **argv ) {

  if( argc != 3 ) {
    printf("you have to type <file> <number of line to disassemble>\n");
    exit(1);
  }

  int pc = 0;
  unsigned char buff[4096];

  int f = open( argv[1], O_RDONLY );

  read( f, buff, sizeof(buff) );

  printf("pc\tbyte\t\t instruction\n");
  printf("=================================\n");

  for( pc = 0; pc < atoi(argv[2]); pc++ ) {

    switch(buff[pc]) {
      case 0x00:
	printf("%#04x;\t0x00\t\t NOP\n", pc);
	pc += 1;
	break;
      case 0x01:
	printf("%#04x:\t0x01\t\t LXI B, D16\n", pc);
	pc += 3;
	break;
      case 0x02:
	printf("%#04x:\t0x02\t\t STAX B\n", pc);
	pc += 1;
	break;
      case 0x03:
	printf("%#04x:\t0x03\t\t INX B\n", pc);
	pc += 1;
	break;
      case 0x04:
	printf("%#04x:\t0x04\t\t INR B\n", pc);
	pc += 1;
	break;
      case 0x05:
	printf("%#04x:\t0x05\t\t DCR B, D8\n", pc);
	pc += 2;
	break;
      case 0x06:
	printf("%#04x:\t0x06\t\t MVI B, D8\n", pc);
	pc += 1;
	break;
      case 0x07:
	printf("%#04x:\t0x07\t\t RLC\n", pc);
	pc += 1;
	break;
      case 0x08:
	printf("%#04x:\t0x08\t\t -\n", pc);
	pc += 1;
	break;
      case 0x09:
	printf("%#04x:\t0x09\t\t DAD B\n", pc);
	pc += 1;
	break;
      case 0x0A:
	printf("%#04x:\t0x0A\t\t LDAX B\n", pc);
	pc += 1;
	break;
      case 0x0B:
	printf("%#04x:\t0x0B\t\t DCX B\n", pc);
	pc += 1;
	break;
      case 0x0C:
	printf("%#04x:\t0x0C\t\t INR C\n", pc);
	pc += 2;
	break;
      case 0x0D:
	printf("%#04x:\t0x0D\t\t DCR C\n", pc);
	pc += 1;
	break;
      case 0x0E:
	printf("%#04x:\t0x0E\t\t MVI C, D8\n", pc);
	pc += 1;
	break;
      case 0x0F:
	printf("%#04x:\t0x0F\t\t RRC\n", pc);
	pc += 3;
	break;
      case 0x10:
	printf("%#04x:\t0x10\t\t -\n", pc);
	pc += 1;
	break;
      case 0x11:
	printf("%#04x:\t0x11\t\t LXI D, D16\n", pc);
	pc += 3;
	break;
      case 0x12:
	printf("%#04x:\t0x12\t\t STAX D\n", pc);
	pc += 1;
	break;
      case 0x13:
	printf("%#04x:\t0x13\t\t INX D\n", pc);
	pc += 1;
	break;
      case 0x14:
	printf("%#04x:\t0x14\t\t INR D\n", pc);
	pc += 1;
	break;
      case 0x15:
	printf("%#04x:\t0x15\t\t DCR D\n", pc);
	pc += 1;
	break;
      case 0x16:
	printf("%#04x:\t0x16\t\t MVI D, D8\n", pc);
	pc += 2;
	break;
      case 0x17:
	printf("%#04x:\t0x17\t\t RAL\n", pc);
	pc += 1;
	break;
      case 0x18:
	printf("%#04x:\t0x18\t\t - \n", pc);
	pc += 1;
	break;
      case 0x19:
	printf("%#04x:\t0x19\t\t DAD D\n", pc);
	pc += 1;
	break;
      case 0x1A:
	printf("%#04x:\t0x1A\t\t LDAX D\n", pc);
	pc += 1;
	break;
      case 0x1B:
	printf("%#04x:\t0x1B\t\t DCX D\n", pc);
	pc += 1;
	break;
      case 0x1C:
	printf("%#04x:\t0x1C\t\t INR E\n", pc);
	pc += 1;
	break;
      case 0x1D:
	printf("%#04x:\t0x1D\t\t DCR E\n", pc);
	pc += 1;
	break;
      case 0x1E:
	printf("%#04x:\t0x1E\t\t MVI E, D8\n", pc);
	pc += 2;
	break;
      case 0x1F:
	printf("%#04x:\t0x1F\t\t RAR\n", pc);
	pc += 1;
	break;
      case 0x20:
	printf("%#04x:\t0x20\t\t - \n", pc);
	pc += 1;
	break;
      case 0x21:
	printf("%#04x:\t0x21\t\t LXI H, D16\n", pc);
	pc += 3;
	break;
      case 0x22:
	printf("%#04x:\t0x22 0x%x%x\t SHLD 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0x23:
	printf("%#04x:\t0x23\t\t INX H\n", pc);
	pc += 1;
	break;
      case 0x24:
	printf("%#04x:\t0x24\t\t INR H\n", pc);
	pc += 1;
	break;
      case 0x25:
	printf("%#04x:\t0x25\t\t DCR H\n", pc);
	pc += 1;
	break;
      case 0x26:
	printf("%#04x:\t0x26\t\t MVI H, D8\n", pc);
	pc += 2;
	break;
      case 0x27:
	printf("%#04x:\t0x27\t\t DAA\n", pc);
	pc += 1;
	break;
      case 0x28:
	printf("%#04x:\t0x28\t\t - \n", pc);
	pc += 1;
	break;
      case 0x29:
	printf("%#04x:\t0x29\t\t DAD H\n", pc);
	pc += 1;
	break;
      case 0x2A:
	printf("%#04x:\t0x2A 0x%x%x\t LHLD 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc+1] | buff[pc+2] << 8 );
	pc += 3;
	break;
      case 0x2B:
	printf("%#04x:\t0x2B\t\t DCX H\n", pc);
	pc += 1;
	break;
      case 0x2C:
	printf("%#04x:\t0x2C\t\t DCX H\n", pc);
	pc += 1;
	break;
      case 0x2D:
	printf("%#04x:\t0x2D\t\t INR L\n", pc);
	pc += 1;
	break;
      case 0x2E:
	printf("%#04x:\t0x2E\t\t MVI L, D8\n", pc);
	pc += 2;
	break;
      case 0x2F:
	printf("%#04x:\t0x2F\t\t CMA\n", pc);
	pc += 1;
	break;
      case 0x30:
	printf("%#04x:\t0x30\t\t - \n", pc);
	pc += 1;
	break;
      case 0x31:
	printf("%#04x:\t0x31\t\t LXI SP, D16\n", pc);
	pc += 3;
	break;
      case 0x32:
	printf("%#04x:\t0x32 0x%x%x\t STA 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0x33:
	printf("%#04x:\t0x33\t\t INX SP\n", pc);
	pc += 1;
	break;
      case 0x34:
	printf("%#04x:\t0x34\t\t INR M\n", pc);
	pc += 1;
	break;
      case 0x35:
	printf("%#04x:\t0x35\t\t DCR M\n", pc);
	pc += 1;
	break;
      case 0x36:
	printf("%#04x:\t0x36\t\t MVI M, D8 \n", pc);
	pc += 1;
	break;
      case 0x37:
	printf("%#04x:\t0x37\t\t STC \n", pc);
	pc += 1;
	break;
      case 0x38:
	printf("%#04x:\t0x38\t\t - \n ", pc);
	pc += 1;
	break;
      case 0x39:
	printf("%#04x:\t0x39\t\t DAD SP \n", pc);
	pc += 1;
	break;
      case 0x3A:
	printf("%#04x:\t0x3A 0x%x%x\t LDA 0x%x \n", pc,buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0x3B:
	printf("%#04x:\t0x3B\t\t DCX SP \n", pc);
	pc += 1;
	break;
      case 0x3C:
	printf("%#04x:\t0x3C\t\t INR A\n", pc);
	pc += 1;
	break;
      case 0x3D:
	printf("%#04x:\t0x3D\t\t DCR A\n", pc);
	pc += 1;
	break;
      case 0x3E:
	printf("%#04x:\t0x3E\t\t MVI A, D8\n", pc);
	pc += 2;
	break;
      case 0x3F:
	printf("%#04x:\t0x3F\t\t CMC \n", pc);
	pc += 1;
	break;
      case 0x40:
	printf("%#04x:\t0x40\t\t MOV B, B\n", pc);
	pc += 1;
	break;
      case 0x41:
	printf("%#04x:\t0x41\t\t MOV B, C\n", pc);
	pc += 1;
	break;
      case 0x42:
	printf("%#04x:\t0x42\t\t MOV B, D\n", pc);
	pc += 1;
	break;
      case 0x43:
	printf("%#04x:\t0x43\t\t MOV B, E\n", pc);
	pc += 1;
	break;
      case 0x44:
	printf("%#04x:\t0x44\t\t MOV B, H\n", pc);
	pc += 1;
	break;
      case 0x45:
	printf("%#04x:\t0x45\t\t MOV B, L\n", pc);
	pc += 1;
	break;
      case 0x46:
	printf("%#04x:\t0x46\t\t MOV B, M\n", pc);
	pc += 1;
	break;
      case 0x47:
	printf("%#04x:\t0x47\t\t MOV B, A\n", pc);
	pc += 1;
	break;
      case 0x48:
	printf("%#04x:\t0x48\t\t MOV C, B\n", pc);
	pc += 1;
	break;
      case 0x49:
	printf("%#04x:\t0x49\t\t MOV C, C\n", pc);
	pc += 1;
	break;
      case 0x4A:
	printf("%#04x:\t0x4A\t\t MOV C, D\n", pc);
	pc += 1;
	break;
      case 0x4B:
	printf("%#04x:\t0x4B\t\t MOV C, E\n", pc);
	pc += 1;
	break;
      case 0x4C:
	printf("%#04x:\t0x4C\t\t MOV C, H\n", pc);
	pc += 1;
	break;
      case 0x4D:
	printf("%#04x:\t0x4D\t\t MOV C, L\n", pc);
	pc += 1;
	break;
      case 0x4E:
	printf("%#04x:\t0x4E\t\t MOV C, M\n", pc);
	pc += 1;
	break;
      case 0x4F:
	printf("%#04x:\t0x4F\t\t MOV C, A\n", pc);
	pc += 1;
	break;
      case 0x50:
	printf("%#04x:\t0x50\t\t MOV D, B\n", pc);
	pc += 1;
	break;
      case 0x51:
	printf("%#04x:\t0x51\t\t MOV D, C\n", pc);
	pc += 1;
	break;
      case 0x52:
	printf("%#04x:\t0x52\t\t MOV D, D\n", pc);
	pc += 1;
	break;
      case 0x53:
	printf("%#04x:\t0x53\t\t MOV D, E\n", pc);
	pc += 1;
	break;
      case 0x54:
	printf("%#04x:\t0x54\t\t MOV D, H\n", pc);
	pc += 1;
	break;
      case 0x55:
	printf("%#04x:\t0x55\t\t MOV D, L\n", pc);
	pc += 1;
	break;
      case 0x56:
	printf("%#04x:\t0x56\t\t MOV D, M\n", pc);
	pc += 1;
	break;
      case 0x57:
	printf("%#04x:\t0x57\t\t MOV D, A\n", pc);
	pc += 1;
	break;
      case 0x58:
	printf("%#04x:\t0x58\t\t MOV E, B\n", pc);
	pc += 1;
	break;
      case 0x59:
	printf("%#04x:\t0x59\t\t MOV E, C\n", pc);
	pc += 1;
	break;
      case 0x5A:
	printf("%#04x:\t0x5A\t\t MOV E, D\n", pc);
	pc += 1;
	break;
      case 0x5B:
	printf("%#04x:\t0x5B\t\t MOV E, E\n", pc);
	pc += 1;
	break;
      case 0x5C:
	printf("%#04x:\t0x5C\t\t MOV E, H\n", pc);
	pc += 1;
	break;
      case 0x5D:
	printf("%#04x:\t0x5D\t\t MOV E, L\n", pc);
	pc += 1;
	break;
      case 0x5E:
	printf("%#04x:\t0x5E\t\t MOV E, M\n", pc);
	pc += 1;
	break;
      case 0x5F:
	printf("%#04x:\t0x5F\t\t MOV E, A\n", pc);
	pc += 1;
	break;
      case 0x60:
	printf("%#04x:\t0x60\t\t MOV H, B\n", pc);
	pc += 1;
	break;
      case 0x61:
	printf("%#04x:\t0x61\t\t MOV H, C\n", pc);
	pc += 1;
	break;
      case 0x62:
	printf("%#04x:\t0x62\t\t MOV H, D\n", pc);
	pc += 1;
	break;
      case 0x63:
	printf("%#04x:\t0x63\t\t MOV H, E\n", pc);
	pc += 1;
	break;
      case 0x64:
	printf("%#04x:\t0x64\t\t MOV H, H\n", pc);
	pc += 1;
	break;
      case 0x65:
	printf("%#04x:\t0x65\t\t MOV H, L\n", pc);
	pc += 1;
	break;
      case 0x66:
	printf("%#04x:\t0x66\t\t MOV H, M\n ", pc);
	pc += 1;
	break;
      case 0x67:
	printf("%#04x:\t0x67\t\t MOV H, A\n", pc);
	pc += 1;
	break;
      case 0x68:
	printf("%#04x:\t0x68\t\t MOV L, B\n", pc);
	pc += 1;
	break;
      case 0x69:
	printf("%#04x:\t0x69\t\t MOV L, C\n", pc);
	pc += 1;
	break;
      case 0x6A:
	printf("%#04x:\t0x6A\t\t MOV L, D\n", pc);
	pc += 1;
	break;
      case 0x6B:
	printf("%#04x:\t0x6B\t\t MOV L, E\n ", pc);
	pc += 1;
	break;
      case 0x6C:
	printf("%#04x:\t0x6C\t\t MOV L, H\n", pc);
	pc += 1;
	break;
      case 0x6D:
	printf("%#04x:\t0x6D\t\t MOV L, L\n", pc);
	pc += 1;
	break;
      case 0x6E:
	printf("%#04x:\t0x6E\t\t MOV, L, M\n", pc);
	pc += 1;
	break;
      case 0x6F:
	printf("%#04x:\t0x6F\t\t MOV L, A\n", pc);
	pc += 1;
	break;
      case 0x70:
	printf("%#04x:\t0x70\t\t MOV M, B\n", pc);
	pc += 1;
	break;
      case 0x71:
	printf("%#04x:\t0x71\t\t MOV M, C\n", pc);
	pc += 1;
	break;
      case 0x72:
	printf("%#04x:\t0x72\t\t MOV M, D\n", pc);
	pc += 1;
	break;
      case 0x73:
	printf("%#04x:\t0x73\t\t MOV M, E\n", pc);
	pc += 1;
	break;
      case 0x74:
	printf("%#04x:\t0x74\t\t MOV M, H\n", pc);
	pc += 1;
	break;
      case 0x75:
	printf("%#04x:\t0x75\t\t MOV M, L\n", pc);
	pc += 1;
	break;
      case 0x76:
	printf("%#04x:\t0x76\t\t HLT\n", pc);
	pc += 1;
	break;
      case 0x77:
	printf("%#04x:\t0x77\t\t MOV M, A\n", pc);
	pc += 1;
	break;
      case 0x78:
	printf("%#04x:\t0x78\t\t MOV A, B\n", pc);
	pc += 1;
	break;
      case 0x79:
	printf("%#04x:\t0x79\t\t MOV A, C\n", pc);
	pc += 1;
	break;
      case 0x7A:
	printf("%#04x:\t0x7A\t\t MOV A, D\n", pc);
	pc += 1;
	break;
      case 0x7B:
	printf("%#04x:\t0x7B\t\t MOV A, E\n", pc);
	pc += 1;
	break;
      case 0x7C:
	printf("%#04x:\t0x7C\t\t MOV A, H\n", pc);
	pc += 1;
	break;
      case 0x7D:
	printf("%#04x:\t0x7D\t\t MOV A, L\n", pc);
	pc += 1;
	break;
      case 0x7E:
	printf("%#04x:\t0x7E\t\t MOV A, M\n", pc);
	pc += 1;
	break;
      case 0x7F:
	printf("%#04x:\t0x7F\t\t MOV A, A\n", pc);
	pc += 1;
	break;
      case 0x80:
	printf("%#04x:\t0x80\t\t ADD B\n", pc);
	pc += 1;
	break;
      case 0x81:
	printf("%#04x:\t0x81\t\t ADD C\n", pc);
	pc += 1;
	break;
      case 0x82:
	printf("%#04x:\t0x82\t\t ADD D\n", pc);
	pc += 1;
	break;
      case 0x83:
	printf("%#04x:\t0x83\t\t ADD E\n", pc);
	pc += 1;
	break;
      case 0x84:
	printf("%#04x:\t0x84\t\t ADD H\n", pc);
	pc += 1;
	break;
      case 0x85:
	printf("%#04x:\t0x85\t\t ADD L\n", pc);
	pc += 1;
	break;
      case 0x86:
	printf("%#04x:\t0x86\t\t ADD M\n", pc);
	pc += 1;
	break;
      case 0x87:
	printf("%#04x:\t0x87\t\t ADD A\n", pc);
	pc += 1;
	break;
      case 0x88:
	printf("%#04x:\t0x88\t\t ADC B\n", pc);
	pc += 1;
	break;
      case 0x89:
	printf("%#04x:\t0x89\t\t ADC C\n", pc);
	pc += 1;
	break;
      case 0x8A:
	printf("%#04x:\t0x8A\t\t ADC D\n", pc);
	pc += 1;
	break;
      case 0x8B:
	printf("%#04x:\t0x8B\t\t ADC E\n", pc);
	pc += 1;
	break;
      case 0x8C:
	printf("%#04x:\t0x8C\t\t ADC H\n", pc);
	pc += 1;
	break;
      case 0x8D:
	printf("%#04x:\t0x8D\t\t ADC L\n", pc);
	pc += 1;
	break;
      case 0x8E:
	printf("%#04x:\t0x8E\t\t ADC M\n", pc);
	pc += 1;
	break;
      case 0x8F:
	printf("%#04x:\t0x8F\t\t ADC A\n", pc);
	pc += 1;
	break;
      case 0x90:
	printf("%#04x:\t0x90\t\t SUB B\n", pc);
	pc += 1;
	break;
      case 0x91:
	printf("%#04x:\t0x91\t\t SUB C\n", pc);
	pc += 1;
	break;
      case 0x92:
	printf("%#04x:\t0x92\t\t SUB D\n ", pc);
	pc += 1;
	break;
      case 0x93:
	printf("%#04x:\t0x93\t\t SUB E\n", pc);
	pc += 1;
	break;
      case 0x94:
	printf("%#04x:\t0x94\t\t SUB H\n", pc);
	pc += 1;
	break;
      case 0x95:
	printf("%#04x:\t0x95\t\t SUB L\n", pc);
	pc += 1;
	break;
      case 0x96:
	printf("%#04x:\t0x96\t\t SUB M\n", pc);
	pc += 1;
	break;
      case 0x97:
	printf("%#04x:\t0x97\t\t SUB A\n", pc);
	pc += 1;
	break;
      case 0x98:
	printf("%#04x:\t0x98\t\t SBB B\n", pc);
	pc += 1;
	break;
      case 0x99:
	printf("%#04x:\t0x99\t\t SBB C\n", pc);
	pc += 1;
	break;
      case 0x9A:
	printf("%#04x:\t0x9A\t\t SBB D\n", pc);
	pc += 1;
	break;
      case 0x9B:
	printf("%#04x:\t0x9B\t\t SBB E\n", pc);
	pc += 1;
	break;
      case 0x9C:
	printf("%#04x:\t0x9C\t\t SBB H\n", pc);
	pc += 1;
	break;
      case 0x9D:
	printf("%#04x:\t0x9D\t\t SBB L\n ", pc);
	pc += 1;
	break;
      case 0x9E:
	printf("%#04x:\t0x9E\t\t SBB M\n", pc);
	pc += 1;
	break;
      case 0x9F:
	printf("%#04x:\t0x9F\t\t SBB A\n", pc);
	pc += 1;
	break;
      case 0xA0:
	printf("%#04x:\t0xA0\t\t ANA B\n", pc);
	pc += 1;
	break;
      case 0xA1:
	printf("%#04x:\t0xA1\t\t ANA C\n ", pc);
	pc += 1;
	break;
      case 0xA2:
	printf("%#04x:\t0xA2\t\t ANA D\n", pc);
	pc += 1;
	break;
      case 0xA3:
	printf("%#04x:\t0xA3\t\t ANA E\n", pc);
	pc += 1;
	break;
      case 0xA4:
	printf("%#04x:\t0xA4\t\t ANA H\n", pc);
	pc += 1;
	break;
      case 0xA5:
	printf("%#04x:\t0xA5\t\t ANA L\n", pc);
	pc += 1;
	break;
      case 0xA6:
	printf("%#04x:\t0xA6\t\t ANA M\n ", pc);
	pc += 1;
	break;
      case 0xA7:
	printf("%#04x:\t0xA7\t\t ANA A\n", pc);
	pc += 1;
	break;
      case 0xA8:
	printf("%#04x:\t0xA8\t\t XRA B\n", pc);
	pc += 1;
	break;
      case 0xA9:
	printf("%#04x:\t0xA9\t\t XRA C\n", pc);
	pc += 1;
	break;
      case 0xAA:
	printf("%#04x:\t0xAA\t\t XRA D\n", pc);
	pc += 1;
	break;
      case 0xAB:
	printf("%#04x:\t0xAB\t\t XRA E\n", pc);
	pc += 1;
	break;
      case 0xAC:
	printf("%#04x:\t0xAC\t\t XRA H\n", pc);
	pc += 1;
	break;
      case 0xAD:
	printf("%#04x:\t0xAD\t\t XRA L\n", pc);
	pc += 1;
	break;
      case 0xAE:
	printf("%#04x:\t0xAE\t\t XRA M\n", pc);
	pc += 1;
	break;
      case 0xAF:
	printf("%#04x:\t0xAF\t\t XRA A\n", pc);
	pc += 1;
	break;
      case 0xB0:
	printf("%#04x:\t0xB0\t\t ORA B\n", pc);
	pc += 1;
	break;
      case 0xB1:
	printf("%#04x:\t0xB1\t\t ORA C\n ", pc);
	pc += 1;
	break;
      case 0xB2:
	printf("%#04x:\t0xB2\t\t ORA D\n", pc);
	pc += 1;
	break;
      case 0xB3:
	printf("%#04x:\t0xB3\t\t ORA E\n", pc);
	pc += 1;
	break;
      case 0xB4:
	printf("%#04x:\t0xB4\t\t ORA H\n", pc);
	pc += 1;
	break;
      case 0xB5:
	printf("%#04x:\t0xB5\t\t ORA L\n", pc);
	pc += 1;
	break;
      case 0xB6:
	printf("%#04x:\t0xB6\t\t ORA M\n", pc);
	pc += 1;
	break;
      case 0xB7:
	printf("%#04x:\t0xB7\t\t ORA A\n", pc);
	pc += 1;
	break;
      case 0xB8:
	printf("%#04x:\t0xB8\t\t CMP B\n", pc);
	pc += 1;
	break;
      case 0xB9:
	printf("%#04x:\t0xB9\t\t CMP C\n", pc);
	pc += 1;
	break;
      case 0xBA:
	printf("%#04x:\t0xBA\t\t CMP D\n", pc);
	pc += 1;
	break;
      case 0xBB:
	printf("%#04x:\t0xBB\t\t CMP E\n", pc);
	pc += 1;
	break;
      case 0xBC:
	printf("%#04x:\t0xBC\t\t CMP H\n", pc);
	pc += 1;
	break;
      case 0xBD:
	printf("%#04x:\t0xBD\t\t CMP L\n", pc);
	pc += 1;
	break;
      case 0xBE:
	printf("%#04x:\t0xBE\t\t CMP M\n", pc);
	pc += 1;
	break;
      case 0xBF:
	printf("%#04x:\t0xBF\t\t CMP A\n", pc);
	pc += 1;
	break;
      case 0xC0:
	printf("%#04x:\t0xC0\t\t RNZ\n", pc);
	pc += 1;
	break;
      case 0xC1:
	printf("%#04x:\t0xC1\t\t POP B\n", pc);
	pc += 1;
	break;
      case 0xC2:
	printf("%#04x:\t0xC2 0x%x%x\t JNZ 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xC3:
	printf("%#04x:\t0xC3 0x%x%x\t JMP 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xC4:
	printf("%#04x:\t0xC4 0x%x%x\t CNZ 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xC5:
	printf("%#04x:\t0xC5\t\t PUSH B\n", pc);
	pc += 1;
	break;
      case 0xC6:
	printf("%#04x:\t0xC6\t\t ADI D8\n", pc);
	pc += 2;
	break;
      case 0xC7:
	printf("%#04x:\t0xC7\t\t RST 0\n", pc);
	pc += 1;
	break;
      case 0xC8:
	printf("%#04x:\t0xC8\t\t RZ\n", pc);
	pc += 1;
	break;
      case 0xC9:
	printf("%#04x:\t0xC9\t\t RET\n", pc);
	pc += 3;
	break;
      case 0xCA:
	printf("%#04x:\t0xCA 0x%x%x\t JZ 0x%x\n", pc,buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xCB:
	printf("%#04x:\t0xCB\t\t - \n", pc);
	pc += 1;
	break;
      case 0xCC:
	printf("%#04x:\t0xCC 0x%x%x\t CZ 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xCD:
	printf("%#04x:\t0xCD 0x%x%x\t CALL 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xCE:
	printf("%#04x:\t0xCE\t\t ACI D8\n", pc);
	pc += 2;
	break;
      case 0xCF:
	printf("%#04x:\t0xCF\t\t RST 1\n", pc);
	pc += 1;
	break;
      case 0xD0:
	printf("%#04x:\t0xD0\t\t RNC\n", pc);
	pc += 1;
	break;
      case 0xD1:
	printf("%#04x:\t0xD1\t\t POP D\n", pc);
	pc += 1;
	break;
      case 0xD2:
	printf("%#04x:\t0xD2 0x%x%x\t JNC 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xD3:
	printf("%#04x:\t0xD3\t\ŧ OUT D8\n", pc);
	pc += 2;
	break;
      case 0xD4:
	printf("%#04x:\t0xD4 0x%x%x\t CNC 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xD5:
	printf("%#04x:\t0xD5\t\t PUSH D\n", pc);
	pc += 1;
	break;
      case 0xD6:
	printf("%#04x:\t0xD6\t\t SUI D8\n", pc);
	pc += 2;
	break;
      case 0xD7:
	printf("%#04x:\t0xD7\t\t RST 2\n", pc);
	pc += 1;
	break;
      case 0xD8:
	printf("%#04x:\t0xD8\t\t RC\n", pc);
	pc += 1;
	break;
      case 0xD9:
	printf("%#04x:\t0xD9\t\ŧ -\n", pc);
	pc += 1;
	break;
      case 0xDA:
	printf("%#04x:\t0xDA 0x%x%x\t JC 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xDB:
	printf("%#04x:\t0xDB\t\t IN D8\n", pc);
	pc += 2;
	break;
      case 0xDC:
	printf("%#04x:\t0xDC 0x%x%x\t CC 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xDE:
	printf("%#04x:\t0xDE\t\t -\n", pc);
	pc += 1;
	break;
      case 0xDF:
	printf("%#04x:\t0xDF\t\t RST 3\n", pc);
	pc += 3;
	break;
      case 0xE0:
	printf("%#04x:\t0xE0\t\t RPO\n", pc);
	pc += 1;
	break;
      case 0xE1:
	printf("%#04x:\t0xE1\t\t POP H\n", pc);
	pc += 1;
	break;
      case 0xE2:
	printf("%#04x:\t0xE2 0x%x%x\t JPO 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xE3:
	printf("%#04x:\t0xE3\t\t XTHL\n", pc);
	pc += 1;
	break;
      case 0xE4:
	printf("%#04x:\t0xE4 0x%x%x\t CPO %x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xE5:
	printf("%#04x:\t0xE5\t\t PUSH H\n", pc);
	pc += 1;
	break;
      case 0xE6:
	printf("%#04x:\t0xE6\t\t ANI D8\n", pc);
	pc += 2;
	break;
      case 0xE7:
	printf("%#04x:\t0xE7\t\t RST 4\n", pc);
	pc += 1;
	break;
      case 0xE8:
	printf("%#04x:\t0xE8\t\t RPE\n", pc);
	pc += 1;
	break;
      case 0xE9:
	printf("%#04x:\t0xE9\t\t PCHL\n", pc);
	pc += 1;
	break;
      case 0xEA:
	printf("%#04x:\t0xEA 0x%x%x\t JPE 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xEB:
	printf("%#04x:\t0xEB\t\t XCHG\n", pc);
	pc += 1;
	break;
      case 0xEC:
	printf("%#04x:\t0xEC 0x%x%x\t CPE 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xED:
	printf("%#04x:\t0xED\t\t -\n", pc);
	pc += 1;
	break;
      case 0xEE:
	printf("%#04x:\t0xEE\t\t XRI D8\n", pc);
	pc += 2;
	break;
      case 0xEF:
	printf("%#04x:\t0xEF\t\t RST 5\n", pc);
	pc += 1;
	break;
      case 0xF0:
	printf("%#04x:\t0xF0\t\t RP\n", pc);
	pc += 1;
	break;
      case 0xF1:
	printf("%#04x:\t0xF1\t\t POP PSW\n", pc);
	pc += 1;
	break;
      case 0xF2:
	printf("%#04x:\t0xF2 0x%x%x\t JP 0x%x\n ", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xF3:
	printf("%#04x:\t0xF3\t\t DI\n", pc);
	pc += 1;
	break;
      case 0xF4:
	printf("%#04x:\t0xF4 0x%x%x\t CP 0x%x\n ", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xF5:
	printf("%#04x:\t0xF5\t\t PUSH PSW\n", pc);
	pc += 1;
	break;
      case 0xF6:
	printf("%#04x:\t0xF6\t\t ORI D8\n", pc);
	pc += 2;
	break;
      case 0xF7:
	printf("%#04x:\t0xF7\t\t RST 6\n", pc);
	pc += 1;
	break;
      case 0xF8:
	printf("%#04x:\t0xF8\t\t RM\n", pc);
	pc += 1;
	break;
      case 0xF9:
	printf("%#04x:\t0xF9\t\t SPHL\n", pc);
	pc += 1;
	break;
      case 0xFA:
	printf("%#04x:\t0xFA 0x%x%x\t JM 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xFB:
	printf("%#04x:\t0xFB\t\t EI\n", pc);
	pc += 1;
	break;
      case 0xFC:
	printf("%#04x:\t0xFC 0x%x%x\t CM 0x%x\n", pc, buff[pc + 1], buff[pc + 2], buff[pc + 1] | buff[pc + 2] << 8);
	pc += 3;
	break;
      case 0xFD:
	printf("%#04x:\t0xFD\t\t -\n", pc);
	pc += 1;
	break;
      case 0xFE:
	printf("%#04x:\t0xFE\t\t CPI D8\n", pc);
	pc += 2;
	break;
      case 0xFF:
	printf("%#04x:\t0xFF\t\t RST 7\n", pc);
	pc += 1;
	break;
      default:
	printf("\t\t\tunknown instruction\n");
	break;
    }
  }

  return 0;
}
