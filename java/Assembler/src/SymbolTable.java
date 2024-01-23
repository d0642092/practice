import java.lang.Integer;

public class SymbolTable {
	static String nowLocation;
	static String[] LOCCTR = new String[100];
	static int m = 0;
	private String labelName;
	private String locationCounter;

	public SymbolTable() {
		this.labelName = "N/A";
		this.locationCounter = "N/A";
	}

	public void setLabelName(String label) {
		this.labelName = label;
	}
//	private static void printData(ArrayList<OPTAB> operation, ArrayList<SymbolTable> symTab,
//	ArrayList<String> objectCode) {
////System.out.println("OPCODE");
////for(j=0;j<operation.size();j++) {
////	System.out.println(operation.get(j));
////}
////System.out.println("\nLOCCTR");
////for(j=0;j<SymbolTable.m;j++) {
////	System.out.println(SymbolTable.LOCCTR[j]);
////}
//////System.out.println("\nSyMTAB");
////for(j=0;j<symTab.size();j++) {
////	System.out.println(symTab.get(j));
////}
////System.out.println("\nobjectCode");
////for(j=0;j<objectCode.size();j++) {
////	System.out.println(objectCode.get(j));
////}
////
////System.out.println("\nnowLocation " + SymbolTable.nowLocation);
//
//}
//
//private static void printObjectCode(ArrayList<String> objectCode) {
//System.out.println("\nobjectCode");
//for (j = 0; j < objectCode.size(); j++) {
//	System.out.println(objectCode.get(j));
//}
//}
	public void setLocationCouter(String counter) {
		this.locationCounter = Integer.toHexString(Integer.parseInt(nowLocation, 16) + Integer.parseInt(counter, 16));
		LOCCTR[m++] = locationCounter;
		nowLocation = locationCounter;
	}

	public void setLocationCouter(OPTAB command) {
		this.locationCounter = Integer.toHexString(Integer.parseInt(nowLocation, 16) + command.getFormat());
		LOCCTR[m++] = locationCounter;
		nowLocation = locationCounter;

	}

	public void setAll(String label, String counter) {
		this.labelName = label;
		this.locationCounter = counter;
		LOCCTR[m++] = locationCounter;
		nowLocation = locationCounter;
	}

	public String getLocationCount(OPTAB command) {
		return Integer.toHexString(Integer.parseInt(nowLocation, 16) + command.getFormat());
	}

	public String toString() {
		return this.labelName + " " + this.locationCounter + "\r\n";
	}
}
