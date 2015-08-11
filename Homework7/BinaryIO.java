/*
 * Enzo Galbo
 * 4/10/2015
 * Steven Klein
 * CS 150
 * This is a program that creates a file and populates it with doubles using
 * a data output stream, then reads these doubles as chars using
 * a data input stream.
 */
package homework7;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Homework7 {

    public static void main(String[] args) {
        File dir = new File("binaryfiles");
        dir.mkdir();
        for (int i = 0; i < 10; i++) {
            try {
                DataOutputStream fout = new DataOutputStream(new FileOutputStream("binaryfiles/temp" + i + ".dat"));
                for (int j = 0; j < 20; j++) {
                    fout.writeDouble((Math.random() * 500));
                }
            } catch (IOException e) {
                System.out.println("Error, file could not be created.");
            }
        }

        for (int i = 0; i < 10; i++) {
            try {
                DataInputStream fin = new DataInputStream(new FileInputStream("binaryfiles/temp" + i + ".dat"));
                try {
                    System.out.print("File " + i + ": ");
                    while (true) {                        
                    System.out.print(fin.readChar() + " ");
                    }
                    
                } catch (IOException e) {
                    System.out.println(""); // go to next line when end is reached
                                            // IOException thrown when there are no values to read on file.
                }
            } catch (FileNotFoundException e) {
                System.out.println("Error, the file could not be found.");
            }

        }

    }

}
