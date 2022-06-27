package employess;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Objects;

public class  Pracownik implements Serializable{
    //var
    protected String pesel;
    protected String imie;
    protected String nazwisko;
    protected BigDecimal wynagrodzenie;
    protected String telefonSluzbowy;
    //Set
    public void setPesel(String pesel){
        this.pesel=pesel;
    }
    public void setImie(String imie){
        this.imie=imie;
    }
    public void setNazwisko(String nazwisko){
        this.nazwisko=nazwisko;
    }
    public void setWynagrodzenie(BigDecimal wynagrodzenie){
        this.wynagrodzenie=wynagrodzenie;
    }
    public void setTelefonSluzbowy(String telefonSluzbowy){
        this.telefonSluzbowy=telefonSluzbowy;
    }
    //Get
    public String getPesel(){
        return this.pesel;
    }
    public String getImie(){
        return this.imie;
    }
    public String getNazwisko(){
        return this.nazwisko;
    }
    public BigDecimal getWynagrodzenie(){
        return this.wynagrodzenie;
    }
    public String getTelefonSluzbowy(){
        return this.telefonSluzbowy;
    }
    //Constructor
    public Pracownik(){}
    public Pracownik(String pesel, String imie, String nazwisko, BigDecimal wynagrodzenie, String telefonSluzbowy){
        this.setPesel(pesel);
        this.setImie(imie);
        this.setNazwisko(nazwisko);
        this.setWynagrodzenie(wynagrodzenie);
        this.setTelefonSluzbowy(telefonSluzbowy);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj){
            return true;
        }
        if (obj == null){
            return false;
        }
        if (getClass() == obj.getClass()){
            return true;
        }
        Pracownik tmp = (Pracownik) obj;
        return tmp.pesel.equals(this.pesel);
    }
    @Override
    public int hashCode() {
        return Objects.hash(pesel);
    }
}
