#ifndef VIDEO_INIT_H
#define VIDEO_INIT_H
//clean up sometime
enum esc_seq {
	LF = 0x0A,
	VT = 0x0B
};
extern uint8_t bitmap;
extern enum esc_seq esc_flags[2];
void ega_init(void);
void video_init(void);

#endif