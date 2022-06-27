package employess;

import java.math.BigDecimal;
import java.math.BigInteger;

public final class Dyrektor extends Pracownik {
    //var
    private BigDecimal dodatekSluzbowy;
    private BigDecimal limitKosztow;
    private BigInteger kartaSluzbowa;
    //Set
    public void setDodatekSluzbowy(BigDecimal dodatekSluzbowy){
        this.dodatekSluzbowy=dodatekSluzbowy;
    }
    public void setLimitKosztow(BigDecimal limitKosztow){
        this.limitKosztow=limitKosztow;
    }
    public void setKartaSluzbowa(BigInteger kartaSluzbowa){
        this.kartaSluzbowa=kartaSluzbowa;
    }
    //Get
    public BigDecimal getDodatekSluzbowy(){
        return this.dodatekSluzbowy;
    }
    public BigDecimal getLimitKosztow(){
        return this.limitKosztow;
    }
    public BigInteger getKartaSluzbowa(){
        return this.kartaSluzbowa;
    }
    //Constructor
    public Dyrektor(){}
    public Dyrektor(String pesel, String imie, String nazwisko, BigDecimal wynagrodzenie, String telefonSluzbowy){
        super(pesel,imie,nazwisko,wynagrodzenie,telefonSluzbowy);
    }
    public Dyrektor(String pesel, String imie, String nazwisko, BigDecimal wynagrodzenie, String telefonSluzbowy,BigDecimal dodatekSluzbowy,BigDecimal limitKosztow,BigInteger kartaSluzbowa){
        super(pesel,imie,nazwisko,wynagrodzenie,telefonSluzbowy);
        this.setDodatekSluzbowy(dodatekSluzbowy);
        this.setLimitKosztow(limitKosztow);
        this.setKartaSluzbowa(kartaSluzbowa);
    }
}
