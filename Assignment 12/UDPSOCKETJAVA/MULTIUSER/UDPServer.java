import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UDPServer {
    public static void main(String[] args) throws SocketException,IOException {

        DatagramSocket serverSocket = new DatagramSocket(5000);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));


        byte[] receiveData = new byte[1024];
        byte[] sendData;

        while(true){
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

            serverSocket.receive(receivePacket);

            String sentence = new String(receivePacket.getData(), 0, receivePacket.getLength());

            if(sentence.equals("stop"))
                break;

            System.out.println("Client:"+sentence);

            InetAddress IPAddress = receivePacket.getAddress();

            int port = receivePacket.getPort();

            String serverSentence = in.readLine();

            sendData = serverSentence.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);

            serverSocket.send(sendPacket);
        }

    }
}
