// Osbaldo Esquivel
// 15JAN2014

#ifndef A1_H_INCLUDED
#define A1_H_INCLUDED

class theCell 
{
public:
	void initGrid();
	void showGrid();
	void copyFunc();
	void pickChoice();
	theCell(int r, int s);
private:
	int h, w;
	bool map [100][100];
	bool mapTemp [100][100];
};

#endif // A1_H_INCLUDED
