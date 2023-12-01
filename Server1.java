import java.net.*;
import java.io.*;
public class Server{
public static void main(String args[]) throws IOException
{
ServerSocket ss=new ServerSocket(4000);
System.out.println("waiting forconnection...");
Socket s=ss.accept();
}
}
