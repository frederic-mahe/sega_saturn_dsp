#include "Vsaturn_dsp.h"
#include "verilated.h"
#include "vga_out.h"

#if VM_TRACE
#include "verilated_vcd_c.h"
#endif

unsigned int rom_size = 256;	// 256 Words (32-bit wide).
uint32_t *rom_ptr = (uint32_t *) malloc(rom_size);

int main_time;

int hcount = 0;
int vcount = 0;


int main(int argc, char **argv, char **env)
{
	// Half cycles
	vluint64_t hcycle = 0;
	vluint8_t hclkcnt = 0;

	// VGA output
	int vga_clk;
	int vga_hs;
	int vga_vs;
	int vga_r;
	int vga_g;
	int vga_b;

	Verilated::commandArgs(argc, argv);

	// Init top verilog instance
	Vsaturn_dsp* top = new Vsaturn_dsp;

	// Init VGA output C++ model
	// VgaOut* vga = new VgaOut(1, 24, HS_POS_POL|VS_POS_POL, 0, 2000, 0, 1000, "snapshot");
	VgaOut* vga = new VgaOut(0, 24, 1, 0, 1280, 0, 720, "snapshot");

	FILE *romfile;
	romfile = fopen("sonicr_intro_dsp.bin","r");
	if (romfile!=NULL) {
		printf("\nDSP Program RAM file loaded OK.\n");
	}
	else {
		printf("\nDSP Program RAM file not found!\n\n");
		return 0;
	};

	unsigned int file_size;
	fseek(romfile, 0L, SEEK_END);
	file_size = ftell(romfile);
	fseek(romfile, 0L, SEEK_SET);
	
	fread(rom_ptr, 1, file_size, romfile);	// Read the whole ROM file into RAM.
	
	
	//while (!Verilated::gotFinish()) {
	while ( main_time < 20 ) {		// Only run for a short time.
		if (main_time < 8) {
			//top->reset_n = 0;		// Assert reset
		}
		if (main_time == 10) {
			//top->reset_n = 1;   	// Deassert reset
		}
		if ((main_time & 1) == 1) {
			top->CLOCK = 1;
			//top->pix_clk = 1;       // Toggle clock
			//top->sys_clk = 1;
		}
		if ((main_time & 1) == 0) {
			top->CLOCK = 0;
			//top->pix_clk = 0;
			//top->sys_clk = 0;

			uint32_t byte_swap;
			
			if (top->INST_ADDR < rom_size) {
				byte_swap = (rom_ptr[top->INST_ADDR]&0xFF000000)>>24 |
							(rom_ptr[top->INST_ADDR]&0x00FF0000)>>8 |
							(rom_ptr[top->INST_ADDR]&0x0000FF00)<<8 |
							(rom_ptr[top->INST_ADDR]&0x000000FF)<<24;
							
				top->INST_IN = byte_swap;
			}
			
			printf("ADDR:  %08x      ", top->INST_ADDR-1);
			printf("FETCH: %08x      ", top->FETCH);
			
			// Operational Instruction...
			if ( (top->FETCH&0xF0000000)>>28 == 0x0 ) {
				uint16_t alu_op 	= ((top->FETCH&0x3C000000)>>26)&0xF;
				uint16_t xbus_op 	= ((top->FETCH&0x03F00000)>>20)&0x3F;
				uint16_t ybus_op 	= ((top->FETCH&0x000FC000)>>24)&0x3F;
				uint16_t d1bus_op 	= ((top->FETCH&0x00003FFF)>>0)&0x3FFF;

				printf("ALU_OP:  %02x   ", alu_op);
				printf("XBUS_OP: %02x   ", xbus_op);
				printf("YBUS_OP: %02x   ", ybus_op);
				printf("D1_OP:   %04x   ", d1bus_op);
				
				// Control signals...
				if (top->MD0_TO_X)   printf("MD0_TO_X,  ");
				if (top->MD1_TO_X)   printf("MD1_TO_X,  ");
				if (top->MD2_TO_X)   printf("MD2_TO_X,  ");
				if (top->MD3_TO_X)   printf("MD3_TO_X,  ");

				if (top->MD0_TO_Y)   printf("MD0_TO_Y,  ");
				if (top->MD1_TO_Y)   printf("MD1_TO_Y,  ");
				if (top->MD2_TO_Y)   printf("MD2_TO_Y,  ");
				if (top->MD3_TO_Y)   printf("MD3_TO_Y,  ");

				if (top->MD0_TO_D1)  printf("MD0_TO_D1, ");
				if (top->MD1_TO_D1)  printf("MD1_TO_D1, ");
				if (top->MD2_TO_D1)  printf("MD2_TO_D1, ");
				if (top->MD3_TO_D1)  printf("MD3_TO_D1, ");

				if (top->D1_TO_MD0)  printf("D1_TO_MD0, ");
				if (top->D1_TO_MD1)  printf("D1_TO_MD1, ");
				if (top->D1_TO_MD2)  printf("D1_TO_MD2, ");
				if (top->D1_TO_MD3)  printf("D1_TO_MD3, ");

				if (top->ACH_TO_D1)  printf("ACH_TO_D1, ");
				if (top->ACL_TO_D1)  printf("ACL_TO_D1, ");

				if (top->X_TO_RX)    printf("X_TO_RX, ");
				if (top->D1_TO_RX)   printf("D1_TO_RX, ");

				if (top->LOAD_RX)    printf("LOAD_RX, ");
				if (top->LOAD_RY)    printf("LOAD_RY, ");

				if (top->PC_TO_TOP)  printf("PC_TO_TOP, ");
				if (top->D1_TO_TOP)  printf("D1_TO_TOP, ");

				if (top->MUL_TO_P)   printf("MUL_TO_P, ");
				if (top->P_TO_PL)    printf("P_TO_PL, ");
				if (top->X_TO_PL)    printf("X_TO_PL, ");
				if (top->D1_TO_PL)   printf("D1_TO_PL, ");

				if (top->LOAD_PL)    printf("LOAD_PL, ");

				if (top->ALU_TO_A)   printf("ALU_TO_A, ");
				if (top->Y_TO_ACL)   printf("Y_TO_ACL, ");

				if (top->LOAD_ACH)   printf("LOAD_ACH, ");
				if (top->LOAD_ACL)   printf("LOAD_ACL, ");

				if (top->IMM_TO_D1)  printf("IMM_TO_D1, ");

				if (top->IMM_TO_LOP) printf("IMM_TO_LOP, ");
				if (top->D1_TO_LOP)  printf("D1_TO_LOP, ");

				if (top->PC_TO_D0)   printf("PC_TO_D0, ");

				if (top->RA_TO_RAMS) printf("RA_TO_RAMS, ");

				if (top->SHIFT_L16_TO_D1) printf("SHFT_L16_TO_D1,");

				if (top->CLR_A)      printf("CLR_A, ");

				if (top->LOAD_CT0)   printf("LOAD_CT0,  ");
				if (top->LOAD_CT1)   printf("LOAD_CT1,  ");
				if (top->LOAD_CT2)   printf("LOAD_CT2,  ");
				if (top->LOAD_CT3)   printf("LOAD_CT3,  ");
				
				if (top->LOAD_MD0)   printf("LOAD_MD0, ");
				if (top->LOAD_MD1)   printf("LOAD_MD1, ");
				if (top->LOAD_MD2)   printf("LOAD_MD2, ");
				if (top->LOAD_MD3)   printf("LOAD_MD3, ");
				
				if (top->LOAD_RA)    printf("LOAD_RA,  ");

				if (top->LOAD_RA0)   printf("LOAD_RA0, ");
				if (top->LOAD_WA0)   printf("LOAD_WA0, ");

				if (top->LOAD_LOP)   printf("LOAD_LOP, ");
				if (top->LOAD_TOP)   printf("LOAD_TOP, ");

				if (top->LOAD_PROG_RAM) printf("LOAD_PROG_RAM, ");

				if (top->INC_CT0)    printf("INC_CT0,   ");
				if (top->INC_CT1)    printf("INC_CT1,   ");
				if (top->INC_CT2)    printf("INC_CT2,   ");
				if (top->INC_CT3)    printf("INC_CT3,   ");
				
				printf("\n");

				printf("P_REG: %012x  ", top->P_REG);
				printf("A_REG: %012x  ", top->A_REG);
				
				switch (alu_op) {
					case 0x0: printf("NOP           "); break;
					case 0x1: printf("AND           "); break;
					case 0x2: printf("OR            "); break;
					case 0x3: printf("XOR           "); break;
					case 0x4: printf("ADD           "); break;
					case 0x5: printf("SUB           "); break;
					case 0x6: printf("AD2           "); break;
					case 0x7: break;
					case 0x8: printf("SR            "); break;
					case 0x9: printf("RR            "); break;
					case 0xA: printf("SL            "); break;
					case 0xB: printf("RL            "); break;
					case 0xC: break;
					case 0xD: break;
					case 0xE: break;
					case 0xF: printf("RL8           "); break;
				}
				
				switch (xbus_op&0x38) {
					case 0x0: printf("NOP           "); break;
					case 0x1: break;
					case 0x2: printf("MOV MUL,P     "); break;
					case 0x3: {
						switch (xbus_op&0x7) {
							case 0x0: printf("MOV M0,PL     "); break;
							case 0x1: printf("MOV M1,PL     "); break;
							case 0x2: printf("MOV M2,PL     "); break;
							case 0x3: printf("MOV M3,PL     "); break;
							case 0x4: printf("MOV MC0,PL    "); break;
							case 0x5: printf("MOV MC1,PL    "); break;
							case 0x6: printf("MOV MC2,PL    "); break;
							case 0x7: printf("MOV MC3,PL    "); break;
						}
					}
					case 0x4: {
						switch (xbus_op&0x7) {
							case 0x0: printf("MOV M0,X      "); break;
							case 0x1: printf("MOV M1,X      "); break;
							case 0x2: printf("MOV M2,X      "); break;
							case 0x3: printf("MOV M3,X      "); break;
							case 0x4: printf("MOV MC0,X     "); break;
							case 0x5: printf("MOV MC1,X     "); break;
							case 0x6: printf("MOV MC2,X     "); break;
							case 0x7: printf("MOV MC3,X     "); break;
						}
					}
					default: break;
				}
				
				switch (ybus_op&0x38) {
					case 0x0: printf("NOP           "); break;
					case 0x1: printf("CLR A         "); break;
					case 0x2: printf("MOV ALU,A     "); break;
					case 0x3: {
						switch (xbus_op&0x7) {
							case 0x0: printf("MOV M0,ACL    "); break;
							case 0x1: printf("MOV M1,ACL    "); break;
							case 0x2: printf("MOV M2,ACL    "); break;
							case 0x3: printf("MOV M3,ACL    "); break;
							case 0x4: printf("MOV MC0,ACL   "); break;
							case 0x5: printf("MOV MC1,ACL   "); break;
							case 0x6: printf("MOV MC2,ACL   "); break;
							case 0x7: printf("MOV MC3,ACL   "); break;
						}
					}
					case 0x4: {
						switch (xbus_op&0x7) {
							case 0x0: printf("MOV M0,Y      "); break;
							case 0x1: printf("MOV M1,Y      "); break;
							case 0x2: printf("MOV M2,Y      "); break;
							case 0x3: printf("MOV M3,Y      "); break;
							case 0x4: printf("MOV MC0,Y     "); break;
							case 0x5: printf("MOV MC1,Y     "); break;
							case 0x6: printf("MOV MC2,Y     "); break;
							case 0x7: printf("MOV MC3,Y     "); break;
						}
					}
					default: break;
				}
				
				
				switch ( (d1bus_op&0x3000)>>12) {
					case 0x0: printf("NOP           "); break;
					case 0x1: {
						printf("MOV #$%02x,", d1bus_op&0xFF);
						switch ( (d1bus_op&0xF00)>>8 ) {
							case 0x0: printf("MC0  "); break;
							case 0x1: printf("MC1  "); break;
							case 0x2: printf("MC2  "); break;
							case 0x3: printf("MC3  "); break;
							case 0x4: printf("RX   "); break;
							case 0x5: printf("PL   "); break;
							case 0x6: printf("RA0  "); break;
							case 0x7: printf("WA0  "); break;
							case 0x8: break;
							case 0x9: break;
							case 0xA: printf("LOP  "); break;
							case 0xB: printf("TOP  "); break;
							case 0xC: printf("CT0  "); break;
							case 0xD: printf("CT1  "); break;
							case 0xE: printf("CT2  "); break;
							case 0xF: printf("CT3  "); break;
						}
					}
					case 0x2: break;
					case 0x3: {
						switch ( d1bus_op&0xF ) {
							// Source...
							case 0x0: printf("MOV M0,"); break;
							case 0x1: printf("MOV M1,"); break;
							case 0x2: printf("MOV M2,"); break;
							case 0x3: printf("MOV M3,"); break;
							case 0x4: printf("MOV MC0,"); break;
							case 0x5: printf("MOV MC1,"); break;
							case 0x6: printf("MOV MC2,"); break;
							case 0x7: printf("MOV MC3,"); break;
							case 0x8: printf("MOV NF!,"); break;break;
							case 0x9: printf("MOV ALL,"); break;
							case 0xA: printf("MOV ALH,"); break;
							case 0xB: break;
							case 0xC: break;
							case 0xD: break;
							case 0xE: break;
							case 0xF: break;
						}
						switch ( (d1bus_op&0xF00)>>8 ) {
							// Destination...
							case 0x0: printf("MC0  "); break;
							case 0x1: printf("MC1  "); break;
							case 0x2: printf("MC2  "); break;
							case 0x3: printf("MC3  "); break;
							case 0x4: printf("RX   "); break;
							case 0x5: printf("PL   "); break;
							case 0x6: printf("RA0  "); break;
							case 0x7: printf("WA0  "); break;
							case 0x8: break;
							case 0x9: break;
							case 0xA: printf("LOP  "); break;
							case 0xB: printf("TOP  "); break;
							case 0xC: printf("CT0  "); break;
							case 0xD: printf("CT1  "); break;
							case 0xE: printf("CT2  "); break;
							case 0xF: printf("CT3  "); break;
						}
					}
					default: break;
				}

			}	
			
			// DMA Instruction...
			if ( (top->FETCH&0xF0000000)>>28 == 0xC ) {
				bool dma_format = (top->FETCH&0x00002000)>>13;
				printf("DMA");
				if (dma_format==0) {
					printf("1: ");	// DMA format 1.
					uint8_t dma_add_mode = (top->FETCH&0x00038000)>>15;
					uint8_t dma_data_ram = (top->FETCH&0x00000300)>>8;
					printf("ADD_MODE: %d  ", dma_add_mode);
					printf("DATA_RAM_ADDR: %d", dma_data_ram);
				}
				else {
					printf("2: ");	// DMA format 2.
					uint8_t dma_add_mode = (top->FETCH&0x00038000)>>15;
					uint8_t dma_data_ram = (top->FETCH&0x00000300)>>8;
					printf("ADD_MODE: %d  ", dma_add_mode);
					printf("DATA_RAM_ADDR: %d", dma_data_ram);
				}
				printf("\n");
			}
			
			// JUMP Instruction...
			if ( (top->FETCH&0xF0000000)>>28 == 0xD ) {
				printf("JMP ");
				if ( (top->FETCH&0x03F80000)==0x03080000) printf("Z,  #$");
				if ( (top->FETCH&0x03F80000)==0x02080000) printf("NZ, #$");
				if ( (top->FETCH&0x03F80000)==0x03100000) printf("S,  #$");
				if ( (top->FETCH&0x03F80000)==0x02100000) printf("NS, #$");
				if ( (top->FETCH&0x03F80000)==0x03200000) printf("C,  #$");
				if ( (top->FETCH&0x03F80000)==0x02200000) printf("NC, #$");
				if ( (top->FETCH&0x03F80000)==0x03400000) printf("T0, #$");
				if ( (top->FETCH&0x03F80000)==0x02400000) printf("NT0,#$");
				if ( (top->FETCH&0x03F80000)==0x03180000) printf("ZS, #$");
				if ( (top->FETCH&0x03F80000)==0x02180000) printf("NZS,#$");
				printf("%02x", top->FETCH&0xFF);
				printf("\n");
			}
			
			// LOOP BOTTOM Command...
			if ( (top->FETCH&0xF0000000)>>28 == 0xE ) {
				if ( (top->FETCH&0x08000000)>>27 == 0 ) printf("BTM    ");
				else printf("LPS    ");
				printf("\n");
			}
			
			printf("\n");

			printf("D1BUS: %08x      ", top->D1_BUS);
			printf("CT0: %02x  ", top->CT0);
			printf("CT1: %02x  ", top->CT1);
			printf("CT2: %02x  ", top->CT2);
			printf("CT3: %02x  ", top->CT3);			
						
			printf("\n\n");
		
					
			if (vga_clk==1) {
				if (hcount<1648) {
					hcount++;	
				}
				else {
					hcount = 0;
					if (vcount<750) vcount ++;
					else vcount = 0;
				}

				if (hcount==0) vga_hs = 1;
				else vga_hs = 0;

				if (vcount==0) {
					vga_vs = 1;
					//printf("main_time: %08d  hcount: %08d  vcount: %08d\n", main_time, hcount, vcount);
				}
				else vga_vs = 0;
			}
				
			/*
			top->horbeam = hcount;
			top->verbeam = vcount;
			top->hsync = vga_hs;
			top->vsync = vga_vs;
			*/
			
			vga_clk	= top->CLOCK;
			//vga_vs    = top->vga_vs_n;
			//vga_hs    = top->vga_hs_n;
			//vga_r     = (top->rgb_out&0xFF0000)>>16;
			//vga_g     = (top->rgb_out&0x00FF00)>>8;
			//vga_b     = (top->rgb_out&0x0000FF)>>0;
			
			vga->eval (hcycle / 2,
					   vga_clk, vga_vs, vga_hs,
					   vga_r, vga_g, vga_b);

			hcycle++;
			
			hclkcnt++;
			//top->sys_clk = (hclkcnt & 1) == 1;
			//top->pix_clk = (hclkcnt % 3) == 2;
		}
		
		top->eval();            // Evaluate model!
		
		main_time++;            // Time passes...
	}
	top->final();
	
	delete top;
    exit(0);
}