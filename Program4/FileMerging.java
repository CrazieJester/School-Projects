/*
 * Enzo Galbo
 * 4/30/2015
 * Steven Klein
 * This is a program that reads in doubles, stores them in arraylists
 * which are in an array, then prints them to a file in ascending order
 * stating when a file is completely read.
 */
package program4;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

public class Program4 {

    public static void main(String[] args) throws FileNotFoundException {
        ArrayList<Double> list0 = new ArrayList<>();
        ArrayList<Double> list1 = new ArrayList<>();
        ArrayList<Double> list2 = new ArrayList<>();
        ArrayList<Double> list3 = new ArrayList<>();
        ArrayList<Double> list4 = new ArrayList<>();
        ArrayList<Double> list5 = new ArrayList<>();
        ArrayList<Double> list6 = new ArrayList<>();
        ArrayList<Double> list7 = new ArrayList<>();
        ArrayList<Double> list8 = new ArrayList<>();
        ArrayList<Double> list9 = new ArrayList<>();

        ArrayList[] myArray = new ArrayList[10];
        myArray[0] = list0;
        myArray[1] = list1;
        myArray[2] = list2;
        myArray[3] = list3;
        myArray[4] = list4;
        myArray[5] = list5;
        myArray[6] = list6;
        myArray[7] = list7;
        myArray[8] = list8;
        myArray[9] = list9;

        int[] individualListSizes = new int[10];
        int listSize = 0;

        for (int i = 0; i < 10; i++) {
            try {
                DataInputStream fin = new DataInputStream(new FileInputStream("binaryfiles/temp" + i + ".dat"));
                try {
                    System.out.print("File " + i + ": ");
                    while (true) {
                        double x = fin.readDouble();
                        myArray[i].add(x);
                        System.out.print(x + " ");
                        individualListSizes[i]++;
                    }

                } catch (IOException e) {
                    System.out.println(""); // go to next line when end is reached
                    // IOException thrown when there are no values to read on file.
                }
            } catch (FileNotFoundException e) {
                System.out.println("Error, the file could not be found.");
            }
        }

        for (int i = 0; i < 10; i++) {
            listSize += individualListSizes[i];
        }

        double currentNum = 0;
        int fileDone = 0;

        File file = new File("binaryfiles/resultFile.dat");
        FileOutputStream fin = new FileOutputStream(file);
        PrintStream out = new PrintStream(fin);
        System.setOut(out);

        for (int h = 0; h < listSize; h++) {
            int jTemp = 0;
            double min = Double.MAX_VALUE;
            for (int j = 0; j < myArray.length; j++) {
                if (!myArray[j].isEmpty()) {
                    currentNum = (double) myArray[j].get(0);
                    if (min > currentNum) {
                        min = currentNum;
                        jTemp = j;
                    }
                }
            }
            System.out.println(min);
            myArray[jTemp].remove(0);
            if (myArray[jTemp].isEmpty()) {
                fileDone++;
                System.out.println("fileDone " + fileDone);
            }
        }
    }
}
