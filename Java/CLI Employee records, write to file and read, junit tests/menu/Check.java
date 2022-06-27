package menu;

public final class Check {
    private Check() {}
    public static Boolean isPeselCorrect(String pesel){
        //formula from instruction Laboratorium09.pdf
        if(pesel.length()==11){
            if ((pesel.charAt(0) + 3 * pesel.charAt(1) + 7 * pesel.charAt(2) + 9 * pesel.charAt(3) + pesel.charAt(4) + 3 * pesel.charAt(5)
            + 7 * pesel.charAt(6) + 9 * pesel.charAt(7) + pesel.charAt(8) + 3 * pesel.charAt(9) + pesel.charAt(10)) % 10 != 0) {
                return false;
            }else{
                return true;
            } 
    }
    return false;
    }
    public static Boolean isStringLettersOnly(String imie){
        for(char c : imie.toCharArray()){
            if(Character.isDigit(c)){
                return false;
            }
        }
        return true;
    }
    public static Boolean isTelephoneCorrect(String telefonSluzbowy){
        //check if first character is +
        if(!(Character.isDigit(telefonSluzbowy.charAt(0))) && (telefonSluzbowy.charAt(0)!='+')){
            return false;
        }
        //check if digit, skip first
        for(int i=1; i<telefonSluzbowy.length();i++){
            if(!Character.isDigit(telefonSluzbowy.charAt(i))){
                return false;
            }
        }
        return true;
    }
    public static Boolean isStringDigitOnly(String s){
        for(char c : s.toCharArray()){
            if(!(Character.isDigit(c))){
                return false;
            }
        }
        return true;
    }
}