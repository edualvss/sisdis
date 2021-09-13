
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author eduardo
 */
public class TCPSocket {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String hostname = args[0];
        int portNumber = Integer.parseInt(args[1]);
        
        try{
            // 1. Cria Socket
            Socket socket = new Socket(hostname,portNumber);
            // 2. Cria o canal de saida de mensagens
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            // 3. Cria o canal de entrada de mensagens
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            // Cria leitor do console
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            
            
            String userInput;
            while((userInput = stdIn.readLine()) != null) {
                // 4. Envia mensagem
                out.println(userInput);
                // 5. Recebe mensagem
                System.out.println("Echo: "+ in.readLine());
            }
        } catch(Exception ex) {
            System.err.println("Problem: "+ex.getLocalizedMessage());
        }
        
        
    }
    
}
