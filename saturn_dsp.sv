module saturn_dsp (
	input CLOCK,
	
	input [31:0] BUS_DI,
	output [31:0] BUS_DO
);


wire MD0_TO_D0;
wire MD1_TO_D0;
wire MD2_TO_D0;
wire MD3_TO_D0;
wire [31:0] D0_BUS = (MD0_TO_D0) ? MD0_DOUT :
							(MD1_TO_D0) ? MD1_DOUT :
							(MD2_TO_D0) ? MD2_DOUT :
							(MD3_TO_D0) ? MD3_DOUT : 32'h00000000;


wire MD0_TO_D1;
wire MD1_TO_D1;
wire MD2_TO_D1;
wire MD3_TO_D1;
wire [31:0] D1_BUS = (MD0_TO_D1) ? MD0_DOUT :
							(MD1_TO_D1) ? MD1_DOUT :
							(MD2_TO_D1) ? MD2_DOUT :
							(MD3_TO_D1) ? MD3_DOUT : 32'h00000000;


logic [5:0] CT0;
logic [5:0] CT1;
logic [5:0] CT2;
logic [5:0] CT3;


// "RA (W) This is the register that stores the address for accessing the data
// RAM. This register is 8 bit. The RAM designation number (0-3) is
// stored by the high-order 2 bits. The RAM access address is stored in the lower 6 bits."
//
// In other words. Bits [7:6] select one of the four Data RAMs,
// and bits [5:0] select the address within the selected Data RAM. ElectronAsh.
//
logic [7:0] RA;


logic [31:0] RA0;
logic [31:0] WA0;


// Accumulator.
logic [47:0] A_REG;	// The A register ACH(16),ACL(32).


wire [31:0] X_BUS;
wire [31:0] Y_BUS;


logic [31:0] RX;		// Multiplier first input register.
logic [31:0] RY;		// Multiplier second input register.
wire [47:0] MUL_RESULT = RX * RY;	// The multiplier itself...
logic [47:0] P_REG;	// The P register PH(16),PL(32), for latching the multiplier result, and feeding to the ALU "B" input...



// "This is an 8-bit register that stores the lead address. The jump command and
// subroutine execution process store the lead address in this register and executes the process."
logic [7:0] TOP;

// Instruction Fetch register.
wire [31:0] FETCH;


// "This is a 12-bit register that stores the loop counter. The number of
// loops is set by the process of repeating 1 command."
logic [11:0] LOP;


wire [47:0] ALU_RES;
wire S_FLAG;
wire Z_FLAG;
wire C_FLAG;
wire V_FLAG;

alu alu_inst (
	.A_BUS( A_REG ),		// ACH(16),ACL(32).
	.B_BUS( P_REG ),		// PH(16), PL(32).
	
	.OP( FETCH[29:26] ),	// OPERATION.
	
	.RESULT( ALU_RES ),	// Duh.
	
	.S_FLAG( S_FLAG ),
	.Z_FLAG( Z_FLAG ),
	.C_FLAG( C_FLAG ),
	.V_FLAG( V_FLAG )
);



wire [31:0] MD0_DI;
wire [3:0] MD0_BE;
wire MD0_WREN;
wire [31:0] MD0_DOUT;
data_ram	data_ram_md0 (
	.clock ( CLOCK ),
	
	.address ( CT0 ),
	.data ( MD0_DI ),
	.byteena ( MD0_BE ),
	.wren ( MD0_WREN ),
	
	.q ( MD0_DOUT )
);

wire [31:0] MD1_DI;
wire [3:0] MD1_BE;
wire MD1_WREN;
wire [31:0] MD1_DOUT;
data_ram	data_ram_md1 (
	.clock ( CLOCK ),
	
	.address ( CT1 ),
	.data ( MD1_DI ),
	.byteena ( MD1_BE ),
	.wren ( MD1_WREN ),
	
	.q ( MD1_DOUT )
);

