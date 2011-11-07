

// TO DRAW BASIC SHAPES


import java.io.*;
import java.awt.*;
import javax.swing.*;

abstract class Shape extends JFrame
{
   DataInputStream rd;
   int x,y;
   int a,b;
   Shape()
   {
     super("Shape");
     rd=new DataInputStream(System.in);
     setSize(500,500);
     x=100;
     y=100;
   }
}
 class Rect extends Shape
{
    Rect()
    {
         super();
         a=300;
         b=100;
    }
    Rect(int p,int q)
    {
       super();
       a=p;
       b=q;
     }
     public void paint(Graphics g)
     {
        super.paint(g);
        g.drawRect(x,y,a,b);
      }
}


class Squ extends Rect
{
    Squ(int p)
    {
         super(p,p);
    }
    public void paint(Graphics g)
    {
        super.paint(g);
    }
}


class ellipse extends Shape
{
   ellipse()
   {
      super();
      a=200;
      b=100;
   }
   ellipse(int p,int q)
   {
      super();
      a=p;
      b=q;
   }
   public void paint(Graphics g)
   {
       super.paint(g);
       g.drawOval(x,y,a,b);
   }
}


class circle extends ellipse
{
     circle(int p)
     {
          super(p,p);
     }
     public void paint(Graphics g)
     {
           super.paint(g);
     }
}


public class Shapes
{
    public static void main(String args[])
    {
        int a,b;
        DataInputStream rd=new DataInputStream(System.in);
        Shape sh=new Rect(0,0);
        int choice;
        while(true)
        {
              System.out.println("Main Menu\n 1.Rectangle\n 2.Square\n 3.Ellipse\n 4.Circle\n 5.Exit\n");
              System.out.println("Enter your choice : ");
              try
              {
                  choice=Integer.parseInt(rd.readLine());
              }
              catch(IOException e)
              {
                choice=0;
              }              
              switch(choice)
              {
              
              	case 1:System.out.println("\nEnter the length and breadth:");
              		try
              		{
              			a=Integer.parseInt(rd.readLine());
              			b=Integer.parseInt(rd.readLine());
              		}
              		catch(IOException e)
              		{
              			a=0;
              			b=0;
              		}
              		sh=new Rect(a,b);
              		break;
              	case 2:System.out.println("\nEnter the side:");
              		try
              		{
              			a=Integer.parseInt(rd.readLine());
              		}
              		 catch(IOException e)
              		 {
              		 	a=0;
              		 }
              		 sh=new Squ(a);
              		 break;
              	case 3:System.out.println("\nEnter the major and minor axis:");
              		try
              		{
              			a=Integer.parseInt(rd.readLine());
              			b=Integer.parseInt(rd.readLine());
              		}
              		catch(IOException e)
              		{
              			a=0;
              			b=0;
              		}
              		sh=new ellipse(a,b);
              		break;
              	case 4:System.out.println("\nEnter the radius:");
              		try
              		{
              			a=Integer.parseInt(rd.readLine());
              		}
              		catch(IOException e)
              		{
              			a=60;
              		}
              		sh=new circle(a);
              		break;
              	case 5:System.exit(0);
	}
              	sh.show();
        }
	}
}               
