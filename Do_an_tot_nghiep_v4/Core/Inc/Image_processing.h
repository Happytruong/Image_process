/*
 * Image_processing.h
 *
 *  Created on: Aug 20, 2021
 *      Author: CVH
 */

#ifndef INC_IMAGE_PROCESSING_H_
#define INC_IMAGE_PROCESSING_H_

uint16_t convRGB565(unsigned char r, unsigned char g);
RET RGB_Image(unsigned char *p_buffer, uint32_t lenght);
//void Gray_Image(unsigned char *p_buffer, uint32_t lenght);
//void Red_Image(unsigned char *p_buffer, uint32_t lenght);
//void Blue_Image(unsigned char *p_buffer, uint32_t lenght);
//void Green_Image(unsigned char *p_buffer, uint32_t lenght);
RET ColorFiler_Image(unsigned char *p_buffer, uint32_t lenght, uint16_t color);
RET Gray32_Image(unsigned char *p_buffer, uint32_t lenght);
RET Negative_Image(unsigned char *p_buffer, uint32_t lenght);
RET Bin_Image(unsigned char *p_buffer, uint32_t lenght);
RET Histogram(unsigned char *p_buffer, uint32_t lenght);

#endif /* INC_IMAGE_PROCESSING_H_ */
