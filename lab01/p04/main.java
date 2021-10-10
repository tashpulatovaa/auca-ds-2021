import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);

        while(inp.hasNextLine()){
            String line = inp.nextLine();
            System.out.println(isPalindrome(line) ? "palindrome" : "not a palindrome");
        }
    }

    static boolean isPalindrome(String line){
        StringBuilder builder = new StringBuilder();
        for(char c : line.toCharArray()){
            if(Character.isLetter(c)){
                builder.append(Character.toLowerCase(c));
            }
        }

        StringBuilder tmp = new StringBuilder();
        for(char c : line.toCharArray()) {
            if (Character.isLetter(c)) {
                tmp.append(Character.toLowerCase(c));
            }
        }
        tmp.reverse();

        return builder.toString().equals(tmp.toString());
    }
}