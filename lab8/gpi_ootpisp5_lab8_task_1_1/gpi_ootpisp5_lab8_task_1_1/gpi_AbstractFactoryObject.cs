using System;

public class gpi_AbstractFactoryObject
{
    public gpi_AbstractFactoryObject()
    {
        Console.WriteLine(" \n . constructor object");
    }

    public gpi_AbstractFactoryBitmapImage gpi_CreateBitmap(string gpi_option = "")
    {
        if (gpi_option == "text")
        {
            return new gpi_ConcreteFactoryText();
        }

        return new gpi_AbstractFactoryBitmapImage();
    }
	public gpi_AbstractFactoryVectorImage gpi_CreateVector(string gpi_option = "")
    {
        if (gpi_option == "line")
        {
            return new gpi_ConcreteFactoryLine();
        }

        if (gpi_option == "rectangle")
        {
            return new gpi_ConcreteFactoryRectangle();
        }

        if (gpi_option == "ellipse")
        {
            return new gpi_ConcreteFactoryEllipse();
        }

        return new gpi_AbstractFactoryVectorImage();
    }
}
