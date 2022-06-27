package menu;

import java.math.BigDecimal;
import java.util.HashSet;
import java.util.Iterator;
import data.Backup;
import employess.Dyrektor;
import employess.Handlowiec;
import employess.Pracownik;

public class Interaction {
    private HashSet<Pracownik> data = null;

    public Interaction(HashSet<Pracownik> HashSet) {
        this.data = HashSet;
    }

    private void showListEmp() {

        Output.println("1." + Text.menu[0] + "\n");
        Iterator<Pracownik> itr = data.iterator();
        int size = data.size();
        if (size == 0) {
            Output.printErr(Text.err[10]);
            return;
        }
        for (int i = 1; i <= size; i++) {
            Pracownik tmp = itr.next();
            int type = -1;// 1 Pracownik 2 Dyrektor 3 Handlowiec
            if (tmp.getClass() == Handlowiec.class) {
                type = 3;
            } else if (tmp.getClass() == Dyrektor.class) {
                type = 2;
            } else {
                type = 1;
            }
            // TYPE 1
            Output.printf(Text.format[0], Text.list[0], Text.other[7], tmp.getPesel());// ps
            Output.printf(Text.format[0], Text.list[1], Text.other[7], tmp.getImie());// im
            Output.printf(Text.format[0], Text.list[2], Text.other[7], tmp.getNazwisko());// nazw
            Output.printf(Text.format[0], Text.list[3], Text.other[7], Text.other[type]);// stan
            Output.printf(Text.format[0], Text.list[4], Text.other[7], tmp.getWynagrodzenie());// wyn
            Output.printf(Text.format[0], Text.list[5], Text.other[7], tmp.getTelefonSluzbowy());// tels
            // TYPE 2 DYREKTOR
            if (type == 2) {
                Output.printf(Text.format[0], Text.list[6], Text.other[7], ((Dyrektor) tmp).getDodatekSluzbowy());// dods
                Output.printf(Text.format[0], Text.list[7], Text.other[7], ((Dyrektor) tmp).getKartaSluzbowa());// kartsluz
                Output.printf(Text.format[0], Text.list[8], Text.other[7], ((Dyrektor) tmp).getLimitKosztow());// limtksz
            }
            // TYPE 3 HANDLOWIEC
            if (type == 3) {
                Output.printf(Text.format[0], Text.list[9], Text.other[7], ((Handlowiec) tmp).getStawkaProwizji());// prow
                Output.printf(Text.format[0], Text.list[10], Text.other[7], ((Handlowiec) tmp).getLimitProwizji());// limt
                                                                                                                   // prow
            }

            Output.printf(Text.format[1], Text.other[14], i, size, Text.other[15]);
            if (i < size) {
                Output.println(Text.other[5] + Text.other[8]);
            }
            Output.println(Text.other[6] + Text.other[12]);
            char data = '0';
            boolean inputCorrect = false;
            while (!inputCorrect) {
                try {
                    data = Input.getChar();
                    if (data == 'Q' || data == 'q') {
                        inputCorrect = true;
                        return;
                    } else if (Character.isWhitespace(data) && i < size) {
                        inputCorrect = true;
                    } else {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                } catch (IllegalArgumentException e) {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            }

        }
    }

    private boolean showAddEmpConfirm() {
        Output.println("\n\t" + Text.other[0]);
        Output.println(Text.other[5] + Text.other[9]);
        Output.println(Text.other[6] + Text.other[13]);
        char chIn = '-';
        boolean inputCorrect = false;
        while (!inputCorrect) {
            try {
                chIn = Input.getChar();
                if (chIn == 'Q' || chIn == 'q') {
                    inputCorrect = true;
                    ;
                    return false;
                } else if (Character.isWhitespace(chIn)) {
                    inputCorrect = true;
                    return true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        return false;
    }

    private void showAddEmp() {
        char chIn = '0';
        Output.println("2." + Text.menu[1] + "\n");
        Output.print(Text.choice[0] + "\t");
        boolean inputCorrect = false;
        int type = -1;// 1 Pracownik 2 Dyrektor 3 Handlowiec
        while (!inputCorrect) {
            try {
                chIn = Input.getChar();
                if (chIn == 'd' || chIn == 'D') {
                    inputCorrect = true;
                    type = 2;
                } else if (chIn == 'h' || chIn == 'H') {
                    type = 3;
                    inputCorrect = true;
                } else if (chIn == 'p' || chIn == 'P') {
                    type = 1;
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        Output.println("\t" + Text.other[0]);
        // Get for Everyone
        // Pesel
        String pracownikPesel = "";
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[0], Text.other[7]);
                pracownikPesel = Input.getPesel();
                inputCorrect = true;
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[3]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        // Name
        String pracownikName = "";
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[1], Text.other[7]);
                pracownikName = Input.getString();
                inputCorrect = true;
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        // Surname

        String pracownikSurname = "";
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[2], Text.other[7]);
                pracownikSurname = Input.getString();
                inputCorrect = true;
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        // Money

        BigDecimal pracownikMoney = BigDecimal.ZERO;
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[4], Text.other[7]);
                pracownikMoney = Input.getBDecimal();
                inputCorrect = true;
                if (pracownikMoney.compareTo(BigDecimal.ZERO) > 0) {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[5]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        // Telephone
        String pracownikTelephone = "";
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[5], Text.other[7]);
                pracownikTelephone = Input.getTelephone();
                inputCorrect = true;
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;

        // Add
        switch (type) {
            case 1:
                Pracownik nPracownik = new Pracownik(pracownikPesel, pracownikName, pracownikSurname, pracownikMoney,
                        pracownikTelephone);
                if (this.showAddEmpConfirm()) {
                    Boolean isGood = this.data.add(nPracownik);
                    if (!isGood) {
                        Output.printErr(Text.err[4]);
                    }
                }
                break;
            case 2:
                Dyrektor nDyrektor = new Dyrektor(pracownikPesel, pracownikName, pracownikSurname, pracownikMoney,
                        pracownikTelephone);
                // More money

                while (!inputCorrect) {
                    try {
                        Output.printf(Text.format[2], Text.list[6], Text.other[7]);
                        nDyrektor.setDodatekSluzbowy(Input.getBDecimal());
                        if (nDyrektor.getDodatekSluzbowy().compareTo(BigDecimal.ZERO) > 0) {
                            inputCorrect = true;
                        } else {
                            Output.printErr(Text.err[3]);
                        }
                    } catch (IllegalArgumentException e) {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                }
                inputCorrect = false;
                // Creditcard

                while (!inputCorrect) {
                    try {
                        Output.printf(Text.format[2], Text.list[7], Text.other[7]);
                        nDyrektor.setKartaSluzbowa(Input.getBInt());
                        inputCorrect = true;
                    } catch (IllegalArgumentException e) {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                }
                inputCorrect = false;
                // Creditcard limit

                while (!inputCorrect) {
                    try {
                        Output.printf(Text.format[2], Text.list[8], Text.other[7]);
                        nDyrektor.setLimitKosztow(Input.getBDecimal());
                        inputCorrect = true;
                    } catch (IllegalArgumentException e) {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                }
                inputCorrect = false;
                if (this.showAddEmpConfirm()) {
                    Boolean isGood = this.data.add(nDyrektor);
                    if (!isGood) {
                        Output.printErr(Text.err[4]);
                    }
                }
                break;
            case 3:
                Handlowiec nHandlarz = new Handlowiec(pracownikPesel, pracownikName, pracownikSurname, pracownikMoney,
                        pracownikTelephone);
                // %

                while (!inputCorrect) {
                    try {
                        Output.printf(Text.format[2], Text.list[9], Text.other[7]);
                        nHandlarz.setStawkaProwizji(Input.getBDecimal());
                        inputCorrect = true;
                    } catch (IllegalArgumentException e) {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                }
                inputCorrect = false;
                // limit of %

                while (!inputCorrect) {
                    try {
                        Output.printf(Text.format[2], Text.list[10], Text.other[7]);
                        nHandlarz.setLimitProwizji(Input.getBDecimal());
                        inputCorrect = true;
                    } catch (IllegalArgumentException e) {
                        Output.printErr(Text.err[2]);
                        inputCorrect = false;
                    }
                }
                inputCorrect = false;

                if (this.showAddEmpConfirm()) {
                    Boolean isGood = this.data.add(nHandlarz);
                    if (!isGood) {
                        Output.printErr(Text.err[4]);
                    }
                }
                break;
        }
        return;
    }

    public static boolean removeEmp(String pesel, HashSet<Pracownik> data) {
        Iterator<Pracownik> itr = data.iterator();
        while (itr.hasNext()) {
            Pracownik tmp = itr.next();
            if (tmp.getPesel().equals(pesel)) {
                data.remove(tmp);
                return true;
            }
        }
        return true;
    }

    private void showRmEmp() {
        Output.println("3." + Text.menu[2]);
        if (this.data.size() == 0) {
            Output.printErr(Text.err[10]);
            return;
        }
        boolean inputCorrect = false;
        String pracownikPesel = "";
        while (!inputCorrect) {
            try {
                Output.printf(Text.format[2], Text.list[0], Text.other[7]);
                pracownikPesel = Input.getPesel();
                inputCorrect = true;
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        inputCorrect = false;
        Output.println("\n\t" + Text.other[0]);
        Output.println(Text.other[5] + Text.other[16]);
        Output.println(Text.other[6] + Text.other[12]);
        char chIn = '-';
        inputCorrect = false;
        while (!inputCorrect) {
            try {
                chIn = Input.getChar();
                if (chIn == 'Q' || chIn == 'q') {
                    inputCorrect = true;
                    ;
                    return;
                } else if (Character.isWhitespace(chIn)) {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        if (Interaction.removeEmp(pracownikPesel, this.data)) {
            Output.println(Text.other[17]);
        } else {
            Output.printErr(Text.err[6]);
        }
        return;
    }

    private boolean bckConfirm() {
        Output.println("\t" + Text.other[0]);
        Output.println(Text.other[5] + Text.other[10]);
        Output.println(Text.other[6] + Text.other[13]);
        // do you want to accept? Enter or q
        boolean inputCorrect = false;
        char chIn = '-';
        while (!inputCorrect) {
            try {
                chIn = Input.getChar();
                if (chIn == 'Q' || chIn == 'q') {
                    inputCorrect = true;
                    ;
                    return false;
                } else if (Character.isWhitespace(chIn)) {
                    inputCorrect = true;
                    return true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }

        }
        return false;
    }

    private void bckOpenGzip() {
        String files[] = Backup.getFiles("Gzip\\");
        if (files.length == 0) {
            Output.printErr(Text.err[8]);
            return;
        }
        for (int i = 0; i < files.length; i++) {
            Output.printf(Text.format[4], i + 1, Text.other[7], files[i]);
        }
        Output.println("\t" + Text.other[0]);
        Output.print(Text.other[11]);
        // get input
        boolean inputCorrect = false;
        int number = '-';
        while (!inputCorrect) {
            try {
                number = Input.getInt();
                if (number > 0 && number <= files.length) {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        // confirm
        if (!this.bckConfirm()) {
            return;
        }
        // do stuff
        HashSet out = Backup.loadGzip(files[number - 1]);
        if (out == null) {
            Output.printErr(Text.err[9]);
            return;
        }
        this.data = Backup.loadGzip(files[number - 1]);
        Output.println(Text.other[18]);
        return;
    }

    private void bckSaveGzip() {
        if (this.data.size() == 0) {
            Output.printErr(Text.err[10]);
            return;
        }
        Backup.saveToGzip(this.data);
        Output.println(Text.other[18]);
        return;
    }

    private void bckSaveZip() {
        if (this.data.size() == 0) {
            Output.printErr(Text.err[10]);
            return;
        }
        Backup.saveToZip(this.data);
        Output.println(Text.other[18]);
        return;
    }

    private void bckOpenZip() {
        String files[] = Backup.getFiles("Zip\\");
        if (files.length == 0) {
            Output.printErr(Text.err[8]);
            return;
        }
        for (int i = 0; i < files.length; i++) {
            Output.printf(Text.format[4], i + 1, Text.other[7], files[i]);
        }
        Output.println("\t" + Text.other[0]);
        Output.print(Text.other[11]);
        // get input
        boolean inputCorrect = false;
        int number = '-';
        while (!inputCorrect) {
            try {
                number = Input.getInt();
                if (number > 0 && number <= files.length) {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        // confirm
        if (!bckConfirm()) {
            return;
        }
        // do stuff
        HashSet out = Backup.loadZip(files[number - 1]);
        if (out == null) {
            Output.printErr(Text.err[9]);
            return;
        }
        this.data = Backup.loadGzip(files[number - 1]);
        Output.println(Text.other[18]);
        return;
    }

    private void bckShow() {
        Output.println("4." + Text.menu[3]);
        Output.printf(Text.format[2], Text.choice[1], Text.other[7]);
        // Z save or O open
        boolean inputCorrect = false;
        char chInZO = '-';
        while (!inputCorrect) {
            try {
                chInZO = Input.getChar();
                if (chInZO == 'Z' || chInZO == 'z') {
                    inputCorrect = true;
                } else if (chInZO == 'o' || chInZO == 'O') {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        Output.println("\t" + Text.other[0]);
        Output.printf(Text.format[2], Text.choice[2], Text.other[7]);
        // Gzip or Zip
        inputCorrect = false;
        char chInGZ = '-';
        while (!inputCorrect) {
            try {
                chInGZ = Input.getChar();
                if (chInGZ == 'G' || chInGZ == 'g') {
                    inputCorrect = true;
                    ;
                } else if (chInGZ == 'Z' || chInGZ == 'z') {
                    inputCorrect = true;
                } else {
                    Output.printErr(Text.err[2]);
                    inputCorrect = false;
                }
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[2]);
                inputCorrect = false;
            }
        }
        Output.println("\t" + Text.other[0]);
        chInGZ = Character.toUpperCase(chInGZ);
        chInZO = Character.toUpperCase(chInZO);
        if (chInGZ == 'G' && chInZO == 'O') {
            this.bckOpenGzip();
        }
        if (chInGZ == 'G' && chInZO == 'Z') {
            this.bckSaveGzip();
        }
        if (chInGZ == 'Z' && chInZO == 'O') {
            this.bckOpenZip();
        }
        if (chInGZ == 'Z' && chInZO == 'Z') {
            this.bckSaveZip();
        }
        return;
    }

    public void menu() {
        Boolean in = false;
        int choice = -1;
        while (!in) {
            choice = -1;
            this.showMenu();
            try {
                choice = Input.getInt();
            } catch (IllegalArgumentException e) {
                Output.printErr(Text.err[0]);
            }
            if (choice <= 5 && choice >= 1) {
                in = true;
            } else {
                Output.printErr(Text.err[1]);
            }
        }
        switch (choice) {
            case 1:
                this.showListEmp();
                break;
            case 2:
                this.showAddEmp();
                break;
            case 3:
                this.showRmEmp();
                break;
            case 4:
                this.bckShow();
                break;
            case 5:
                System.exit(0);
                break;

        }
    }

    private void showMenu() {
        Output.println(Text.menu[4]);
        Output.printf("\t1. %s \n", Text.menu[0]);
        Output.printf("\t2. %s \n", Text.menu[1]);
        Output.printf("\t3. %s \n", Text.menu[2]);
        Output.printf("\t4. %s \n", Text.menu[3]);
        Output.printf("\t5. %s \n", Text.menu[5]);
        Output.print(Text.other[11]);
    }
}
