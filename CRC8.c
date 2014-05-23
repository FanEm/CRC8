

#include "stdafx.h"
#include <stdint.h>
#include <iostream>
#define POLYNOMIAL 0xD8 // Определяем полином для вычисления

uint8_t crc(uint8_t const message) // Объявляем функцию с 1 входным параметром — каким-либо числом
{
	uint8_t remainder;	// Объявляем переменную остатка от деления (в ней же потом будет результат)

	remainder = message; // присваиваем переменной остатка наши входные данные (т.к. в самом начале остатка ещё нет)

	// Для каждой битовой позиции входных данных совершаем:
	for (uint8_t bit = 8; bit > 0; --bit)
	{
		// Если старший бит остатка == 1
		if (remainder & 0x80)
		{
			// То складываем по модулю 2 (XOR) остаток и полином, получаем новый остаток.
			remainder ^= POLYNOMIAL;
		}

		// Сдвигаем остаток на 1 бит влево, таким образом, помещая в конец новый бит исходных данных.
		remainder = (remainder << 1);
	}   // Соответственно, если старший бит == 0, то просто сразу сдвигаем, не производя XOR.

	// Возвращаем значащие биты — это и есть CRC.
	return (remainder);

}

void main(void)
{
	const char test[] = "123456789";
	uint8_t n = atoi(test);
	printf("The CRC of %s is %i", test, crc(n));
	getchar();

}
