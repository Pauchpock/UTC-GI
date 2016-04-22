----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:45:13 10/06/2014 
-- Design Name: 
-- Module Name:    tp2_1 - Behavioral 
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

entity tp2_1 is
	PORT(LED_10 : out integer range 0 to 3; 
		  PB_0 : in bit;
		  PB_1 : in bit); 
end tp2_1;

architecture Behavioral of tp2_1 is
begin
	process(PB_0,PB_1) -- le synthétiseur se fiche de ce qui est entre parenthèses
	variable i : integer range 0 to 3 := 0;
	begin
		if (PB_1 = '1') then
			i := 0;
		elsif(PB_0'event AND PB_0='1') then
			i := i + 1;
		end if;
		LED_10 <= i;
	end process;
end Behavioral;

