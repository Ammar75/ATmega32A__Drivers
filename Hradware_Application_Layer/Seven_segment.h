/*
 * _7_segment.h
 *
 * Created: 4/3/2025 5:24:44 PM
 *  Author: Ammar
 */ 


#ifndef Seven_segment_H_
#define Seven_segment_H_

void Seven_Segment_vintit(unsigned char port);
void Seven_segment_write_by_numb(unsigned char port , unsigned char numb);

void Seven_segment_vWrite_BCD(unsigned char port , unsigned char val , const char *nibble);

void Seven_segment_vinit_BCD(unsigned char port , const char *nibble);


#endif /* Seven_segment_H_ */