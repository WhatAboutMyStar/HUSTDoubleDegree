#include <windows.h>

void main(void) 
{
	char	info[128];
	long	m_10 = 255;
	long	m_s;
	long	m_y;
	char	hex[16];
	int		pos;

	printf("计算表达式	商	余数\n", m_10, m_s, m_y);
	do {
		m_s = m_10 / 16;
		m_y = m_10 % 16;

		itoa(m_y, hex, 16);

		printf("%5d ÷ 16 = %5d	%s\n", m_10, m_s, hex);
		m_10 = m_s;
	} while(m_s != 0);
}
