import java.io.File;
import java.io.IOException;
import java.util.HashSet;

import data.Backup;
import employess.Pracownik;
import menu.Interaction;
public class start {

    public static void main(String[] args) throws IOException {
        // System.out.println("Test");
        //Handlowiec tmp = new Handlowiec("2221", "Michał1", "", new BigDecimal(44444), "+48732732732", new BigDecimal(44444), new BigDecimal(44444));
        // Handlowiec tmp2 = new Handlowiec("2222", "Michał2", "Nowakowski", new BigDecimal(0), "+48732732732", new BigDecimal(44444), new BigDecimal(44444));
        // Handlowiec tmp3 = new Handlowiec("2223", "Michał3", "Nowakowski", null, "+48732732732", new BigDecimal(44444), new BigDecimal(44444));
         HashSet<Pracownik> data = new HashSet<>();
        //data.add(tmp);
        //data.add(tmp2);
        //data.add(tmp3);
        String files[] = Backup.getFiles("Zip\\");
        File newFile = new File(Backup.filePathMT+"Zip\\"+files[files.length-1]+"\\89022eee2468.zip");
        newFile.createNewFile();
        Interaction obj = new Interaction(data);
        while(true){
        obj.menu();
        }
    }
}