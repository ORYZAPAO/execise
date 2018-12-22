//
// CRC16(CCITT) 計算例
//

#include<iostream>
#include<boost/format.hpp>
using namespace std;

const uint16_t CRC16POLY=0x8408;// (反転表記)

// --------------------------------------------------
uint16_t crc16(uint16_t crc, uint8_t *buf, size_t len){
  
  crc = ~crc;

  for(size_t i=0; i<len; i++){
    crc ^= buf[i];

    for(int j=0; j<8; j++){
      if( crc & 0x1 ){ // 
        crc = (crc >> 1) ^ CRC16POLY;
      }else{           // # "0"ならシフト
        crc >>= 1;
      }
    }
    
  }
  
  return ~crc;
}



// --------------------------------------------------
// --------------------------------------------------
uint32_t crc_table[256];

void make_crc_table(void) {
    for (uint16_t i = 0; i < 256; i++) {
        uint16_t crc = i;
        for (int j = 0; j < 8; j++) {
          //c = (c & 1) ? (0xEDB88320 ^ (c >> 1)) : (c >> 1);
          crc = (crc & 1) ? (CRC16POLY ^ (crc >> 1)) : (crc >> 1);
        }
        crc_table[i] = crc;
    }
}

uint16_t crc16_2(uint8_t *buf, size_t len) {
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++) {
        crc = crc_table[(crc ^ buf[i]) & 0xFF] ^ (crc >> 8);
    }
    return crc ^ 0xFFFF;
}

// --------------------------------------------------
int main(){
  uint8_t mes[]="123456789";

  // The expected CRC for the given data
  // boost::uint16_t const  expected = 0x29B1;

  // CRC16(CCITT) 
  // "CRC16= 906E"
  cout << boost::format("CRC16= %X") % crc16(0,mes, sizeof(mes)-1) << endl;


  // CRC16(CCITT) ... テーブル計算版
  // "CRC16= 906E"
  make_crc_table();
  cout << boost::format("CRC16= %X") % crc16_2(mes,sizeof(mes)-1) << endl;

}