wire [31:0] MD2_DI;
wire [3:0] MD2_BE;
wire MD2_WREN;
wire [31:0] MD2_DOUT;
data_ram	data_ram_md2 (
	.clock ( CLOCK ),
	
	.address ( CT2 ),
	.data ( MD2_DI ),
	.byteena ( MD2_BE ),
	.wren ( MD2_WREN ),
	
	.q ( MD2_DOUT )
);

wire [31:0] MD3_DI;
wire [3:0] MD3_BE;
wire MD3_WREN;
wire [31:0] MD3_DOUT;
data_ram	data_ram_md3 (
	.clock ( CLOCK ),
	
	.address ( CT3 ),
	.data ( MD3_DI ),
	.byteena ( MD3_BE ),
	.wren ( MD3_WREN ),
	
	.q ( MD3_DOUT )
);




endmodule


// Early test of an ALU for the Sega Saturn SCU chip.
//
// ElectronAsh. 2018.
//
module alu (
	input [47:0] A_BUS,	// ACH(16),ACL(32).
	input [47:0] B_BUS,	// PH(16), PL(32).
	
	input [3:0] OP,		// OPERATION
	
	output [47:0] RESULT,// Duh.
	
	output S_FLAG,
	output Z_FLAG,
	output C_FLAG,
	output V_FLAG
);


wire [49:0] INT_RES;	// Two extra MSB bits. Bit [49] for checking for Overflow, and bit [48] for the Carry flag.
assign RESULT = INT_RES[47:0];

