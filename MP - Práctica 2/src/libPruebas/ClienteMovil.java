package libPruebas;

public class ClienteMovil extends Cliente {
	private float minutosHablados;
	private float precioMinuto;
	private Fecha Permanencia;
	  

	public ClienteMovil(String nif, String nom, Fecha fNac, Fecha fAlta, Fecha fper, float min, float p_min) {
		super(nif, nom, fNac, fAlta);
		minutosHablados = min;
		precioMinuto = p_min;
		Permanencia = fper;
		
	}
	
	public ClienteMovil(String nif, String nom, Fecha fNac, Fecha fAlta, float min, float p_min) {
		this(nif,nom,fNac,fAlta, new Fecha(fAlta.getDia(),fAlta.getMes(),fAlta.getAnio()+1),min,p_min);		
	}
	
	public ClienteMovil(String nif, String nom, Fecha fNac, float min, float p_min) {
		this(nif,nom,fNac,getFechaPorDefecto(),min,p_min);
	}
	
	public ClienteMovil(ClienteMovil c) {
		super(c);
		minutosHablados = c.minutosHablados;
		precioMinuto = c.precioMinuto;
		Permanencia = c.Permanencia;
	}
	
	public float getminutosHablados() { return minutosHablados;	}
	public void setminutosHablados(float min) { minutosHablados = min; }
	
	public float getprecioMinuto() { return precioMinuto; }
	public void setprecioMinuto(float p_min) { precioMinuto = p_min; }
	
	public Fecha getFPermanencia() { return Permanencia; }
	public void setFPermanencia(Fecha Permanencia) { this.Permanencia = (Fecha) Permanencia.clone();}
	
	public float factura() { return minutosHablados*precioMinuto; }
	
	public String toString() {
		return super.toString()+" "+Permanencia+" "+minutosHablados+" x "+precioMinuto+" ---> "+factura();
	}
	
	public Object clone() {
		return new ClienteMovil(getNif(), getNombre(), getFechaNac(), getFechaAlta(), getFPermanencia(), getminutosHablados(), getprecioMinuto());
	}
	
	public boolean equals(Object c) {
		return c instanceof ClienteMovil && getNif().equals(((Cliente)c).getNif());
	}
	
	
	
}
