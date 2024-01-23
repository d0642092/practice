
public class OPTAB {

	private String mnemonic;
	private String opCode;
	private int format;

	public OPTAB() {
		this.mnemonic = "N/A";
		this.opCode = "N/A";
		this.format = 2;
	}

	public void setAll(String mnemonic, int format, String opCode) {
		this.mnemonic = mnemonic;
		this.opCode = opCode;
		this.format = format;
	}

	public String getMnemonic() {
		return this.mnemonic;
	}

	public String getOpCode() {
		return this.opCode;
	}

	public int getFormat() {
		return this.format;
	}

	public boolean equals(String others) {
		return this.mnemonic.equals(others);
	}

	public String toString() {
		return this.mnemonic + " " + this.format + " " + this.opCode;
	}
}
