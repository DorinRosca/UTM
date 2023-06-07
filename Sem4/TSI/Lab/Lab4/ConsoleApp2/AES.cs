using System;
using System.Security.Cryptography;

public class AES
{
    private byte[] key;
    private byte[] iv;

    public void Method(byte[] key, byte[] iv)
    {
        this.key = key;
        this.iv = iv;
    }

    public byte[] Encrypt(byte[] plaintext)
    {
        using (AesManaged aes = new AesManaged())
        {
            aes.Key = key;
            aes.IV = iv;

            ICryptoTransform encryptor = aes.CreateEncryptor(aes.Key, aes.IV);

            using (System.IO.MemoryStream ms = new System.IO.MemoryStream())
            {
                using (CryptoStream cs = new CryptoStream(ms, encryptor, CryptoStreamMode.Write))
                {
                    cs.Write(plaintext, 0, plaintext.Length);
                    cs.FlushFinalBlock();
                }
                return ms.ToArray();
            }
        }
    }

    public byte[] Decrypt(byte[] ciphertext)
    {
        using (AesManaged aes = new AesManaged())
        {
            aes.Key = key;
            aes.IV = iv;

            ICryptoTransform decryptor = aes.CreateDecryptor(aes.Key, aes.IV);

            using (System.IO.MemoryStream ms = new System.IO.MemoryStream(ciphertext))
            {
                using (CryptoStream cs = new CryptoStream(ms, decryptor, CryptoStreamMode.Read))
                {
                    byte[] decrypted = new byte[ciphertext.Length];
                    int bytesRead = cs.Read(decrypted, 0, decrypted.Length);
                    byte[] result = new byte[bytesRead];
                    Array.Copy(decrypted, result, bytesRead);
                    return result;
                }
            }
        }
    }
}