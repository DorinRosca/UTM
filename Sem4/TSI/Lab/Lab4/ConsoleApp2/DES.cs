using System;

    public class DES
    {
       public static void Method
            (string[] args)
        {
            string plainText = "TextCriptat!"; // Textul clar
            string key = "thekey"; // Cheia de criptare
            Console.WriteLine("Textul clar: " + plainText);
            Console.WriteLine("Cheia: " + key);

            string encryptedText = Encrypt(plainText, key); // Textul criptat
            Console.WriteLine("Textul criptat: " + encryptedText);

            string decryptedText = Decrypt(encryptedText, key); // Textul decriptat
            Console.WriteLine("Textul decriptat: " + decryptedText);
        }

        static string Encrypt(string plainText, string key)
        {
            byte[] plainBytes = System.Text.Encoding.ASCII.GetBytes(plainText);
            byte[] keyBytes = System.Text.Encoding.ASCII.GetBytes(key);

            // Criptare
            for (int i = 0; i < plainBytes.Length; i++)
            {
                plainBytes[i] = (byte)(plainBytes[i] ^ keyBytes[i % key.Length]);
            }

            return Convert.ToBase64String(plainBytes);
        }

        static string Decrypt(string encryptedText, string key)
        {
            byte[] encryptedBytes = Convert.FromBase64String(encryptedText);
            byte[] keyBytes = System.Text.Encoding.ASCII.GetBytes(key);

            // Decriptare
            for (int i = 0; i < encryptedBytes.Length; i++)
            {
                encryptedBytes[i] = (byte)(encryptedBytes[i] ^ keyBytes[i % key.Length]);
            }

            return System.Text.Encoding.ASCII.GetString(encryptedBytes);
        }
    }
