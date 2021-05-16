#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/*���. � 12 - ����������� "+" ��� ������������ ��������, �  "-" - ��� �������� ��������� ������ ������� � ������*/
class fVector {
	float* vector;
	int size;
public:
	fVector(int size);
	fVector(void);
	void output(void) const;
	void input(void);
	float get(int index, int& error);
	void set(int index, float value, int& error);
	~fVector(void);
	fVector(const fVector& v);
	fVector& operator = (fVector& v);
	fVector& operator + (fVector& v);
	fVector& operator - (fVector& v);
	fVector& operator * (float number);
	fVector& operator / (float number);
	float operator ^ (fVector& v);
};
#endif
