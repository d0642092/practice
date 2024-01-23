import java.lang.Integer;
import java.util.ArrayList;
public class Object {
	private String opCode;
	private String n;
	private String i;
	private String x;
	private String b;
	private String p;
	private String e;
	private String disp;

	public Object() {
		this.opCode = null;
		this.n = "1";
		this.i = "1";
		this.x = "0";
		this.b = "0";
		this.p = "1";
		this.e = "0";
		this.disp = null;
	}

	public void setOpCode(String opCode) {
		this.opCode = opCode;
	}

	public void setNI(String n, String i) {
		this.n = n;
		this.i = i;
	}

	public void setX(String x) {
		this.x = x;
	}

	public void setB(String b) {
		this.b = b;
	}

	public void setP(String p) {
		this.p = p;
	}

	public void setE(String e) {
		this.e = e;
	}

	public void setDisp(String disp) {
		this.disp = disp;
	}


	public void reset() {
		this.n = "1";
		this.i = "1";
		this.x = "0";
		this.b = "0";
		this.p = "1";
		this.e = "0";
	}

	public String getOpCode() {
		return this.opCode;
	}

	public String getNI() {
		return "00" + this.n + this.i;
	}

	public String getXBPE() {
		return this.x + this.b + this.p + 
				this.e;
	}

	public String getDisp() {
		return this.disp;
	}

	public String toString() {
		return this.opCode + this.getNI() +
				this.x + this.b + this.p + 
				this.e + this.disp;
	}
}
