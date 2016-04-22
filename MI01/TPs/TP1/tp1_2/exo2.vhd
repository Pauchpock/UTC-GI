----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:48:30 09/29/2014 
-- Design Name: 
-- Module Name:    exo2 - Behavioral 
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

entity exo2 is
		PORT( SW_10, SW_32 : in integer range 0 to 3;
				LED_10 : out integer range 0 to 3 );
end exo2;
architecture Behavioral of exo2 is
begin
	LED_10 <= SW_10 + SW_32;
end Behavioral;

