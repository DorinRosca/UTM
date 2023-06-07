using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;

namespace ConsoleApp2
{
   public class Menu
    {
        static void Main(string[] args)
        {
            RSA obiect1 = new RSA();
            DSA obiect2 = new DSA();
            DES obiect3 = new DES();
            AES obiect4 = new AES();

            /* RSA.Method();
             DES.Method(args);*/

            // Meniul
            Console.WriteLine("============== Meniu =============");
            Console.WriteLine("1. Algoritmul DES");
            Console.WriteLine("2. Algoritmul RSA");
            Console.WriteLine("3. Algoritmul DSA");
            Console.WriteLine("4. Algoritmul Exit");

            int option;
            bool exit = false;

            while (!exit)
            {
                // Solicitare input de la utilizator
                Console.Write("Introduceti Optiunea: ");
                if (int.TryParse(Console.ReadLine(), out option))
                {
                    switch (option)
                    {
                        case 1:
                            Console.WriteLine("1.Algoritmul DES.\n");
                            DES.Method(args);
                            break;
                        case 2:
                            Console.WriteLine("2. Algoritmul AES.");
                            /*AES.Method(args);*/
                            break;
                        case 3:
                            Console.WriteLine("3. Algoritmul RSA");
                            RSA.Method();
                            break;
                        case 4:
                            Console.WriteLine("4. Algoritmul DSA");
                            DSA.Method();
                            break;
                        case 5:
                            Console.WriteLine("Ati selectat Exit.");
                            exit = true;
                            break;
                        default:
                            Console.WriteLine("Optiune invalida. Incercati din nou.");
                            break;
                    }
                }
                else
                {
                    Console.WriteLine("Optiune invalida. Incercati din nou.");
                }
            }

            // Pauza pentru a vizualiza rezultatul
            Console.ReadLine();
        }


    }
    
}
