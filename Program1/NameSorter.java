/*
 * Enzo Galbo
 * Program 1
 * Steven Klein
 * 2/4/2015
 */
package program1;

    import java.util.Scanner;
    import java.io.File;
    import java.io.FileNotFoundException;
    import java.util.Arrays;

public class Program1 {

    public static void main(String[] args) {
        String[] names = new String[450];
        String[][] namesByLetter = new String[26][];
        int[] letterCount = new int[26];
        names = loadNamesFromFile(letterCount);
        Arrays.sort(names);
        namesByLetter = divideNamesByLetter(names, letterCount);
        printNamesByLetter(namesByLetter);
        
    }
    
    public static String[] loadNamesFromFile(int[] letterCount) {
        String[] target = new String[450];
        
        for (int i = 0; i < letterCount.length; i++){
            letterCount[i] = 0;
        }

        Scanner inFile;
        try {
            inFile = new Scanner(new File("names.txt"));
      
            int j = 0;
        while (inFile.hasNext()) {
            String firstName = inFile.next();
            String lastName = inFile.next();
            letterCount[((Character.getNumericValue(lastName.charAt(0))) - 10)]++;
            String fullName = lastName + "," + firstName;
            target[j] = fullName;
            j++;
        }
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found!");
            System.exit(0);
        }
        return target;
    }
    
    public static String[][] divideNamesByLetter (String[] nameList, int[] letterCounts) {
        String[][] namesByLetter = new String[26][];
        int k = 0;
        
        for (int i = 0; i < namesByLetter.length; i++) {
            namesByLetter[i] = new String[letterCounts[i]];
            for (int j = 0; j < letterCounts[i]; j++){
                namesByLetter[i][j] = nameList[k];
                k++;
            }
        }
        return namesByLetter;
    }
    
    public static void printNamesByLetter(String[][] grid) {
        String[] alphabet = {"A:", "B:", "C:", "D:", "E:", "F:",
                             "G:", "H:", "I:", "J:", "K:", "L:",
                             "M:", "N:", "O:", "P:", "Q:", "R:",
                             "S:", "T:", "U:", "V:", "W:", "X:",
                             "Y:", "Z:"};
                
        for (int i = 0; i < alphabet.length; i++){
            System.out.println(alphabet[i]);
            for (String grid1 : grid[i]) {
                System.out.println(grid1);
            }
        }
    }
}