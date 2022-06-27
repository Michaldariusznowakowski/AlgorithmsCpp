package tests;
import java.io.File;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Random;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import data.Backup;
import employess.Dyrektor;
import employess.Handlowiec;
import employess.Pracownik;
import menu.Check;
import menu.Interaction;

public class tests {
    static String randomLetters(int targetLenght){
        int left=97;//a
        int right= 122;//z
        Random random= new Random();
        String output="";
        for (int i = 0; i < targetLenght; i++) {
            int randomC = left + (int) 
          (random.nextFloat() * (right - left + 1));
          output=output+Character.toString(Character.toChars(randomC)[0]);
        }
        return output;
    }
    static int randomInt(int max, int min){
        Random random = new Random();
        int l = max - min + 1;
        int i = random.nextInt() % l;
        return max + i;
    }
    @Test
    void addHandlowiec(){
        Handlowiec test = new Handlowiec("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        Assertions.assertTrue(contTest.add(test));
    }
    @Test
    void addDyrektor(){
        Dyrektor test = new Dyrektor("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        Assertions.assertTrue(contTest.add(test));
    }
    @Test
    void addHandlowiecToOthers(){
        Handlowiec test = new Handlowiec("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        Dyrektor test2 = new Dyrektor("86041232576", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        contTest.add(test2);
        Boolean correct = true;
        if(contTest.add(test)==false){correct=false;}
        Assertions.assertTrue(correct);
    }
    @Test
    void addDyrektorToOthers(){
        Dyrektor test = new Dyrektor("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        Handlowiec test2 = new Handlowiec("88031165239", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        contTest.add(test2);
        Boolean correct = true;
        if(contTest.add(test)==false){correct=false;}
        Assertions.assertTrue(correct);
    }
    @Test
    void addDyrektorToOthersWithNoResult(){
        Dyrektor test = new Dyrektor("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        Handlowiec test2 = new Handlowiec("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        contTest.add(test2);
        Boolean correct = true;
        if(contTest.add(test)==false){correct=false;}
        Assertions.assertTrue(correct);
    }
    @Test
    void addRandomTenWorkers(){
        Pracownik tests[] = new Pracownik[10];
        tests[0] = new Handlowiec("91092665857", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        tests[1] = new Handlowiec("86041232576", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        tests[2] = new Handlowiec("88031165239", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        tests[3] = new Handlowiec("96031499122", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        
        tests[4] = new Dyrektor("79011328735", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        tests[5] = new Dyrektor("63112815636", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        tests[6] = new Dyrektor("76041015297", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        tests[7] = new Dyrektor("95060735845", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        
        tests[8] = new Pracownik("78082225635", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)));
        tests[9] = new Pracownik("89081431468", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        Boolean correct = true;
        for (Pracownik pracownik : tests) {
            if(contTest.add(pracownik)==false){
                correct=false;
            }
        }
        Assertions.assertTrue(correct);
    }
    @Test
    void remDyrektor(){
        String pesel ="91092665857";
        Dyrektor test = new Dyrektor(pesel, randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)), new BigDecimal(randomInt(100, 1)),BigInteger.valueOf(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        contTest.add(test);
        Assertions.assertTrue(Interaction.removeEmp(pesel, contTest));
    }
    @Test
    void remHandlowiec(){
        String pesel ="91092665857";
        Handlowiec test = new Handlowiec(pesel, randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        contTest.add(test);
        Assertions.assertTrue(Interaction.removeEmp(pesel, contTest));
    }
    @Test
    void checkPesel(){
        String correctPesels[]={
            "91092665857",
            "86041232576",
            "88031165239",
            "96031499122",
            "79011328735",
            "63112815636",
            "76041015297",
            "95060735845",
            "78082225635",
            "89081431468"
        };
        String badPesel[]={
            "911126658571",
            "22221232576",
            "8803116239",
            "960aa991222",
            "70001328735",
            "63122815636",
            "76221015297",
            "123",
            "",
            "1"
        };
        for (String string : badPesel) {
            Assertions.assertFalse(Check.isPeselCorrect(string));
        }
        for (String string : correctPesels) {
            Assertions.assertTrue(Check.isPeselCorrect(string));
        }
    }
    //SaveToZip And load Check if correct
    @Test
    void checkSerializable(){
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        Handlowiec test = new Handlowiec("89081431468", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        contTest.add(test);
        Backup.saveToZip(contTest);
        String files[] = Backup.getFiles("Zip\\");
        if(files.length==0){Assertions.assertFalse(true);}
        HashSet<Pracownik> contTest2 = Backup.loadZip(files[files.length-1]);
        Assertions.assertTrue(contTest2.contains(test));
    }
    @Test
    void checkSerializableError() throws IOException{
        HashSet<Pracownik> contTest = new HashSet<Pracownik>();
        Handlowiec test = new Handlowiec("89081431468", randomLetters(10), randomLetters(10), new BigDecimal(randomInt(5000,1)), Integer.toString(randomInt(999999999,0)), new BigDecimal(randomInt(100, 1)),new BigDecimal(randomInt(100, 1)));
        contTest.add(test);
        Backup.saveToZip(contTest);
        String files[] = Backup.getFiles("Zip\\");
        String filesZ[] = Backup.getFiles("Zip\\"+files[files.length-1]+"\\");
        File newFile = new File(Backup.filePathMT+"Zip\\"+files[files.length-1]+"\\"+filesZ[filesZ.length-1]);
        newFile.delete();
        newFile.createNewFile();
        if(files.length==0){Assertions.assertFalse(true);}
        HashSet<Pracownik> contTest2 = Backup.loadZip(files[files.length-1]);
        if(contTest2==null){Assertions.assertTrue(true);}
    }
}
