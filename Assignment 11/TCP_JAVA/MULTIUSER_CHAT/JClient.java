
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author groot
 */
public class JClient {
 
    
    
    public static void main(String args[]){
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));    
    System.out.println("Client");
        try {
            Socket sk=new Socket("localhost", 1997);
            String msg="go";
            DataOutputStream dout=new DataOutputStream(sk.getOutputStream());
            DataInputStream din=new DataInputStream(sk.getInputStream());
            while(!msg.equals("stop")){
                
            System.out.print("----->");
            
            String send=br.readLine();
            dout.writeUTF(send);
            msg=din.readUTF();
            System.out.println(msg);
            }
        
        } catch (IOException ex) {
            Logger.getLogger(JClient.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    
    }
    
}
