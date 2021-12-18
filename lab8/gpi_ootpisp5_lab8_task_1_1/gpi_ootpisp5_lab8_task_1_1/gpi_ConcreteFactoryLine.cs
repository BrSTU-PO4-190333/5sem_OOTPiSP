using System;

public class gpi_ConcreteFactoryLine: gpi_AbstractFactoryVectorImage
{
	protected int		gpi_x1 = 0;		// Координата первой точки
	protected int		gpi_y1 = 0;		// Координата первой точки
	protected int		gpi_x2 = 0;		// Координата второй точки
	protected int		gpi_y2 = 0;		// Координата второй точки

	public gpi_ConcreteFactoryLine()
	{
		Console.WriteLine("     `-- constructor line");
	}
}
