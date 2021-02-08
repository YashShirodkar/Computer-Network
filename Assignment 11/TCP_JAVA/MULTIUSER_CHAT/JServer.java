
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;


public class JServer extends Thread{
    
    static ArrayList<Socket> list;
    JServer(Socket s1){
    this.s1=s1;
    }
    Socket s1; 
    String ms,msg;
    public void run(){
        try {
            DataInputStream din=new DataInputStream(s1.getInputStream());
            DataOutputStream dou=new DataOutputStream(s1.getOutputStream());
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            msg="go";
            while(!msg.equals("stop")){
            msg=din.readUTF();
            System.out.println(s1.getInetAddress()+"  :" + msg);
            ms=br.readLine();
            dou.writeUTF(ms);
            dou.flush();
            }
        } catch (IOException ex) {
            Logger.getLogger(JServer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void main(String args[]){
        //list=new ArrayList<>(8);
        
    System.out.println("Server");
        try {
            ServerSocket serv=new ServerSocket(1997);
            while(true){
            Socket cli=serv.accept();
            JServer j1=new JServer(cli);
            //list.add(cli);
            j1.start();
            }
        } catch (IOException ex) {
            Logger.getLogger(JServer.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    }
}
