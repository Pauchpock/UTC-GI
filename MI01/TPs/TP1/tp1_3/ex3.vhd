----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:24:39 09/29/2014 
-- Design Name: 
-- Module Name:    ex3 - Behavioral 
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

entity ex3 is
	PORT( SW_10, SW_32 : in integer range 0 to 3;
			SW_4, SW_5 : in BIT;
				LED_10 : out integer range 0 to 3 );
end ex3;

architecture Behavioral of ex3 is

begin
	LED_10 <= SW_10 + SW_32 WHEN SW_4 = '0' AND SW_5 = '0' else
			    SW_32 - SW_10 WHEN SW_4 = '1' AND SW_5 = '0' else
	          SW_10 * SW_32 WHEN SW_4 = '0' AND SW_5 = '1' else
				 0;
end Behavioral;