always_comb begin
	case (OP)
	4'h0: /*INT_RES <= 49'h0000000000000*/;	// NOP. Probably no need to clear the result?
	4'h1: begin
		INT_RES <= A_BUS[31:0] & B_BUS[31:0];	// Bitwise AND (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h2: begin
		INT_RES <= A_BUS[31:0] | B_BUS[31:0];	// Bitwise OR (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h3: begin
		INT_RES <= A_BUS[31:0] ^ B_BUS[31:0];	// Bitwise XOR (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h4: begin
		INT_RES <= A_BUS[31:0] + B_BUS[31:0];	// ADD (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];
	end
	4'h5: begin
		INT_RES <= A_BUS[31:0] - B_BUS[31:0];	// SUB (ACL - PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];	// Not sure how to properly check for Underflow?
	end
	4'h6: begin
		INT_RES <= A_BUS + B_BUS;					// AD2 (ACH:ACL + PH:PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];
	end
	4'h7:;												// Not used?
	4'h8: begin
		INT_RES <= {A_BUS[31], A_BUS[31:1]};	// SR (Shift Right). MSB bit does not change, and the rest of the bits shift right!
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[0];
	end
	4'h9: begin
		INT_RES <= {A_BUS[0], A_BUS[31:1]};		// RR (Rotate Right).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[0];
	end
	4'hA: begin
		INT_RES <= {A_BUS[30:0], 1'b0};			// SL (Shift Left).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	4'hB: begin
		INT_RES <= {A_BUS[30:0], A_BUS[31]};	// RL (Rotate Left).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	4'hC:;												// Not used?
	4'hD:;												// Not used?
	4'hE:;												// Not used?
	4'hF: begin
		INT_RES <= {A_BUS[31:0], 8'h00};			// RL8 (Rotate Left 8 bits).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	endcase
end


endmodule


module instruction_decoder (
	input logic [31:0] FETCH,
	
	output logic D0_TO_CT0,
	output logic D0_TO_CT1,
	output logic D0_TO_CT2,
	output logic D0_TO_CT3,
	
	output logic D1_TO_CT0,
	output logic D1_TO_CT1,
	output logic D1_TO_CT2,
	output logic D1_TO_CT3,

	output logic LOAD_CT0,
	output logic LOAD_CT1,
	output logic LOAD_CT2,
	output logic LOAD_CT3,

	output logic INC_CT0,
	output logic INC_CT1,
	output logic INC_CT2,
	output logic INC_CT3,
	
	output logic MD0_TO_X,
	output logic MD1_TO_X,
	output logic MD2_TO_X,
	output logic MD3_TO_X,
	
	output logic MD0_TO_Y,
	output logic MD1_TO_Y,
	output logic MD2_TO_Y,
	output logic MD3_TO_Y,

	output logic MD0_TO_D1,
	output logic MD1_TO_D1,
	output logic MD2_TO_D1,
	output logic MD3_TO_D1,
	
	output logic D1_TO_MD0,
	output logic D1_TO_MD1,
	output logic D1_TO_MD2,
	output logic D1_TO_MD3,
	
	output logic ACH_TO_D1,
	output logic ACL_TO_D1,
	
	output logic LOAD_MD0,
	output logic LOAD_MD1,
	output logic LOAD_MD2,
	output logic LOAD_MD3,
	
	output logic X_TO_RX,
	output logic D1_TO_RX,
	
	output logic LOAD_RX,
	output logic LOAD_RY,
	
	output logic PC_TO_TOP,
	output logic D1_TO_TOP,
	
	output logic MUL_TO_P,
	output logic X_TO_PL,
	output logic D1_TO_PL,
	
	output logic LOAD_PL,
	
	output logic ALU_TO_ACL,
	output logic Y_TO_ACL,
	
	output logic LOAD_ACH,
	output logic LOAD_ACL,

	output logic IMM_TO_D1,	// I think IMM to "D0" is a typo on the block diagram. ElectronAsh.
	
	output logic IMM_TO_LOP,
	output logic D1_TO_LOP,
	
	output logic PC_TO_D0,

	output logic LOAD_RA,
	output logic RA_TO_RAMS,
	
	output logic SHIFT_L16_TO_D1,
	
	output logic CLR_A,
	
	output logic LOAD_RA0,
	output logic LOAD_WA0,
	
	output logic LOAD_LOP,
	output logic LOAD_TOP,
	
	output logic LOAD_PROG_RAM
);

//
// 31 30 | 29 28 27 26 | 25 24 23 22 21 20 | 19 18 17 16 15 14 | 13 12 11 10 9  8  7  6  5  4  3  2  1  0 
//  0  0   ALU Control     X-Bus Control       Y-Bus Control               D1-Bus Control
//


always_comb begin

	// Defaults...
	D0_TO_CT0 <= 1'b0;
	D0_TO_CT1 <= 1'b0;
	D0_TO_CT2 <= 1'b0;
	D0_TO_CT3 <= 1'b0;
	
	D1_TO_CT0 <= 1'b0;
	D1_TO_CT1 <= 1'b0;
	D1_TO_CT2 <= 1'b0;
	D1_TO_CT3 <= 1'b0;

	LOAD_CT0 <= 1'b0;
	LOAD_CT1 <= 1'b0;
	LOAD_CT2 <= 1'b0;
	LOAD_CT3 <= 1'b0;

	INC_CT0 <= 1'b0;
	INC_CT1 <= 1'b0;
	INC_CT2 <= 1'b0;
	INC_CT3 <= 1'b0;
	
	MD0_TO_X <= 1'b0;
	MD1_TO_X <= 1'b0;
	MD2_TO_X <= 1'b0;
	MD3_TO_X <= 1'b0;
	
	MD0_TO_Y <= 1'b0;
	MD1_TO_Y <= 1'b0;
	MD2_TO_Y <= 1'b0;
	MD3_TO_Y <= 1'b0;
	
	MD0_TO_D1 <= 1'b0;
	MD1_TO_D1 <= 1'b0;
	MD2_TO_D1 <= 1'b0;
	MD3_TO_D1 <= 1'b0;
	
	D1_TO_MD0 <= 1'b0;
	D1_TO_MD1 <= 1'b0;
	D1_TO_MD2 <= 1'b0;
	D1_TO_MD3 <= 1'b0;
	
	ACH_TO_D1 <= 1'b0;
	ACL_TO_D1 <= 1'b0;
	
	LOAD_MD0 <= 1'b0;
	LOAD_MD1 <= 1'b0;
	LOAD_MD2 <= 1'b0;
	LOAD_MD3 <= 1'b0;
	
	X_TO_RX <= 1'b0;
	D1_TO_RX <= 1'b0;
	LOAD_RX <= 1'b0;
	LOAD_RY <= 1'b0;
	
	PC_TO_TOP <= 1'b0;
	D1_TO_TOP <= 1'b0;
	
	P_TO_PL <= 1'b0;
	X_TO_PL <= 1'b0;
	D1_TO_PL <= 1'b0;
	LOAD_PL <= 1'b0;
	
	ALU_TO_ACL <= 1'b0;
	Y_TO_ACL <= 1'b0;

	LOAD_ACH <= 1'b0;
	LOAD_ACL <= 1'b0;

	IMM_TO_D1 <= 1'b0;	// I think IMM to "D0" is a typo on the block diagram. ElectronAsh.
	
	IMM_TO_LOP <= 1'b0;
	D1_TO_LOP <= 1'b0;
	
	PC_TO_D0 <= 1'b0;

	LOAD_RA <= 1'b0;
	RA_TO_RAMS <= 1'b0;
	
	SHIFT_L16_TO_D1 <= 1'b0;
	
	CLR_A <= 1'b0;
	
	LOAD_RA0 <= 1'b0;
	LOAD_WA0 <= 1'b0;

	LOAD_LOP <= 1'b0;
	LOAD_TOP <= 1'b0;
	
	LOAD_PROG_RAM <= 1'b0;

	
	// Handle Operation Commands (non-DMA)...
	if (FETCH[31:30]==2'b00) begin
		// (no need to directly control the ALU, as that's controlled directly by the instruction bits.)
		
		// Handle X-Bus control.
		case (FETCH[25:23]) 
		3'b000:;	// X-Bus NOP.
		
		// Handle MoV [s],X
		3'b100: begin
			case (FETCH[21:20])
			2'b00: begin
				MD0_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT3 <= 1'b1;
			end
			endcase
			
		// Handle MOV MUL,P
		3'b010: begin
			MUL_TO_P <= 1'b1;
		end
		
		// Handle MOV [s],P
		3'b011: begin
			case (FETCH[21:20])
			2'b00: begin
				MD0_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
		end

		
		// Handle Y-Bus control.
		case (FETCH[19:17]) 
		3'b000:;	// Y-Bus NOP.
		
		// Handle MoV [s],Y
		3'b100: begin
			case (FETCH[15:14])
			2'b00: begin
				MD0_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT3 <= 1'b1;
			end
			endcase
			
		// Handle CLR A.
		3'b001: begin
			MUL_TO_P <= 1'b1;
		end
		
		// Handle MOV ALU,A
		3'b010: begin
			ALU_TO_ACL <= 1'b1;
			LOAD_ACH <= 1'b1;
			LOAD_ACL <= 1'b1;
		end
		
		// Handle MOV [s],A
		3'b011: begin
			case (FETCH[15:4])
			2'b00: begin
				MD0_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT3 <= 1'b1;
			end
			endcase
		end
		
		endcase
		
		
		// Handle D1-Bus control.
		case (FETCH[13:12]) 
		2'b00:;	// D1-Bus NOP.
		
		// Handle MOV Simm,[d]
		2'b01: begin		
			case (FETCH[11:8])
			4'b0000: begin				// Imm to DATA RAM0, CT0++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD0 <= 1'b1;
				LOAD_MD0 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0001: begin				// Imm to DATA RAM1, CT1++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD1 <= 1'b1;
				LOAD_MD1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0010: begin				// Imm to DATA RAM2, CT2++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD2 <= 1'b1;
				LOAD_MD2 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0011: begin				// Imm to DATA RAM3, CT3++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD3 <= 1'b1;
				LOAD_MD3 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			4'b0100: begin				// Imm to RX.
				IMM_TO_D1 <= 1'b1;
				D1_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;			
			end
			4'b0101: begin				// Imm to PL.
				IMM_TO_D1 <= 1'b1;
				D1_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;			
			end
			4'b0110: begin				// Imm to RA0.
				IMM_TO_D1 <= 1'b1;
				LOAD_RA0 <= 1'b1;
			end
			4'b0111: begin				// Imm to WA0.
				IMM_TO_D1 <= 1'b1;
				LOAD_WA0 <= 1'b1;
			end
			4'b1000:;					// Unused.
			4'b1001:;					// Unused.
			4'b1010: begin				// Imm to LOP.
				IMM_TO_D1 <= 1'b1;
				LOAD_LOP <= 1'b1;
			end
			4'b1011: begin				// Imm to TOP.
				IMM_TO_D1 <= 1'b1;
				LOAD_TOP <= 1'b1;
			end
			4'b1100: begin				// Imm to CT0.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT0 <= 1'b1;
			end
			4'b1101: begin				// Imm to CT1.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT1 <= 1'b1;
			end
			4'b1110: begin				// Imm to CT2.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT2 <= 1'b1;
			end
			4'b1111: begin				// Imm to CT3.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT3 <= 1'b1;
			end
			endcase
		end
		
		// Handle MOV [s],[d]
		2'b11: begin
		
			// DESTINATION.
			case (FETCH[11:8])
			4'b0000: begin				// Source to DATA RAM0, CT0++
				D1_TO_MD0 <= 1'b1;
				LOAD_MD0 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0001: begin				// Source to DATA RAM1, CT1++
				D1_TO_MD1 <= 1'b1;
				LOAD_MD1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0010: begin				// Source to DATA RAM2, CT2++
				D1_TO_MD2 <= 1'b1;
				LOAD_MD2 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0011: begin				// Source to DATA RAM3, CT3++
				D1_TO_MD3 <= 1'b1;
				LOAD_MD3 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			4'b0100: begin				// Source to RX.
				D1_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;			
			end
			4'b0101: begin				// Source to PL.
				D1_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;			
			end
			4'b0110: begin				// Source to RA0.
				LOAD_RA0 <= 1'b1;
			end
			4'b0111: begin				// Source to WA0.
				LOAD_WA0 <= 1'b1;
			end
			4'b1000:;					// Unused.
			4'b1001:;					// Unused.
			4'b1010: begin				// Source to LOP.
				LOAD_LOP <= 1'b1;
			end
			4'b1011: begin				// Source to TOP.
				LOAD_TOP <= 1'b1;
			end
			4'b1100: begin				// Source to CT0.
				LOAD_CT0 <= 1'b1;
			end
			4'b1101: begin				// Source to CT1.
				LOAD_CT1 <= 1'b1;
			end
			4'b1110: begin				// Source to CT2.
				LOAD_CT2 <= 1'b1;
			end
			4'b1111: begin				// Source to CT3.
				LOAD_CT3 <= 1'b1;
			end
			
			// SOURCE.
			case (FETCH[3:0])
			4'b0000: begin				// Source is MD0.
				MD0_TO_D1 <= 1'b1;
			end
			4'b0001: begin				// Source is MD1.
				MD1_TO_D1 <= 1'b1;
			end
			4'b0010: begin				// Source is MD2.
				MD2_TO_D1 <= 1'b1;
			end
			4'b0011: begin				// Source is MD3.
				MD3_TO_D1 <= 1'b1;
			end
			4'b0100: begin				// Source is MD0. CT0++.
				MD0_TO_D1 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0101: begin				// Source is MD1. CT1++.
				MD1_TO_D1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0110: begin				// Source is MD2. CT2++.
				MD2_TO_D1 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0111: begin				// Source is MD3. CT3++.
				MD3_TO_D1 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			endcase
			4'b1000: ;				// No field.
			4'b1001: begin
				ACL_TO_D1 <= 1'b1;	// ALU Low.
			end
			4'b1010: begin
				ACH_TO_D1 <= 1'b1;	// ALU High.
			end
		end
	end
end


endmodule
