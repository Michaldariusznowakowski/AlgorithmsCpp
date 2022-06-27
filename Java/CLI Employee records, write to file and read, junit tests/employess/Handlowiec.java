package employess;

import java.math.BigDecimal;

public final class Handlowiec extends Pracownik{
    //Var
    private BigDecimal stawkaProwizji;
    private BigDecimal limitProwizji;
    //Set
    public void setStawkaProwizji(BigDecimal stawkaProwizji) {
        this.stawkaProwizji = stawkaProwizji;
    }
    public void setLimitProwizji(BigDecimal limitProwizji) {
        this.limitProwizji = limitProwizji;
    }
    //Get
    public BigDecimal getStawkaProwizji() {
        return stawkaProwizji;
    }
    public BigDecimal getLimitProwizji() {
        return limitProwizji;
    }
    //Constructor
    public Handlowiec(){}
    public Handlowiec(String pesel, String imie, String nazwisko, BigDecimal wynagrodzenie, String telefonSluzbowy){
        super(pesel,imie,nazwisko,wynagrodzenie,telefonSluzbowy);
    }
    public Handlowiec(String pesel,String imie, String nazwisko, BigDecimal wynagrodzenie, String telefonSluzbowy,BigDecimal stawkaProwizji, BigDecimal limitProwizji) {
        super(pesel,imie,nazwisko,wynagrodzenie,telefonSluzbowy);
        setStawkaProwizji(stawkaProwizji);
        setLimitProwizji(limitProwizji);
    }
}
