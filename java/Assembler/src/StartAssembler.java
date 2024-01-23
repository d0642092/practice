import java.lang.Integer;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.io.FileWriter;

//依規定格式於期限內上傳至網路教室。
//作業格式如下：
//封面：作業題目、原班級、學號、姓名 
//作法：題目定義、資料結構及演算法說明 
//程式碼 
//執行結果：測試資料及結果 
//討論：遭遇困難及解決過程 
//心得：自由發揮

public class StartAssembler {
	private static int j = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {

			// creat OPCODE
			Scanner fileOp = null;
			fileOp = new Scanner(new FileInputStream("./data/op.txt"));
			ArrayList<OPTAB> operation = new ArrayList<OPTAB>();

			while (fileOp.hasNext()) {
				OPTAB nowOprate = new OPTAB();
				String mnemonic = fileOp.next();
				int format = fileOp.nextInt();
				String opCode = fileOp.next();
				nowOprate.setAll(mnemonic, format, opCode);
				operation.add(nowOprate);

			}
			fileOp.close();

			// Input file
			Scanner fileIn = null;
			fileIn = new Scanner(new FileInputStream("./data/INPUT.txt"));

			String command;
			ArrayList<SymbolTable> symTab = new ArrayList<SymbolTable>();

			ArrayList<String> objectCode = new ArrayList<String>();
			String lastCommand = null;
			String lastNumber = null;
			OPTAB lastMnemonic = null;

			while (fileIn.hasNextLine()) {
				command = fileIn.nextLine();
				String[] test = command.split(" ", 3);
				SymbolTable nowLabel = new SymbolTable();

				if (command.indexOf("START") != -1) {
					nowLabel.setAll(test[0], test[2]);
					symTab.add(nowLabel);
					lastCommand = "START";
					lastNumber = test[2];
					objectCode.add(null);
				}

				else if (command.indexOf("END") != -1) {
					switch (lastCommand) {
					case "WORD":
						SymbolTable.nowLocation = Integer
								.toHexString(Integer.parseInt(SymbolTable.nowLocation, 16) + 3);
						break;
					case "RESW":
						SymbolTable.nowLocation = Integer.toHexString((Integer.parseInt(lastNumber) * 3));
						break;
					default:
						break;
					}
					objectCode.add(null);
				}

				else {
					if (test.length == 3) {
						j = 0;
						nowLabel.setLabelName(test[0]);
						while (j < operation.size()) {
							if (operation.get(j).getMnemonic().equals(test[1])) {
								if (lastCommand == "START") {
									nowLabel.setLocationCouter(lastNumber);
									lastMnemonic = operation.get(j);
									symTab.add(nowLabel);
									lastCommand = null;
									objectCode.add(null);
								} else {
									nowLabel.setLocationCouter(lastMnemonic);
									lastMnemonic = operation.get(j);
									symTab.add(nowLabel);
									objectCode.add(null);
								}
								break;
							}
							j++;
						}
						switch (test[1]) {
						case "WORD":
							if (lastMnemonic != null) {
								nowLabel.setLocationCouter(Integer.toHexString(lastMnemonic.getFormat()));
							} else {
								switch (lastCommand) {
								case "WORD":
									nowLabel.setLocationCouter("3");
									break;
								case "RESW":
									nowLabel.setLocationCouter(Integer.toHexString((Integer.parseInt(lastNumber) * 3)));
									break;
								default:
									break;
								}
							}
							lastCommand = "WORD";
							lastNumber = null;
							lastMnemonic = null;
							symTab.add(nowLabel);
							if (Integer.toHexString(Integer.parseInt(test[2])).length() > 6) {
								objectCode.add(Integer.toHexString(Integer.parseInt(test[2]))
										.substring(Integer.toHexString(Integer.parseInt(test[2])).length() - 6));
							} else {
								objectCode.add(String.format("%6s", Integer.toHexString(Integer.parseInt(test[2])))
										.replace(" ", "0"));
							}

							break;
						case "RESW":
							if (lastMnemonic != null) {
								nowLabel.setLocationCouter(Integer.toHexString(lastMnemonic.getFormat()));
							} else {
								switch (lastCommand) {
								case "WORD":
									nowLabel.setLocationCouter("3");
									break;
								case "RESW":
									nowLabel.setLocationCouter(Integer.toHexString((Integer.parseInt(lastNumber) * 3)));
									break;
								default:
									break;
								}
							}
							lastCommand = "RESW";
							lastNumber = test[2];
							lastMnemonic = null;
							symTab.add(nowLabel);
							objectCode.add(null);
							break;
						default:
							break;
						}

					} else {
						j = 0;
						while (j < operation.size()) {
							if (operation.get(j).getMnemonic().equals(test[0])) {
								break;
							}
							j++;
						}
						if (j < 7) {
							SymbolTable.LOCCTR[SymbolTable.m++] = nowLabel.getLocationCount(lastMnemonic);
							SymbolTable.nowLocation = SymbolTable.LOCCTR[SymbolTable.m - 1];
							lastMnemonic = operation.get(j);
							objectCode.add(null);

						}
					}
				}
			}
			//StartAssembler.printData(operation, symTab, objectCode);

			fileIn.close();

			// SymbolTable output;
			FileOutputStream symTable = new FileOutputStream("./data/SymbolTable.txt");
			byte[] bytes = null;
			int j = 0;
			while (j < symTab.size()) {
				bytes = symTab.get(j).toString().getBytes();
				symTable.write(bytes);
				symTable.flush();
				j++;
			}
			symTable.close();

			StartAssembler.creatObjectCode(objectCode);
		} catch (Exception e) {
			// TODO: handle exception
			e.getMessage();
			System.exit(0);
		}

	}


	private static void creatObjectCode(ArrayList<String> objectCode) {
		try {
			j = 0;
			Object obCode = new Object();
			long PC;
			long TA = 0;
			Scanner programCode = null;
			programCode = new Scanner(new FileInputStream("./data/INPUT.txt"));
			Scanner register = null;
			register = new Scanner(new FileInputStream("./data/register.txt"));
			Scanner symbolTab = null;
			symbolTab = new Scanner(new FileInputStream("./data/SymbolTable.txt"));
			Scanner OPCode = null;
			OPCode = new Scanner(new FileInputStream("./data/op.txt"));
			String command = null;
			String symbol = null;
			String[] TAtest = null;
			int flag = 0;

			while (programCode.hasNextLine()) {
				command = programCode.nextLine();
				String[] test = command.split(" ", 3);

				obCode.setOpCode(null);
				obCode.reset();
				if (command.indexOf("START") != -1) {
					j++;
					continue;
				} else if (command.indexOf("END") != -1) {
					break;
				} else {
					if (objectCode.get(j) == null) {
						PC = Long.parseLong(SymbolTable.LOCCTR[j + 1], 16);
						if (test.length == 3) {
							while (OPCode.hasNextLine()) {
								String opcode = OPCode.nextLine();
								String[] OPtest = opcode.split(" ", 3);
								if (OPtest[0].equals(test[1])) {

									obCode.setOpCode(OPtest[2]);

									if (OPtest[1].equals("2")) {
										String regis = null;
										String[] reTest = null;
										if (test[2].indexOf(",") != -1) {
											String one = null;
											String two = null;
											String[] reg = test[2].split(",");
											while (register.hasNextLine()) {
												regis = register.nextLine();
												reTest = regis.split(" ", 2);

												if (test[2].indexOf(reTest[0]) != -1) {
													System.out.println(reg[0] + reg[1] + reTest[0] + "\n\n");
													if (reTest[0].equals(reg[0])) {
														one = reTest[1];
														continue;
													} else if (reTest[0].equals(reg[1])) {
														two = reTest[1];
														continue;
													} else {
														continue;
													}
												}
												objectCode.set(j, obCode.getOpCode() + one + two);
												flag = 1;
												break;
											}
										} else {
											while (register.hasNextLine()) {
												regis = register.nextLine();
												reTest = regis.split(" ", 2);
												if (test[2].indexOf(reTest[0]) != -1) {
													objectCode.set(j, obCode.getOpCode() + reTest[1] + "0");
													flag = 1;
													break;
												}
											}
										}
									}
									break;
								}
							}
							if (obCode.getOpCode() == null) {
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								j++;
								continue;
							}
							if (flag == 1) {
								register.close();
								register = new Scanner(new FileInputStream("./data/register.txt"));
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								j++;
								flag = 0;
								continue;
							}
							if (test[1].indexOf("+") != -1) {
								obCode.setE("1");
								while (symbolTab.hasNextLine()) {
									symbol = symbolTab.nextLine();
									TAtest = symbol.split(" ", 2);
									if (test[2].indexOf(",") != -1) {
										String findLabel[] = test[2].split(",");
										if (symbol.indexOf(findLabel[0]) != -1) {
											TA = Long.parseLong(TAtest[1], 16);
											break;
										} else {
											continue;
										}
									}
									if (symbol.indexOf(test[2]) != -1) {
										TA = Long.parseLong(TAtest[1], 16);
										break;
									}
								}

								long x = Long.parseLong(obCode.getOpCode(), 16);
								long y = Long.parseLong(obCode.getNI(), 2);

								String OPNI = String.format("%2s", Long.toHexString(x + y)).replace(" ", "0");
								String NIXP = Integer.toHexString(Integer.parseInt(obCode.getXBPE(), 2));
								String disp = String.format("%5s", Long.toHexString(TA).replace(" ", "0"));
								objectCode.set(j, OPNI + NIXP + disp);

								j++;
								symbolTab.close();
								symbolTab = new Scanner(new FileInputStream("./data/SymbolTable.txt"));
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								obCode.reset();
								continue;
							}
							if (test[2].indexOf("X") != -1) {
								obCode.setX("1");
							}
							if (test[2].indexOf("@") != -1) {
								obCode.setNI("1", "0");
							}
							if (test[2].indexOf("#") != -1) {
								obCode.setNI("0", "1");
								obCode.setDisp(test[2].substring(1));
								objectCode.set(j, StartAssembler.setObjectCode(obCode));
								j++;
								obCode.reset();
								continue;
							}
							while (symbolTab.hasNextLine()) {
								symbol = symbolTab.nextLine();
								TAtest = symbol.split(" ", 2);
								if (test[2].indexOf(",") != -1) {
									String findLabel[] = test[2].split(",");

									if (symbol.indexOf(findLabel[0]) != -1) {
										TA = Long.parseLong(TAtest[1], 16);
										break;
									} else {
										continue;
									}
								}
								if (symbol.indexOf(test[2]) != -1) {
									TA = Long.parseLong(TAtest[1], 16);
									break;
								}
							}

							obCode.setDisp(Long.toHexString(TA - PC));
							objectCode.set(j, StartAssembler.setObjectCode(obCode));

							j++;
						} else {
							while (OPCode.hasNextLine()) {
								String opcode = OPCode.nextLine();
								String[] OPtest = opcode.split(" ", 3);
								if (OPtest[0].equals(test[0])) {
									obCode.setOpCode(OPtest[2]);

									if (OPtest[1].equals("2")) {
										String regis = null;
										String[] reTest = null;
										if (test[1].indexOf(",") != -1) {
											while (register.hasNextLine()) {
												regis = register.nextLine();
												reTest = regis.split(" ", 2);
												String[] reg = test[1].split(",");
												String one = null;
												String two = null;
												if (test[1].indexOf(reTest[0]) != -1) {
													if (reTest[0].equals(reg[0])) {
														one = reTest[1];
													} else if (reTest[0].equals(reg[1])) {
														two = reTest[1];
													} else {
														continue;
													}
													objectCode.set(j, obCode.getOpCode() + one + two);
													flag = 1;
													break;
												}
											}
										} else {
											while (register.hasNextLine()) {
												regis = register.nextLine();
												reTest = regis.split(" ", 2);
												if (test[1].indexOf(reTest[0]) != -1) {
													objectCode.set(j, obCode.getOpCode() + reTest[1] + "0");
													flag = 1;
													break;
												}
											}
										}
									}
									break;
								}
							}
							if (obCode.getOpCode() == null) {
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								j++;
								continue;
							}

							if (flag == 1) {
								register.close();
								register = new Scanner(new FileInputStream("./data/register.txt"));
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								j++;
								flag = 0;
								continue;
							}

							if (test[0].indexOf("+") != -1) {
								obCode.setE("1");
								while (symbolTab.hasNextLine()) {
									symbol = symbolTab.nextLine();
									TAtest = symbol.split(" ", 2);
									if (test[1].indexOf(",") != -1) {
										String findLabel[] = test[1].split(",");
										if (symbol.indexOf(findLabel[0]) != -1) {
											TA = Long.parseLong(TAtest[1], 16);
											break;
										} else {
											continue;
										}
									}
									if (symbol.indexOf(test[1]) != -1) {
										TA = Long.parseLong(TAtest[1], 16);
										break;
									}
								}

								long x = Long.parseLong(obCode.getOpCode(), 16);
								long y = Long.parseLong(obCode.getNI(), 2);

								String OPNI = String.format("%2s", Long.toHexString(x + y)).replace(" ", "0");
								String NIXP = Integer.toHexString(Integer.parseInt(obCode.getXBPE(), 2));
								String disp = String.format("%5s", Long.toHexString(TA)).replace(" ", "0");

								objectCode.set(j, OPNI + NIXP + disp);

								j++;
								symbolTab.close();
								symbolTab = new Scanner(new FileInputStream("./data/SymbolTable.txt"));
								OPCode.close();
								OPCode = new Scanner(new FileInputStream("./data/op.txt"));
								obCode.reset();
								continue;
							}
							if (test[1].indexOf("@") != -1) {
								obCode.setNI("1", "0");
							}
							if (test[1].indexOf("#") != -1) {
								obCode.setNI("0", "1");
								obCode.setDisp(test[1].substring(1));
								objectCode.set(j, StartAssembler.setObjectCode(obCode));
								j++;
								obCode.reset();
								continue;
							}

							while (symbolTab.hasNextLine()) {
								symbol = symbolTab.nextLine();
								TAtest = symbol.split(" ", 2);
								if (symbol.indexOf(test[1]) != -1) {
									TA = Long.parseLong(TAtest[1], 16);
									break;
								}
							}

							obCode.setDisp(Long.toHexString(TA - PC));
							objectCode.set(j, StartAssembler.setObjectCode(obCode));
							j++;
						}

					} else {
						j++;
						continue;
					}

				}
				symbolTab.close();
				symbolTab = new Scanner(new FileInputStream("./data/SymbolTable.txt"));
				OPCode.close();
				OPCode = new Scanner(new FileInputStream("./data/op.txt"));
				obCode.reset();

			}

			//StartAssembler.printObjectCode(objectCode);
			OPCode.close();
			symbolTab.close();
			register.close();
			j = 0;
			programCode.close();

			programCode = new Scanner(new FileInputStream("./data/INPUT.txt"));
			FileWriter out = null;
			out = new FileWriter("./result/Program.txt");
			out.write("LOCCTR" + "\t\t" + "programsourse" + "\t\t" + "objectCode" + "\r\n");
			SymbolTable.LOCCTR[0] = null;
			while (programCode.hasNextLine()) {
				command = programCode.nextLine();
				String temp = String.format("%4s", SymbolTable.LOCCTR[j]).replace(" ", "0");
				if (SymbolTable.LOCCTR[j] == null & objectCode.get(j) == null) {
					String comtemp = String.format("%28s", command).replaceFirst("#", "#");
					out.write(comtemp + "\r\n");
					j++;
					continue;
				} else if (objectCode.get(j) == null) {
					out.write(temp + "\t\t" + command + "\r\n");
					j++;
					continue;
				} else if (SymbolTable.LOCCTR[j] == null) {
					out.write(command + objectCode.get(j) + "\r\n");
					j++;
					continue;
				} else {

					out.write(temp + "\t\t" + command + "\t\t" + objectCode.get(j) + "\r\n");
					j++;
					continue;
				}
			}
			out.close();
			programCode.close();
			programCode = new Scanner(new FileInputStream("./data/INPUT.txt"));
			out = new FileWriter("./result/ObjectCode.txt");
			j = 1;
			int k = 0;
			String begin = SymbolTable.LOCCTR[1];

			command = programCode.nextLine();
			String[] test = command.split(" ", 3);

			String temp = String.format("%6s", SymbolTable.LOCCTR[1]).replace(" ", "0");
			String temp1 = String.format("%6s", SymbolTable.nowLocation).replace(" ", "0");
			out.write("H " + test[0] + "  " + temp + "  " + temp1 + "\r\n");

			ArrayList<String> obTemp = new ArrayList<String>();
			int init = 0;
			flag = 0;

			while (j != objectCode.size() - 1 & objectCode.size() - j >= 10) {
				while (objectCode.get(j) != null & k < 10) {
					obTemp.add(objectCode.get(j));
					k++;
					j++;
				}
				String max = Integer
						.toHexString(Integer.parseInt(SymbolTable.LOCCTR[k + 1], 16) - Integer.parseInt(begin, 16));

				out.write("T " + begin + " " + max + " ");
				for (int d = 0; d < obTemp.size(); d++) {
					out.write(obTemp.get(d) + " ");
				}
				out.write("\r\n");
				begin = Integer.toHexString(Integer.parseInt(max, 16) + Integer.parseInt(begin, 16));

				System.out.println(begin);

			}
			String max = Integer
					.toHexString(Integer.parseInt(SymbolTable.nowLocation, 16) - Integer.parseInt(begin, 16));
			out.write("T " + begin + " " + max + " ");
			for (int d = j; d < objectCode.size(); d++) {
				if (objectCode.get(d) == null) {
					continue;
				}
				out.write(objectCode.get(d) + " ");
			}
			out.write("\r\n");

			out.write("E " + "  " + temp);
			out.close();
			programCode.close();

		} catch (Exception e) {
			// TODO: handle exception
			e.getMessage();
			System.exit(0);
		}

	}

	public static String setObjectCode(Object obcode) {
		long x = Long.parseLong(obcode.getOpCode(), 16);
		long y = Long.parseLong(obcode.getNI(), 2);

		String OPNI = String.format("%2s", Long.toHexString(x + y)).replace(" ", "0");
		String NIXP = Integer.toHexString(Integer.parseInt(obcode.getXBPE(), 2));
		String disp = null;

		if (obcode.getDisp().length() > 3) {
			disp = obcode.getDisp().substring(obcode.getDisp().length() - 3);
		} else {
			disp = String.format("%3s", Integer.toHexString(Integer.parseInt(obcode.getDisp(), 16))).replace(" ", "0");
		}
		return OPNI + NIXP + disp;
	}
}
