import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.util.Scanner;
import java.lang.Integer;
import java.util.ArrayList;

public class LoaderAndLinker {
	private static ArrayList<String[]> ESTAB = new ArrayList<String[]>();
	private static ArrayList<String[]> program = new ArrayList<String[]>();
	private static ArrayList<String[]> relocationProgram = new ArrayList<String[]>();
	private static String ProLen = "000000";
	private static String StartAt = "4000";
	private static String memoryStartAt = null;
	private static String len = null;
	private static String control = null;
	private static int i = 0;
	private static int j = 0;
	private static int count = 0;
	private static int temp = Integer.parseInt("4000", 16);

	public static void main(String[] args) {
		Scanner file = null;
		int k = 1, m = 0;
		try {
			while (k <= 3) {
				file = new Scanner(new FileInputStream("./data/Program" + k + ".txt"));
				while (file.hasNext()) {
					String code = file.nextLine();
					onePass(code);
				}
				StartAt = Integer.toHexString(Integer.parseInt(StartAt, 16) + Integer.parseInt(ProLen, 16))
						.toUpperCase();
				file.close();
				k++;
			}
			k = 1;
			while (k <= 3) {
				file = new Scanner(new FileInputStream("./data/Program" + k + ".txt"));
				String test[];
				i = 0;
				String lastModiction = null;
				while (file.hasNext()) {
					String location = null;
					int by = 0;
					String code = file.nextLine();
					if (code.startsWith("T")) {
						test = code.split(" ");
						for (m = 2; m < test.length; m++) {
							String temp[] = new String[2];
							if (location == null) {
								location = test[1];
							} else {
								temp[0] = Integer.toHexString(Integer.parseInt(location, 16) + by).toUpperCase();
								temp[1] = test[m];
								location = temp[0];
								by = test[m].length() / 2;
								program.add(i, temp);
								i++;
							}

						}
					} else if (code.startsWith("M")) {
						test = code.split(" ");
						String temp = search(test[3].substring(1));
						if (lastModiction != null && lastModiction.equals(test[1])) {
							String reloction[] = new String[2];
							reloction = relocationProgram.get(j - 1);
							if (test[2].equals("05")) {
								String B = reloction[1].substring(0, 3);
								String A = reloction[1].substring(3);
								if (test[3].startsWith("+")) {
									A = String.format("%5s",
											Integer.toHexString(Integer.parseInt(A, 16) + Integer.parseInt(temp, 16))
													.toUpperCase())
											.replace(" ", "0");
								} else {
									A = String.format("%5s",
											Integer.toHexString(Integer.parseInt(A, 16) - Integer.parseInt(temp, 16))
													.toUpperCase())
											.replace(" ", "0");
								}
								reloction[1] = B + A;
							} else {
								if (test[3].startsWith("+")) {
									reloction[1] = String
											.format("%6x",
													Integer.parseInt(reloction[1], 16) + Integer.parseInt(temp, 16))
											.replace(" ", "0");
								} else {
									reloction[1] = String
											.format("%6x",
													Integer.parseInt(reloction[1], 16) - Integer.parseInt(temp, 16))
											.replace(" ", "0");
								}
								if (reloction[1].startsWith("1")) {
									reloction[1] = reloction[1].substring(1);
								}
							}
							relocationProgram.set(j - 1, reloction);
						} else {
							String reloction[] = new String[2];
							reloction = search(Integer.parseInt(test[1], 16));
							if (test[2].equals("05")) {
								String B = reloction[1].substring(0, 3);
								String A = reloction[1].substring(3);

								if (test[3].startsWith("+")) {
									A = String.format("%5s",
											Integer.toHexString(Integer.parseInt(A, 16) + Integer.parseInt(temp, 16))
													.toUpperCase())
											.replace(" ", "0");
								} else {
									A = String.format("%5s",
											Integer.toHexString(Integer.parseInt(A, 16) - Integer.parseInt(temp, 16))
													.toUpperCase())
											.replace(" ", "0");
								}
								reloction[1] = B + A;
							} else {
								if (test[3].startsWith("+")) {
									reloction[1] = String
											.format("%6x",
													Integer.parseInt(reloction[1], 16) + Integer.parseInt(temp, 16))
											.replace(" ", "0");
								} else {
									reloction[1] = String
											.format("%6x",
													Integer.parseInt(reloction[1], 16) - Integer.parseInt(temp, 16))
											.replace(" ", "0");
								}
								if (reloction[1].startsWith("1")) {
									reloction[1] = reloction[1].substring(1);
								}
							}
							relocationProgram.add(j, reloction);
							j++;
							lastModiction = test[1];
						}
					} else {
						if (code.startsWith("H")) {
							test = code.split(" ");
							len = test[3];
							control = test[1];
							creatLoadMap(test[1]);
						}
					}

				}
				creatLinking(control);
				file.close();
				program.clear();
				relocationProgram.clear();
				j = 0;
				k++;
				lastModiction = null;
			}

		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
	}

	public static void creatLoadMap(String controlSection) {
		String temp2[] = null;
		int m;
		try {
			FileWriter out = new FileWriter("./result/Load Map.txt", true);
			if (controlSection.indexOf("A") != -1) {
				out.write("Control \t Symbol    Address      Length\r\n");
			}
			for (m = 0; m < ESTAB.size(); m++) {
				temp2 = ESTAB.get(m);
				if (temp2[0].equals(controlSection)) {
					out.write(temp2[0] + " \t\t           " + temp2[1] + "\t \t" + len + "\r\n");
					memoryStartAt = temp2[1];
					break;
				}
			}
			for (int r = 1; r <= 2; r++) {
				temp2 = ESTAB.get(m + r);
				out.write(" \t\t " + temp2[0] + "\t   " + temp2[1] + "\r\n");
			}
			out.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}

	public static void creatLinking(String controlSection) {
		String temp2[] = null;
		int m;
		int flag = 0, cons = 0;
		try {

			FileWriter out = new FileWriter("./result/LinkingAndLoader.txt", true);
			if (controlSection.indexOf("A") != -1) {
				out.write("Memory \t\t\t Contents \r\n");
			}
			for (m = 0; m < program.size(); m++) {
				temp2 = program.get(m);
				while (temp != Integer.parseInt(temp2[0], 16) + Integer.parseInt(memoryStartAt, 16) && cons == 0) {
					if (count == 0) {
						out.write("\r\n");
						out.write(Integer.toHexString(temp) + "   **");
						count += 2;
						temp += Integer.parseInt("1", 16);
					} else if (count == 32) {
						count = 0;
					} else if (count % 8 == 0 && flag == 0) {
						out.write("  ");
						flag = 1;
					} else {
						out.write("**");
						flag = 0;
						count += 2;
						temp += Integer.parseInt("1", 16);
					}
				}
				if (count == 32) {
					count = 0;
				}
				if (temp - Integer.parseInt(memoryStartAt, 16) < Integer.parseInt(temp2[0], 16)) {
					cons = 0;
					m--;
					continue;
				}
				cons = 1;
				if (count == 0) {
					out.write("\r\n");
					out.write(Integer.toHexString(temp) + "   ");
				}
				if (count + temp2[1].length() > 32) {
					int t = 32 - count;
					out.write(temp2[1].substring(0, t) + "\r\n");
					count = 0;
					out.write(Integer.toHexString(temp) + "   " + temp2[1].substring(t));
					count = temp2[1].length() - t;
				} else {
					out.write(temp2[1]);
					count += temp2[1].length();
				}
				temp += Integer.parseInt(Integer.toHexString(temp2[1].length() / 2), 16);

			}
			out.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

	public static void onePass(String code) {
		String test[];
		int m = 0;
		test = code.split(" ");
		if (code.startsWith("H")) {
			String temp[] = new String[2];
			temp[0] = test[1];
			temp[1] = StartAt;
			ESTAB.add(i, temp);
			ProLen = test[3];
			i++;
		} else if (code.startsWith("D")) {
			for (m = 1; m < test.length; m += 2) {
				String temp[] = new String[2];
				temp[0] = test[m];
				temp[1] = Integer.toHexString(Integer.parseInt(StartAt, 16) + Integer.parseInt(test[m + 1], 16))
						.toUpperCase();
				ESTAB.add(i, temp);
				i++;
			}
		} else {
			return;
		}
	}

	public static String[] search(int location) {
		String temp2[] = null;
		int m;
		for (m = 0; m < program.size(); m++) {
			temp2 = program.get(m);
			int len = Integer.parseInt(temp2[0], 16) + (temp2[1].length() / 2);
			if (len > location && Integer.parseInt(temp2[0], 16) <= location) {
				return temp2;
			}
		}
		return null;
	}

	public static String search(String symbolName) {
		String temp2[] = null;
		int m;
		for (m = 0; m < ESTAB.size(); m++) {
			temp2 = ESTAB.get(m);
			if (temp2[0].equals(symbolName)) {
				return temp2[1];
			}
		}
		return null;
	}
}
