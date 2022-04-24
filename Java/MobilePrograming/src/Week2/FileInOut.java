package Week2;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileInOut {

	public static void main(String[] args) {
		try {
			File JavaFileIO = new File("sample.txt");
			if (JavaFileIO.createNewFile()) {
				try {
					FileWriter FW = new FileWriter("sample.txt");
					FW.write("아무 글자나 원하는 것을 입력하고, sample.txt로 저장하세요");
					FW.close();
				}  catch (IOException e) {
					System.out.println("An Error Occored!");
					e.printStackTrace();
				}
			}else {
			System.out.println("이미 같은 이름의 파일이 존재합니다.");	
			}			
		} catch (IOException e) {
			System.out.println("An Error Occored!");
			e.printStackTrace();
		}
		
		try {
			File readObj = new File("sample.txt");
			Scanner scan = new Scanner(readObj);
			while (scan.hasNextLine()) {
				String data = scan.nextLine();
				System.out.println(data);
			}
		}  catch (FileNotFoundException e) {
			System.out.println("An Error Occored!");
			e.printStackTrace();
		}
	}

}
