entity tp2_3 is
  port(PB_0,SW_0 : in bit;
       LED_0 : out bit);  
end tp2_3;

architecture Behavioral of tp2_3 is
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
        end if;
      when 1 =>
        if(SW_0='1') then
          nbt:=2;
        end if;
      when 2 =>
        if(SW_0='0') then
          nbt:=3;
        end if;
      when 3 =>
        if (SW_0 ='1') then
          nbt:=4;
        end if;
      when 4 =>
        nbt:=0;
        if(SW_0='0') then
          nbt:=5;
          allume := '1';
        end if;
      when 5 =>
        nbt:=0;
        allume:='0';
      end case;
      LED_0<=allume;
    end if;
  end process;        
end Behavioral;