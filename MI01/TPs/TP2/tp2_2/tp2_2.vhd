----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:20:58 10/06/2014 
-- Design Name: 
-- Module Name:    tp2_2 - Behavioral 
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

entity tp2_2 is
	port(PB_0,SW_0: in bit;
		  LED_0 : out bit);	
end tp2_2;

architecture Behavioral of tp2_2 is
begin
	process(PB_0)
	variable nbt : integer range 0 to 5;
	variable allume : bit := '0';
	begin
	if(PB_0'event and PB_0='1') then
		case nbt is
			when 0 =>
				if(SW_0='1') then
					nbt:=1;
				else 
					nbt:=0;
				end if;
			when 1 =>
				if(SW_0='1') then
					nbt:=2;
				else
					nbt:=0;
				end if;
			when 2 =>
				if(SW_0='0') then
					nbt:=3;
				else
					nbt:=0;
				end if;
			when 3 =>
				if (SW_0 ='1') then
					nbt:=4;
				else
					nbt:=0;
				end if;
			when 4 =>
				nbt:=0;
				if(SW_0='0') then
				nbt:=5;
					allume := '1';
				else
					nbt:=0;
				end if;
			when 5 =>
				nbt:=0;
				allume:='0';
			end case;
			LED_0<=allume;
		end if;
	end process;				
end Behavioral;

