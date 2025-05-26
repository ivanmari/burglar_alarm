#ifndef ASI_H
#define ASI_H

#include "Platform.h"
#include "../SimpleQueue.h"

const unsigned char RX_BYTE_BUFFER_SZ = 16;

class ASi
{
public:

  ASi(Platform*, SimpleQueue*);

  Platform* getPlatform() const;
	
  void beepOn();
  void beepOff();

private:

  Platform* m_platform;
	SimpleQueue* m_SimpleQueue;
	char m_rx_bit_buff;
	char m_rx_bit_buff_count;
	bool m_frame_ready;
};

#endif //ASI_H
