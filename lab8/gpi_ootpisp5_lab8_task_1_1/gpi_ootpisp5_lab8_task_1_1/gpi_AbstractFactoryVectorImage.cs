using System;

public class gpi_AbstractFactoryVectorImage: gpi_AbstractFactoryObject
{
    public gpi_AbstractFactoryVectorImage()
    {
        Console.WriteLine("  `-- constructor vectorImage");
    }

    public gpi_ConcreteFactoryEllipse gpi_CreateEllipse()
    {
        return new gpi_ConcreteFactoryEllipse();
    }

    public gpi_ConcreteFactoryLine gpi_CreateLine()
    {
        return new gpi_ConcreteFactoryLine();
    }

    public gpi_ConcreteFactoryRectangle gpi_CreateRectangle()
    {
        return new gpi_ConcreteFactoryRectangle();
    }
}
