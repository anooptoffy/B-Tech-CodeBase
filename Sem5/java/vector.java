
// PROGRAM

import java.io.*;

class complex
{
	double re,im;
	complex(double r,double i)
	{
		re=r;
		im=i;
	}
	complex add(complex p)
	{
		complex q=new complex(0,0);
		q.re=re+p.re;
		q.im=im+p.im;
		return q;
	}
	complex mul(double s)
	{
		complex q=new complex(re,im);
		q.re=s*q.re;
		q.im=s*q.im;
		return q;
	}
	
	void display()
	{
		System.out.println(re+"+i"+im);
	}
}

abstract class basevector
{
	double rvector[];
	complex cvector[];
	DataInputStream rd;
	basevector()
	{
		rd=new DataInputStream(System.in);
	}
	public abstract basevector add(basevector p);
	public abstract void showvector();
	public abstract void scalarmul(double a);
	public abstract void readvector();
}

class realvector extends basevector
{
	private int i,n;
	realvector(int j)
	{
		super();
		rvector=new double[10];
		n=j;
		for(i=0;i<n;i++)
			rvector[i]=0;
	}
	public void readvector()
	{
		for(i=0;i<n;i++)
		{
			System.out.println("enter the"+(i+1)+"th component");
			try
			{
				rvector[i]=Integer.parseInt(rd.readLine());
			}
			catch(IOException e)
			{
				rvector[i]=0;
			}
		}
	}
	
	public basevector add(basevector p)
	{
		for(i=0;i<n;i++)
		{
			p.rvector[i]=rvector[i]+p.rvector[i];
		}
		return p;
	}
	
	public void scalarmul(double a)
	{
		for(i=0;i<n;i++)
		{
			rvector[i]=rvector[i]*a;
		}
	}
	
	public void showvector()
	{
		System.out.print("(");
		for(i=0;i<n;i++)
		{
			System.out.print(rvector[i]);
			if(i!=(n-1))
				System.out.print(",");
		}
		
		System.out.print(")");
	}
}


class Cvector extends basevector
{
	private int i;
	private int j,n;
	int r,im;
	Cvector(int k)
	{
		super();
		cvector = new complex[10];
		n=k;
		for(i=0;i<n;i++)
			cvector[i]=new complex(0,0);
	}
	
	public void readvector()
	{
		for(i=0;i<n;i++)
		{
			System.out.println("enter the "+(i+1)+"component");
			try
			{
				r=Integer.parseInt(rd.readLine());
				im=Integer.parseInt(rd.readLine());
			}
			catch(IOException e)
			{
				r=0;
				im=0;
			}
			
			cvector[i]=new complex(r,im);
		}
	}
	
	public basevector add(basevector p)
	{
		Cvector c=new Cvector(n);
		for(i=0;i<n;i++)
		{
			c.cvector[i]=cvector[i].add(p.cvector[i]);
		}
		return c;
	}
	
	public void scalarmul(double a)
	{
		for(i=0;i<n;i++)
		{
			cvector[i]=cvector[i].mul(a);
			
		}
	}
	
	public void showvector()
	{
		System.out.print("(");
		for(i=0;i<n;i++)
		{
			cvector[i].display();
			System.out.print(",");
		}
		System.out.print(")");
	}
}

public class vector
{
	public static void main(String args[])
	
	throws NumberFormatException,IOException
	
	{
		DataInputStream rd=new DataInputStream(System.in);
		int choice1,choice2,n;
		double r,im;
		basevector r1,r2;
		while(true)
		{
			System.out.println("menu\n1.real vector\n2.complex vector\n3.exit\n");
			choice1=Integer.parseInt(rd.readLine());
			
			switch(choice1)
			{
				case 1:
					System.out.println("enter the dimension");
					n=Integer.parseInt(rd.readLine());
					
					r1=new realvector(n);
					r1.readvector();
					
					a: while(true)
						{
							System.out.println("\n1.add\n2.scalar mul\n3.dispaly\n4.back\t");
							choice2=Integer.parseInt(rd.readLine());
							
							switch(choice2)
							{
								case 1:
									System.out.println("enter a vector of dimension "+n);
									r2=new realvector(n);
									r2.readvector();
									r1=r1.add(r2);
									r1.showvector();
									break;
								case 2:
									System.out.println("enter a scalar");
									r=Integer.parseInt(rd.readLine());
									r1.scalarmul(r);
									r1.showvector();
									break;
								case 3:
									r1.showvector();
									break;
								case 4: 
									break a;
							}
						}
						break;
				case 2:
					System.out.println("enter the dimension");
					n=Integer.parseInt(rd.readLine());
					r1=new Cvector(n);
					r1.readvector();
					b: while(true)
						{
							System.out.println("1.add\n2.scalarmul\n3.display\n4.back\n");
							choice2=Integer.parseInt(rd.readLine());
							switch(choice2)
							{
								case 1:
									System.out.println("enter a vector of dimension"+n);
									r2=new Cvector(n);
									r2.readvector();
									r1=r1.add(r2);
									r1.showvector();
									break;
								case 2:
									System.out.println("enter a scalar");
									r=Integer.parseInt(rd.readLine());
									r1.scalarmul(r);
									r1.showvector();
									break;
								case 3:
									r1.showvector();
									break;
								case 4:
									break b;
							}
						}
						break;
				case 3:
					System.exit(0);
			}
		}
	}
}
		
					
