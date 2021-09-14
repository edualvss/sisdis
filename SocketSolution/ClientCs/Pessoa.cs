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
