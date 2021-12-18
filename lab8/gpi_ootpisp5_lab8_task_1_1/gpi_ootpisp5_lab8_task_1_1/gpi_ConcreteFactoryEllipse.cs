using System;

public class gpi_ConcreteFactoryEllipse: gpi_AbstractFactoryVectorImage
{
	protected int		gpi_x = 0;		// Координата центра
	protected int		gpi_y = 0;		// Координата центра
	protected float		gpi_rv = 0;		// Радиус по вертикали
	protected float		gpi_rh = 0;		// Радиус по горизонтали

	public gpi_ConcreteFactoryEllipse()
	{
		Console.WriteLine("     `-- constructor ellipse");
	}
}
