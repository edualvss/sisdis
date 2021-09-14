using System;
using System.Collections.Generic;
using System.Text;

namespace ClientCs
{
    class Pessoa
    {
        string Nome { get; set; }
        int Idade { get; set; }
        int Altura { get; set; }

        public Pessoa(string nome, int idade, int altura)
        {
            this.Nome = nome;
            this.Idade = idade;
            this.Altura = altura;
        }

        public Pessoa (string str)
        {
            str = str.Replace("{", "").Replace("}", "");
            string [] str_splited = str.Split(";");

            this.Nome = str_splited[0];
            this.Idade = int.Parse(str_splited[1]);
            this.Altura = int.Parse(str_splited[2]);

            Console.WriteLine("pessoa criada");
        }

        public override string ToString()
        {
            string s = "{";
            s += Nome + ";";
            s += Idade + ";";
            s += Altura;
            s += "}";
            return s;
        }

        
    }
}
