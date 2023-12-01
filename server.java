import java.net.*;
import java.io.*;
public class server{
public static void main(String[]args)throws IOException{
ServerSocket ss=new ServerSocket(5000);
System.out.println("waiting for connection...");
Socket s=ss.accept();
PrintWriter out=new PrintWriter(s.getOutputStream(),true);
BufferedReader in=new BufferedReader(new InputStreamReader(s.getInputStream()));
BufferedReader kln=new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));

while(true)
{
System.out.println("client say:"+in.readLine());
String Input=kln.readLine();

out.println(Input);
}
}
}

