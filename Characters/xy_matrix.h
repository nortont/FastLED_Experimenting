
/*Tim Norton
25/12/2022

File: xy_matrix.h

Description:
Calcultate the X Y position on a matrix for SW2812B LEDs in 8x8x5 configuration 
 */
 
 #include <Arduino.h>
 #ifndef XY_MATRIX // Add this header once only
 #define XY_MATRIX
 
 // Get matrix configuration
  
    // LED panel configuration (X x Y 8x8, 16x16 etc)
    uint8_t _panel_x_pixels=8;
    uint8_t _panel_y_pixels=8;
 
    // Number of pannels (rows,  columns)
    uint8_t _panel_rows=1;
    uint8_t _panel_columns=5;
 
    // return pixel number
    uint16_t xyPixel;
    
   // return pixel value based on xy position
    uint16_t getPosition(uint8_t xPosition, uint8_t yPosition){
            uint8_t _yValue = yPosition * _panel_x_pixels; // 0 index calculation of base Y value
            uint8_t _xPanel = xPosition / _panel_x_pixels; // whole number of panel in which led with be (if x=7, 7/8=0.875=0)
            uint8_t _panelMultiplier = _xPanel * (_panel_x_pixels * (_panel_y_pixels-1));
            uint16_t _pixelNumber =xPosition + _yValue  + _panelMultiplier;
            return _pixelNumber;
      
    }
    
    // calculate 
 #endif