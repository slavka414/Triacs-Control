#ifndef FONT_H_
#define FONT_H_

typedef struct {
	uint8_t FontWidth;    /*!< Font width in pixels */
	uint8_t FontHeight;   /*!< Font height in pixels */
	const uint16_t *data; /*!< Pointer to data font data array */
} FontDef_t;

/**
 * @brief  7 x 10 pixels font size structure 
 */
extern FontDef_t Font_7x10;


#endif 

