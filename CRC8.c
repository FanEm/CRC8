

#include "stdafx.h"
#include <stdint.h>
#include <iostream>
#define POLYNOMIAL 0xD8 // ���������� ������� ��� ����������

uint8_t crc(uint8_t const message) // ��������� ������� � 1 ������� ���������� � �����-���� ������
{
	uint8_t remainder;	// ��������� ���������� ������� �� ������� (� ��� �� ����� ����� ���������)

	remainder = message; // ����������� ���������� ������� ���� ������� ������ (�.�. � ����� ������ ������� ��� ���)

	// ��� ������ ������� ������� ������� ������ ���������:
	for (uint8_t bit = 8; bit > 0; --bit)
	{
		// ���� ������� ��� ������� == 1,
		if (remainder & 0x80)
		{
			// �� ���������� �� ������ 2 (XOR) ������� � �������, �������� ����� �������.
			remainder ^= POLYNOMIAL;
		}

		// �������� ������� �� 1 ��� �����, ����� �������, ������� � ����� ����� ��� �������� ������.
		remainder = (remainder << 1);
	}   // ��������������, ���� ������� ��� == 0, �� ������ ����� ��������, �� ��������� XOR.

	// ���������� �������� ���� � ��� � ���� CRC.
	return (remainder);

}

void main(void)
{
	const char test[] = "123456789";
	uint8_t n = atoi(test);
	printf("The CRC of %s is %i", test, crc(n));
	getchar();

}
