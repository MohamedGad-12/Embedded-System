//Eng.Mohamed Gamal 

#ifndef I2C_H_
#define I2C_H_

void I2C_init();

void I2C_Start(void);

void I2C_Write(unsigned char  D_Byte);

void I2C_Stop();

unsigned char I2C_Read();


#endif /* I2C_H_ */