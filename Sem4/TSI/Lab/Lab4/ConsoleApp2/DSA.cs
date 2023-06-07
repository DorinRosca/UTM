using System;
using System.Security.Cryptography;

public class DSA
{
    public static void Method()
    {
        try
        {
            // Crearea unui obiect DSA
            using (DSACryptoServiceProvider dsa = new DSACryptoServiceProvider())
            {
                // Generarea de chei
                DSAParameters privateKey = dsa.ExportParameters(true);
                DSAParameters publicKey = dsa.ExportParameters(false);

                // Textul de semnat
                string dataToSign = "Exemplu de text de semnat";

                // Convertirea textului într-un array de bytes
                byte[] dataToSignBytes = System.Text.Encoding.UTF8.GetBytes(dataToSign);

                // Semnarea datelor
                byte[] signature = SignData(dataToSignBytes, privateKey);

                // Verificarea semnăturii
                bool isVerified = VerifyData(dataToSignBytes, signature, publicKey);

                if (isVerified)
                {
                    Console.WriteLine("Semnătura este validă!");
                }
                else
                {
                    Console.WriteLine("Semnătura nu este validă!");
                }
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("A apărut o eroare: " + e.Message);
        }
    }

    // Metoda pentru semnarea datelor
    static byte[] SignData(byte[] data, DSAParameters privateKey)
    {
        using (DSACryptoServiceProvider dsa = new DSACryptoServiceProvider())
        {
            dsa.ImportParameters(privateKey);
            return dsa.SignData(data);
        }
    }

    // Metoda pentru verificarea semnăturii
    static bool VerifyData(byte[] data, byte[] signature, DSAParameters publicKey)
    {
        using (DSACryptoServiceProvider dsa = new DSACryptoServiceProvider())
        {
            dsa.ImportParameters(publicKey);
            return dsa.VerifyData(data, signature);
        }
    }
}