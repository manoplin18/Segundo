package libPruebas;

public class ClienteTarifaPlana extends Cliente {
	private static float tarifa = 20f;
	private static float precioExcesoMinuto = 0.15f; 
	private static int minutosTP = 300;
	
	private float minutosHablados;
	private String nacionalidad;
	
	public ClienteTarifaPlana(String nif,String nom, Fecha fNac,Fecha fAlta, float min, String nac) {
		super(nif,nom,fNac,fAlta);
		minutosHablados = min;
		nacionalidad = nac;
		
	}
	public ClienteTarifaPlana(String nif,String nom, Fecha fNac, float min, String nac) {
		super(nif,nom,fNac);
		minutosHablados = min;
		nacionalidad = nac;
		
	}
	
	public float getMinutos() { return minutosHablados; }
	public void setMinutos(float min) { minutosHablados = min; }
	
	public String getNacionalidad() { return nacionalidad; }
	public void setNacionalidad(String nac) { nacionalidad = nac; }
	
	public static float getTarifa() { return tarifa; }
	public static void setTarifa(int min, float tar) {
		minutosTP = min;
    	tarifa = tar;
    }
	
	public static int getLimite() { return minutosTP; }
	
	public static float getPrecioExcesoMinuto() { return precioExcesoMinuto; }
	
	public float factura() {
		float exceso_min;
		if(minutosTP > minutosHablados)
			exceso_min = 0;
		else 
			exceso_min = minutosHablados - minutosTP;
		return tarifa + (precioExcesoMinuto * exceso_min);
	}
	
	public Object clone() {
		return new ClienteTarifaPlana(getNif(), getNombre(), getFechaNac(), getFechaAlta(), getMinutos(), getNacionalidad());
	}
	
	public boolean equals(Object obj) {
		return obj instanceof ClienteTarifaPlana && getNif().equals(((Cliente)obj).getNif());
	}
	
	public String toString() {
		return (super.toString()+" "+nacionalidad+" ["+minutosTP+" por "+tarifa+"] "+minutosHablados+" ---> "+factura());
	}
	
	
}
