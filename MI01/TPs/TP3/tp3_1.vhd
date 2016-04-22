----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:43:18 10/13/2014 
-- Design Name: 
-- Module Name:    tp3_1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity blinker is
	port(Clk100MHz, PB_0 : in bit;
	LED_0 : out bit);
end blinker;

architecture clock of blinker is
	alias reset is PB_0; -- alias pour le signal de r�initialisation
	signal clk_out : bit := '0'; -- signal d'horloge apr�s division
	-- Constante de division, ici pour une sortie � 1Hz.
	constant clock_divisor : integer := 100000000;
	begin
	-- Diviseur de fr�quence : divise la fr�quence du signal Clk100MHz par clock_div.
	clock_divider : process(Clk100Mhz, reset)
	variable c : integer range 0 to clock_divisor - 1 := 0;
	begin
	if reset = '1' then
		c := 0;
		clk_out <= '0';
	elsif Clk100MHz'event and Clk100MHz = '1' then
		if c < (clock_divisor - 1) / 2 then
			c := c + 1;
			clk_out <= '0';
		elsif c = (clock_divisor - 1) then
			c := 0;
			clk_out <= '0';
		else
			c := c + 1;
			clk_out <= '1';
		end if;
	end if;
	end process;

	-- Sortie sur la LED
	LED_0 <= clk_out;
end clock;



