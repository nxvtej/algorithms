import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;

public class inout
{
    public static void main(String[] args) throws IOException
    {
        byte content[] = "writing here into the byte array".getBytes();
        ByteArrayInputStream inputStream = new ByteArrayInputStream(content);
        inputstream.read(content);

      file newfile = new File("txt");
        FileOutputStream fileoutstream = new FileOutputStream(newfile);
        fileoutstream.write(content);

        
        
    }
}