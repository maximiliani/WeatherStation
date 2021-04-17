#include "handleEncryption.h" 
#include "ESP8266TrueRandom.h"

AESLib aesLib;

// AES Encryption Key
byte aes_key[] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};

// General initialization vector (you must use your own IV's in production for full security!!!)
byte aes_iv[N_BLOCK] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void aes_init() {
  Serial.println("gen_iv()");
  aesLib.gen_iv(aes_iv);
}

void getNewIV(){
  byte result[16];
  char raw[16];
  for(uint i = 0; i<16; i++) aes_iv[i] = ESP8266TrueRandom.randomByte();
  aesLib.gen_iv(aes_iv);
}

char* p_encrypt(char * msg, uint16_t msgLen, byte iv[]) {
  int cipherlength = aesLib.get_cipher_length(msgLen);
  char encrypted[cipherlength]; 
  aesLib.encrypt((byte *)msg, msgLen, encrypted, aes_key, sizeof(aes_key), iv);
  Serial.print("encrypted = "); Serial.println(encrypted);
  return encrypted;
}

char* p_decrypt(char * msg, uint16_t msgLen, byte iv[]) {
  char decrypted[msgLen];
  aesLib.decrypt((byte *)msg, msgLen, decrypted, aes_key, sizeof(aes_key), iv);
  return decrypted;
}

void setupEncryption() {
  aes_init();
  aesLib.set_paddingmode(paddingMode::CMS);

  char b64in[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  char b64out[base64_enc_len(sizeof(aes_iv))];
  base64_encode(b64out, b64in, 16);

  char b64enc[base64_enc_len(10)];
  base64_encode(b64enc, (char*) "0123456789", 10);

  char b64dec[ base64_dec_len(b64enc, sizeof(b64enc))];
  base64_decode(b64dec, b64enc, sizeof(b64enc));

}

void wait(unsigned long milliseconds) {
  unsigned long timeout = millis() + milliseconds;
  while (millis() < timeout) {
    yield();
  }
}

char* decrypt(char* text){
    Serial.println("Decrypted message: "+ (String)p_decrypt(text, (uint16_t) sizeof(text) ,aes_iv));
    return p_decrypt(text, (uint16_t) sizeof(text) ,aes_iv);
}

char* encrypt(char* text){
  getNewIV();
  Serial.println("IV: "+ (String)((char*)aes_iv));
  Serial.println("encrypted message: " + (String)(p_encrypt(text, (uint16_t) sizeof(text) ,aes_iv)));
  char *p_encrypted = p_encrypt(text, (uint16_t) sizeof(text) ,aes_iv);
  static char buf[16+sizeof(p_encrypted)];
  strcpy(buf,(char*)aes_iv);
  strcat(buf,p_encrypted);
  return buf;
}