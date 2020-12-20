package libPruebas;
import java.util.Scanner;
public final class Fecha implements Cloneable, Proceso {
	private int dia; 
	private int mes;
	private int anio;
	
	public void setFecha(int d, int m, int a) {
		int dmax, diaMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		anio = a;
		if(m < 1)
			m = 1;
		else if (m > 12)
			m = 12;
		dmax = diaMes[m-1];
		if(m == 2 && bisiesto())
			dmax++;
		if(d > dmax)
			d = dmax;
		else if(d < 1)
			d = 1;
		dia = d;
		mes = m;
	}
	
	public Fecha(int dia, int mes, int anio) {setFecha(dia,mes,anio);}
	
	public Fecha(Fecha f) {
		this(f.dia,f.mes,f.anio);
	}
	
	public int getDia() {return dia;}
	public int getMes() {return mes;}
	public int getAnio() {return anio;}
	
	public String toString() {
		return String.format("%02d/%02d/%02d", dia, mes, anio); //Sacar por pantalla dia/mes/anio
	}
	
	public boolean bisiesto() {
		boolean b = false;
		if(anio % 4 == 0) {
			b = true;
			if(anio % 100 == 0 && anio % 400 != 0)
				b = false;
		}
		return b;
	}
	
	public void ver() { System.out.println(this);}
	
	public static Fecha pedirFecha() {
		Fecha fecha = null;
		boolean valida = false;
		Scanner sc = new Scanner(System.in);
		int dia,mes,anio;
		do {
			System.out.println("Introduce la Fecha (dd/mm/aaaa): ");
			String cadena = sc.next();
			String[] tokens = cadena.split("/");
			try {
				if(tokens.length != 3)
					throw new NumberFormatException();
				
				dia = Integer.parseInt(tokens[0]); 
				mes = Integer.parseInt(tokens[1]); 
				anio = Integer.parseInt(tokens[2]); 
				
				fecha = new Fecha(dia,mes,anio);
				
				if(fecha.getDia() != dia || fecha.getMes() != mes)
					throw new NumberFormatException();
				valida = true;
			}catch(NumberFormatException e) {
				System.out.println("Fehca no valida");
			}
		}while(!valida);
		sc.close();
		return fecha;
	}
	
	static public boolean mayor(Fecha f1, Fecha f2) {
		int f1_total = f1.anio*1000+f1.mes*100+f1.dia;
		int f2_total = f2.anio*1000+f2.mes*100+f2.dia;
		
		return (f1_total > f2_total);
	}
	
	public Object clone() {
		Object obj = null;
		try {obj = super.clone();
		}catch(CloneNotSupportedException ex) { System.out.println(" no se puede duplicar"); }
		return obj;
	}
	
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(getClass() != obj.getClass())
			return false;
		Fecha c = (Fecha) obj;
		return (dia == c.dia && mes == c.mes && anio == c.anio);
	}

	public Fecha diaSig() {
		
		Fecha f = (Fecha)clone();	        
	    f.dia ++;

	     int diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	     if(bisiesto())
	    	 diaMes[2] = 29;
	     
	     if(f.dia > diaMes[f.mes]){
	    	 f.dia -= diaMes[f.mes];
	    	 f.mes++;
	    	 if(f.mes > 12){
	    		 f.mes = 1;
	    		 f.anio++;
	         }
	     }	        
	     return f;
	}

	public void setFecha(Fecha f) {
		dia = f.dia;
		mes = f.mes;
		anio = f.anio;
		
	}
	
	
}
