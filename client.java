import java.net.*;
import java.io.*;
public class client{
public static void main(String[] args)throws IOException{

Socket s=new Socket("localhost",5000);
PrintWriter out=new PrintWriter(s.getOutputStream(),true);
BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
BufferedReader kln=new BufferedReader(new InputStreamReader(System.in));

while(true)
{
String UserInput=kln.readLine();
out.println(UserInput);
System.out.println("server says:"+in.readLine());


}
}
}
