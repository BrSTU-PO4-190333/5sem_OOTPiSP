using System;

public class gpi_ConcreteFactoryRectangle: gpi_AbstractFactoryVectorImage
{
	protected int		gpi_x = 0;		// Координата верхнего левого угла
	protected int		gpi_y = 0;		// Координата верхнего левого угла
	protected float		gpi_v = 0;		// Длина по вертикали
	protected float		gpi_h = 0;		// Длина по горизонтали

	public gpi_ConcreteFactoryRectangle()
	{
		Console.WriteLine("     `-- constructor rectangle");
	}
}
