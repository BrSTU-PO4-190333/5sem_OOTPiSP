using System;

public class gpi_ConcreteFactoryText: gpi_AbstractFactoryBitmapImage
{
	protected string	gpi_t = "";			// Текст

	public gpi_ConcreteFactoryText()
	{
		Console.WriteLine("     `-- constructor text");
	}

}
