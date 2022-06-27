package menu;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Input {
    private Input(){}
    private static Scanner console = new Scanner(System.in);
    private static String get(){
        String Output = Input.console.nextLine();
        return Output;
    }
    public static String getString(){
        return Input.get();
    }
    public static String getTelephone(){
        String Tmp=Input.get();
        Tmp=Tmp.trim();
        if(Tmp.length()==0){
            return Tmp;
        }
        if(!(Check.isTelephoneCorrect(Tmp))){
            throw new IllegalArgumentException();
        }
        return Tmp;
    }
    public static String getPesel(){
        String Tmp=Input.get();
        Tmp=Tmp.trim();
        if(!(Check.isPeselCorrect(Tmp))){
            throw new IllegalArgumentException();
        }
        return Tmp;
    }
    public static BigDecimal getBDecimal(){
        String Tmp=Input.get();
        Tmp=Tmp.trim();
        if(!(Check.isStringDigitOnly(Tmp))){
            throw new IllegalArgumentException();
        }
        return new BigDecimal(Tmp);
    }
    public static BigInteger getBInt(){
        String Tmp=Input.get();
        Tmp=Tmp.trim();
        if(!(Check.isStringDigitOnly(Tmp))){
            throw new IllegalArgumentException();
        }
        return new BigInteger(Tmp);
    }
    public static int getInt(){
        String Tmp=Input.get();
        Tmp=Tmp.trim();
        if(!(Check.isStringDigitOnly(Tmp))){
            throw new IllegalArgumentException();
        }
        return Integer.parseInt(Tmp);
    }
    public static char getChar(){
        String Tmp=Input.get();
        Tmp=Tmp.strip();
        if(Tmp.length()>1){
            throw new IllegalArgumentException();
        }
        if(Tmp.isEmpty()){return ' ';}
        return Tmp.charAt(0);
    }
}
