using System;

namespace gpi_ootpisp5_lab8_task_1_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            gpi_AbstractFactoryObject gpi_o = new gpi_AbstractFactoryObject();
            
            gpi_AbstractFactoryObject gpi_t = gpi_o.gpi_CreateBitmap("text");
            gpi_AbstractFactoryObject gpi_l = gpi_o.gpi_CreateVector("line");
            gpi_AbstractFactoryObject gpi_r = gpi_o.gpi_CreateVector("rectangle");
            gpi_AbstractFactoryObject gpi_e = gpi_o.gpi_CreateVector("ellipse");

            gpi_AbstractFactoryObject gpi_bi = gpi_o.gpi_CreateBitmap();
            gpi_AbstractFactoryObject gpi_vi = gpi_o.gpi_CreateVector();

        }
    }
}
