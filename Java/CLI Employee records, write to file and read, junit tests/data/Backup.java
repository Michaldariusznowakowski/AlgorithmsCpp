package data;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.HashSet;
import java.util.zip.*;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import employess.Dyrektor;
import employess.Handlowiec;
import employess.Pracownik;
import menu.Output;
public class Backup  {
    static public String filePathMT=System.getProperty("user.dir")+"\\backupMT\\";
    static public String getName(){
    LocalDate localDate = LocalDate.now();//For reference
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-LLLL-yyyy_");
    return localDate.format(formatter);
    }
    public static String[] getFiles(String name){
        File f = new File(Backup.filePathMT+"\\"+name);
        return f.list();
    }
    public static Pracownik loadGzipSingle(String filepath){
            Pracownik data=null;
            try{
            FileInputStream sin=new FileInputStream(filepath);
            GZIPInputStream gis = new GZIPInputStream(sin);
            ObjectInputStream ois = new ObjectInputStream(gis);
            Object obj = ois.readObject();
            if(obj.getClass()==Pracownik.class){data=(Pracownik)obj;}
            if(obj.getClass()==Handlowiec.class){data=(Handlowiec)obj;}
            if(obj.getClass()==Dyrektor.class){data=(Dyrektor)obj;}
            sin.close();
            gis.close();
            ois.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        return data;
    }
    public static String getfilePath(String type){
        int counter=0;
        while(true){
        File file = new File(Backup.filePathMT+type+"\\"+Backup.getName()+counter+"\\");
        if(!file.exists()){
            file.mkdirs();
            break;
        }else{
            counter++;
        }
        }
        return Backup.filePathMT+type+"\\"+Backup.getName()+counter+"\\";
    }
    private static void saveToZipSingle(Pracownik data,String dir) {
        try {
            FileOutputStream fos = new FileOutputStream(dir+data.getPesel()+".zip");
            ZipOutputStream zos = new ZipOutputStream(fos);
            ZipEntry zEntry = new ZipEntry(data.getClass().getSimpleName());
            zos.putNextEntry(zEntry);
            ObjectOutputStream oos = new ObjectOutputStream(zos);
                oos.writeObject(data);
            oos.close();
            zos.close();
            fos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
    }
    public static void saveToZip(HashSet<Pracownik> data) {
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        Object[] array = data.toArray();
        CompletableFuture<Void>[] completableFutures = new CompletableFuture[array.length];
        String dir = Backup.getfilePath("Zip");
        int i=0;
        for (Object arr : array) {
            completableFutures[i] = CompletableFuture.runAsync(() ->{
                Backup.saveToZipSingle((Pracownik) arr, dir);
            });
            i++;
        }
        for (i = 0; i < completableFutures.length; i++) {
            try {
                completableFutures[i].get();
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }
    }
    public static void saveToGzipSingle(Pracownik data, String dir){
                FileOutputStream fos;
                try {
                fos = new FileOutputStream(dir+data.getPesel()+".gzip");
                GZIPOutputStream gzos = new GZIPOutputStream(fos);
                ObjectOutputStream oos = new ObjectOutputStream(gzos);
                oos.writeObject(data);
                oos.close();
                gzos.close();
                fos.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
    }
    public static void saveToGzip(HashSet<Pracownik> data) {
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        Object[] array = data.toArray();
        CompletableFuture<Void>[] completableFutures = new CompletableFuture[array.length];
        String dir = Backup.getfilePath("Gzip");
        int i=0;
        for (Object arr : array) {
            completableFutures[i] = CompletableFuture.runAsync(() ->{
                Backup.saveToGzipSingle((Pracownik) arr, dir);
            });
            i++;
        }
    }
    public static HashSet<Pracownik> loadGzip(String dirName){
        HashSet<Pracownik> data = new HashSet<Pracownik>();
        String filenames[] = getFiles("Gzip\\"+dirName+"\\");
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        CompletableFuture<Pracownik>[] completableFutures = new CompletableFuture[filenames.length];
        int i=0;
        for (String arr : filenames) {
            completableFutures[i] = CompletableFuture.supplyAsync(() ->{
                return Backup.loadGzipSingle(Backup.filePathMT+"Gzip"+"\\"+dirName+"\\"+arr);
            });
            i++;
        }
        for (i = 0; i < filenames.length; i++) {
            try {
                if(completableFutures[i].get()==null){return null;};
                data.add(completableFutures[i].get());
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }
        return data;
    }
    public static HashSet<Pracownik> loadZip(String dirName){
        HashSet<Pracownik> data = new HashSet<Pracownik>();
        String filenames[] = getFiles("Zip\\"+dirName+"\\");
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        CompletableFuture<Pracownik>[] completableFutures = new CompletableFuture[filenames.length];
        int i=0;
        for (String arr : filenames) {
            completableFutures[i] = CompletableFuture.supplyAsync(() ->{
                return Backup.loadZipSingle(Backup.filePathMT+"Zip"+"\\"+dirName+"\\"+arr);
            });
            i++;
        }
        for (i = 0; i < filenames.length; i++) {
            try {
                if(completableFutures[i].get()==null){return null;};
                data.add(completableFutures[i].get());
                Output.println(completableFutures[i].get().getClass().getSimpleName());
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }
        return data;
    }
    public static Pracownik loadZipSingle(String filename){
            Output.println(filename);
            Pracownik data=null;
            try{
            FileInputStream sin=new FileInputStream(filename);
            ZipInputStream zis = new ZipInputStream(sin);
            zis.getNextEntry();
            ObjectInputStream ois = new ObjectInputStream(zis);
            Object obj = ois.readObject();
            if(obj.getClass()==Pracownik.class){data=(Pracownik)obj;}
            if(obj.getClass()==Handlowiec.class){data=(Handlowiec)obj;}
            if(obj.getClass()==Dyrektor.class){data=(Dyrektor)obj;}
            sin.close();
            zis.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        return data;
    }
}
