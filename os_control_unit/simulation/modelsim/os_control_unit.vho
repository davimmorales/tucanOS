-- Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus Prime License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 15.1.0 Build 185 10/21/2015 SJ Lite Edition"

-- DATE "11/03/2017 17:23:26"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	os_control_unit IS
    PORT (
	CLOCK : IN std_logic;
	BIOS_INSTRUCTION_OPCODE : IN std_logic_vector(5 DOWNTO 0);
	instruction_selection : OUT std_logic
	);
END os_control_unit;

-- Design Ports Information
-- instruction_selection	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[0]	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[1]	=>  Location: PIN_G6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[2]	=>  Location: PIN_E3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[3]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[5]	=>  Location: PIN_D2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIOS_INSTRUCTION_OPCODE[4]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLOCK	=>  Location: PIN_H7,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF os_control_unit IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_CLOCK : std_logic;
SIGNAL ww_BIOS_INSTRUCTION_OPCODE : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_instruction_selection : std_logic;
SIGNAL \instruction_selection~output_o\ : std_logic;
SIGNAL \CLOCK~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[5]~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[4]~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[2]~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[3]~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[0]~input_o\ : std_logic;
SIGNAL \BIOS_INSTRUCTION_OPCODE[1]~input_o\ : std_logic;
SIGNAL \Equal0~0_combout\ : std_logic;
SIGNAL \CONTROL_STATE~0_combout\ : std_logic;
SIGNAL \CONTROL_STATE~q\ : std_logic;

BEGIN

ww_CLOCK <= CLOCK;
ww_BIOS_INSTRUCTION_OPCODE <= BIOS_INSTRUCTION_OPCODE;
instruction_selection <= ww_instruction_selection;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y69_N9
\instruction_selection~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \CONTROL_STATE~q\,
	devoe => ww_devoe,
	o => \instruction_selection~output_o\);

-- Location: IOIBUF_X0_Y68_N15
\CLOCK~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLOCK,
	o => \CLOCK~input_o\);

-- Location: IOIBUF_X0_Y68_N1
\BIOS_INSTRUCTION_OPCODE[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(5),
	o => \BIOS_INSTRUCTION_OPCODE[5]~input_o\);

-- Location: IOIBUF_X0_Y68_N8
\BIOS_INSTRUCTION_OPCODE[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(4),
	o => \BIOS_INSTRUCTION_OPCODE[4]~input_o\);

-- Location: IOIBUF_X0_Y66_N15
\BIOS_INSTRUCTION_OPCODE[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(2),
	o => \BIOS_INSTRUCTION_OPCODE[2]~input_o\);

-- Location: IOIBUF_X0_Y66_N22
\BIOS_INSTRUCTION_OPCODE[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(3),
	o => \BIOS_INSTRUCTION_OPCODE[3]~input_o\);

-- Location: IOIBUF_X0_Y65_N15
\BIOS_INSTRUCTION_OPCODE[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(0),
	o => \BIOS_INSTRUCTION_OPCODE[0]~input_o\);

-- Location: IOIBUF_X0_Y67_N15
\BIOS_INSTRUCTION_OPCODE[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIOS_INSTRUCTION_OPCODE(1),
	o => \BIOS_INSTRUCTION_OPCODE[1]~input_o\);

-- Location: LCCOMB_X1_Y66_N16
\Equal0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Equal0~0_combout\ = (\BIOS_INSTRUCTION_OPCODE[2]~input_o\ & (!\BIOS_INSTRUCTION_OPCODE[3]~input_o\ & (\BIOS_INSTRUCTION_OPCODE[0]~input_o\ & \BIOS_INSTRUCTION_OPCODE[1]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \BIOS_INSTRUCTION_OPCODE[2]~input_o\,
	datab => \BIOS_INSTRUCTION_OPCODE[3]~input_o\,
	datac => \BIOS_INSTRUCTION_OPCODE[0]~input_o\,
	datad => \BIOS_INSTRUCTION_OPCODE[1]~input_o\,
	combout => \Equal0~0_combout\);

-- Location: LCCOMB_X1_Y68_N0
\CONTROL_STATE~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \CONTROL_STATE~0_combout\ = (\CONTROL_STATE~q\) # ((\BIOS_INSTRUCTION_OPCODE[5]~input_o\ & (!\BIOS_INSTRUCTION_OPCODE[4]~input_o\ & \Equal0~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \BIOS_INSTRUCTION_OPCODE[5]~input_o\,
	datab => \BIOS_INSTRUCTION_OPCODE[4]~input_o\,
	datac => \CONTROL_STATE~q\,
	datad => \Equal0~0_combout\,
	combout => \CONTROL_STATE~0_combout\);

-- Location: FF_X1_Y68_N1
CONTROL_STATE : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLOCK~input_o\,
	d => \CONTROL_STATE~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \CONTROL_STATE~q\);

ww_instruction_selection <= \instruction_selection~output_o\;
END structure;


