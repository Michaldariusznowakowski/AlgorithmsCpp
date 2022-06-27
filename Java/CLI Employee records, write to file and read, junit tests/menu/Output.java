package menu;

public class Output {
    private Output(){}
    public static void printf(String f,Object... args){
        for (int i=0;i<args.length;i++) {
            if(args[i]==null || args[i]==""){
                args[i]=Text.other[4];
            }
        }
        System.out.printf(f,args);
    }
    public static void printErr(String text){
        System.out.println("\033[0;31m"+text+"\033[0m");
    }
    public static void print(String text){
        if(text.isEmpty()){text=Text.other[4];}
        System.out.print(text);
    }
    public static void println(String text){
        if(text.isEmpty()){text=Text.other[4];}
        System.out.println(text);
    }
}
