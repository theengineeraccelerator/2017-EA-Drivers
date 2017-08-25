#define REGISTER 0xDB
#define REFRESH 8
#define VCHG 5
#define MODEL_ID_MASK B00001100
#define MODEL_ID 3
#define MODEL_ID_SHIFT 2

char RegValue;
char Data;
int RegValue16;

void setup() {
  Serial.begin (9600);
  Serial.println("Bit Access");
  Serial.println("Bit Set");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00000010, BIN);
  Serial.print ("1: "); Serial.println(1, BIN);
  Serial.print ("1 << VCHG: "); Serial.println(1 << VCHG, BIN);
  Serial.print ("RegValue |= (1 << VCHG): "); Serial.println(RegValue |= (1 << VCHG), BIN);
  Serial.println("");

  Serial.println("Bit Clear");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00100010, BIN);
  Serial.print ("1: "); Serial.println(1, BIN);
  Serial.print ("1 << VCHG: "); Serial.println(1 << VCHG, BIN);
  Serial.print ("~(1 << VCHG): "); Serial.println(~(1 << VCHG), BIN);
  Serial.print ("RegValue &= ~(1 << VCHG): "); Serial.println(RegValue &= ~(1 << VCHG), BIN);
  Serial.println("");

  Serial.println("Bit Read");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00100010, BIN);
  Serial.print ("1: "); Serial.println(1, BIN);
  Serial.print ("1 << VCHG: "); Serial.println(1 << VCHG, BIN);
  Serial.print ("RegValue & (1 << VCHG): "); Serial.println(RegValue & (1 << VCHG), BIN);
  Serial.println("");

  Serial.println("Field Access");
  Serial.println("Field Set");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00100010, BIN);
  Serial.print ("Model ID "); Serial.println(MODEL_ID, BIN);
  Serial.print ("Model ID shift "); Serial.println(MODEL_ID_SHIFT, BIN);
  Serial.print ("MODEL_ID << MODEL_ID_SHIFT: "); Serial.println(MODEL_ID << MODEL_ID_SHIFT, BIN);
  Serial.print ("RegValue |= (MODEL_ID << MODEL_ID_SHIFT): "); Serial.println(RegValue |= (MODEL_ID << MODEL_ID_SHIFT), BIN);
  Serial.println("");

  Serial.println("Field Clear");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00101110, BIN);
  Serial.print ("MODEL_ID_MASK "); Serial.println(MODEL_ID_MASK, BIN);
  Serial.print ("~MODEL_ID_MASK: "); Serial.println(~MODEL_ID_MASK, BIN);
  Serial.print ("RegValue &= ~MODEL_ID_MASK: "); Serial.println(RegValue &= ~MODEL_ID_MASK, BIN);
  Serial.println("");

  Serial.println("Field Read");
  Serial.print ("RegValue: "); Serial.println(RegValue = B00101110, BIN);
  Serial.print ("MODEL_ID_MASK "); Serial.println(MODEL_ID_MASK, BIN);
  Serial.print ("RegValue & MODEL_ID_MASK: "); Serial.println(RegValue & MODEL_ID_MASK, BIN);
  Serial.print ("(RegValue &  MODEL_ID_MASK) >> MODEL_ID_START: "); Serial.println((RegValue &  MODEL_ID_MASK) >> MODEL_ID_SHIFT, BIN);
  Serial.println("");

  Serial.println("Byte (8 Bit) Access");
  Serial.println("Byte Merge");
  Serial.print ("RegValue: "); Serial.println(RegValue = B01000000, BIN);
  Serial.print ("Data: "); Serial.println(Data = B00110000, BIN);
  Serial.print ("RegValue |= Data: "); Serial.println(RegValue |= Data, BIN);
  Serial.println("");
 
  Serial.println("Byte Overwrite");
  Serial.print ("RegValue: "); Serial.println(RegValue = B01000000, BIN);
  Serial.print ("Data: "); Serial.println(Data = B00110000, BIN);
  Serial.print ("RegValue = Data: "); Serial.println(RegValue = Data, BIN);
  Serial.println("");

  Serial.println("Byte Clear");
  Serial.print ("RegValue: "); Serial.println(RegValue = B01000000, BIN);
  Serial.print ("Data: "); Serial.println(Data = B00000000, BIN);
  Serial.print ("RegValue = Data: "); Serial.println(RegValue = Data, BIN);
  Serial.println("");

  Serial.println("Byte Read");
  Serial.print ("RegValue: "); Serial.println(RegValue = B01000000, BIN);
  Serial.println("");
  
  Serial.println("16 Bit Access");
  Serial.println("16 Bit Read");
  Serial.print ("RegValue16: "); Serial.println(RegValue16 = 0x13F1, BIN);
  Serial.print ("RegValue16 >> 8: "); Serial.println(RegValue16 >> 8, BIN);
  Serial.print ("0xFF: "); Serial.println(0xFF, BIN);
  Serial.print ("High Byte"); Serial.print ("(RegValue16 >> 8) & 0xFF: "); Serial.println((RegValue16 >> 8) & 0xFF, BIN);
  Serial.print ("Low Byte"); Serial.print ("RegValue16 & 0xFF: "); Serial.println(RegValue16 & 0xFF, BIN);
  Serial.println("");

  char HighByte;
  char LowByte;
  Serial.println("16 Bit Write");
  Serial.print ("RegValue16: "); Serial.println(RegValue16 = 0x00, BIN);
  Serial.print ("High Byte: ");; Serial.println(HighByte = B00000100, BIN);
  Serial.print ("Low Byte: ");; Serial.println(LowByte = B00110000, BIN);
  Serial.print ("Write High Byte "); Serial.print ("RegValue16 |= HighByte << 8: "); Serial.println(RegValue16 |= HighByte << 8, BIN);
  Serial.print ("Write Low Byte "); Serial.print ("RegValue16 |= LowByte: "); Serial.println(RegValue16 |= LowByte, BIN);
  Serial.println("");

  
} 

void loop() {
  // put your main code here, to run repeatedly:

}
