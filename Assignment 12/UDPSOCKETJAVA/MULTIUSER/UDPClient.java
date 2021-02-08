import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient {
    public static void main(String args[]) throws Exception
    {
        BufferedReader inFromUser =
                new BufferedReader(
                        new InputStreamReader(System.in));

        DatagramSocket clientSocket = new DatagramSocket();

        // Replace hostname with the FQDN of the server.

        InetAddress IPAddress = InetAddress.getByName("localhost");

        byte[] sendData;

        byte[] receiveData = new byte[1024];

        while(true) {
            String sentence = inFromUser.readLine();

            sendData = sentence.getBytes();

            DatagramPacket sendPacket =
                    new DatagramPacket(sendData, sendData.length,
                            IPAddress, 5000);

            clientSocket.send(sendPacket);

            if(sentence.equals("stop"))
                break;

            DatagramPacket receivePacket =
                    new DatagramPacket(receiveData, receiveData.length);

            clientSocket.receive(receivePacket);

            String modifiedSentence = new String(receivePacket.getData(),
                    0, receivePacket.getLength());

            System.out.println("FROM SERVER: " + modifiedSentence);
        }
        clientSocket.close();
    }
}
