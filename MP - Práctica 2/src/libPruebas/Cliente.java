package libPruebas;

public class Cliente implements Cloneable, Proceso {
		
		private final String nif;
		private final int codCliente;
		private String nombre;
		private final Fecha FechaNac;		
		private final Fecha FechaAlta;
		
		private static int contadorCliente = 1;
		private static final Fecha fecha_defecto = new Fecha(1,1,2018);
		
		public Cliente (String NIF, String nom, Fecha fNac, Fecha fAlta){
			nif = NIF;
			nombre = nom;
			FechaNac = fNac;
			FechaAlta = fAlta;
			codCliente = contadorCliente++;
		}
		
		public Cliente (String NIF, String nom, Fecha fNac){
			this(NIF,nom,fNac,fecha_defecto);
		}

		public Cliente(Cliente c) {
			this(c.nif,c.nombre,c.FechaNac,c.FechaAlta);
		}

		public String getNombre() { return nombre;}
		public void setNombre(String nom) {nombre = nom;}
		
		public Fecha getFechaAlta() {return (Fecha) FechaAlta.clone();}
		public void setFechaAlta(Fecha f) { FechaAlta.setFecha(f);}
		public void setFechaAlta(int d, int m, int a) {FechaAlta.setFecha(d, m, a);}
		
		public static Fecha getFechaPorDefecto() {return (Fecha) fecha_defecto.clone();		}
		public static  void setFechaPorDefecto(Fecha f) {fecha_defecto.setFecha(f);}
		
		public Fecha getFechaNac() { return FechaNac;}
		
		public String getNif() { return nif;}

		public void ver() {
			System.out.println(nif + " " + FechaNac + ": "+ nombre + "(" + codCliente + " - " + FechaAlta);
			
		}
		
		public String toString(){
	        return (nif+" "+FechaNac+": "+nombre+" ("+codCliente+" - "+FechaAlta+")");
		}
		
		public Object clone() {
			 return new Cliente(this);
		}
		
		public boolean equals(Object c){
	        return c.getClass() == Cliente.class && nif.equals(((Cliente)c).nif);
	    }
			
}

//*******Preguntas*******


/*public Object clone() {
Cliente c = new Cliente(this);
return c;
}*/
