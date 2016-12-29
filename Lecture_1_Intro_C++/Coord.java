public class Coord
{

	private double xCoord, yCoord;

	public static void main(String [] args)
	{
		Coord c = new Coord();

		c.Initialize(10.0,4.2);

		c.Print();

		c.Reflect();

		c.Print();
	}

	public void Initialize(double xInit, double yInit)
	{
		xCoord = xInit;
		yCoord = yInit;
	}
	
	public void Reflect()
	{
		double temp = xCoord;
		xCoord = yCoord;
		yCoord = temp;
	}

	public void Print()
	{
		System.out.println(xCoord+", "+yCoord);
	}
}