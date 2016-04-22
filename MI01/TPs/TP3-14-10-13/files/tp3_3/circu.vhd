----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:10:48 10/13/2014 
-- Design Name: 
-- Module Name:    circu - Behavioral 
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

entity circu is
	 port(LED_3210, LED_7654 : out integer range 0 to 15;
			PB_0, PB_2, PB_3, Clk100MHz : in bit);
end circu;

architecture Behavioral of circu is
	alias reset is PB_0; -- alias pour le signal de réinitialisation
	alias detect1 is PB_2; -- alias pour la détection axe 1
	alias detect2 is PB_3; -- alias pour la détection axe 2
	signal clk : bit;
	
	component blinker port(Clk100MHz,PB_0 : in bit; LED_0 : out bit);
	end component blinker;

	begin
	C1 : blinker port map(Clk100MHz,PB_0,clk);
	
	process(clk,reset)
		variable state : integer range 0 to 5 := 0;
		variable i : integer range 0 to 7 := 0;
		variable a1 : integer range 0 to 16 := 8;
		variable a2 : integer range 0 to 16 := 2;
	begin
	
	if reset = '1' then --reset synchrone
		state := 0;
		i:=0;
		a1:=8;
		a2:=2;
	elsif(clk'event and clk='1') then
		case state is
			when 0=> --Attente de détection sur l'axe 1
				if(detect1='1')then
					state:=1;
					a1:=8;
					a2:=2;
					i:=1;
				end if;
			when 1 => --On lance le temps de 8s de feu vert et on passe à l'orange
				if(i/=7) then
					i:=i+1;
				else
					state:=2;
					a1:=8;
					a2:=4;
					i:=0;
				end if;
			when 2 => --On attend 2s à l'orange puis on passe au rouge
				if(i/=1) then
					i:=i+1;
				else
					state:=3;
					a1:=2;
					a2:=8;
					i:=0;
				end if;
			when 3=> -- Attente de détection sur l'axe 2
				if(detect2='1')then
					state:=4;
					a1:=2;
					a2:=8;
					i:=1;
				end if;
			when 4 =>
				if(i/=7) then
					i:=i+1;
				else
					state:=5;
					a1:=4;
					a2:=8;
					i:=0;
				end if;
			when 5 =>
				if(i/=1) then
					i:=i+1;
				else
					state:=0;
					a1:=8;
					a2:=2;
					i:=0;
				end if;
			end case;
	end if;
	LED_3210<=a1;
	LED_7654<=a2;
	end process;
end Behavioral;

